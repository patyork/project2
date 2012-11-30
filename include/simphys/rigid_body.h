#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include <chrono>

#include "vec3.h"
#include "quaternion.h"

typedef std::chrono::duration<float, std::ratio<1,1> > fseconds;

namespace simphys {
  
  /*
    A rigid body for a physics simulation.
  */
  class RigidBody {
  private:

    // current position
    vec3 pos;

    // current velocity
    vec3 vel;

    // current acceleration
    vec3 acc;

    // accumulated force for the current time step
    vec3 accumulatedForces;
    
    // angular acceleration
    vec3 angacc;
    
    // angular velocity
    vec3 angvel;
    
    // angular orientation
    Quaternion orientation;
    
    // Inverse Inertia Tensor (1 / Ix, 1 / Iy, 1 / Iz)
    vec3 inverseInertia;
    
    // accumulated torque
    vec3 accumulatedTorque;

    // Damping parameter 
    float damping;

    // 1.0f / mass
    float invMass;
    
    // Radius of the particle
    float radius;
    

  public:

    RigidBody();
    
    // setters
    void setPosition(const vec3& newPos);
    void setVelocity(const vec3& newVel);
    void setAcceleration(const vec3& newAcc);
    void setAngularAcceleration(const vec3& newAngAcc);
    void setAngularVelocity(const vec3& newAngVel);
    void setOrientation(const Quaternion& newOrientation);
    void setInverseInertia(const vec3& newInvInertia);
    void setDamping(float d);
    void setMass(float m);
    void setRadius(float r);

    // getters
    vec3 getPosition() const;
    vec3 getVelocity() const;
    vec3 getAcceleration() const;
    vec3 getAngularAcceleration() const;
    vec3 getAngularVelocity() const;
    Quaternion getOrientation() const;
    vec3 getInverseInertia() const;
    float getDamping() const;
    float getMass() const;
    float getRadius() const;

    // Update the position, velocity, angular orientation and angular velocity of this particle.
    void integrate(fseconds duration);
    
    // clear the force accumulation vector
    void clearForces();
    
    // clear the torque accumulator
    void clearTorques();

    // Apply a force to this particle
    void applyForce(const vec3& force);
    
    // Apply a torque at a point
    void applyTorque(const vec3& force, const vec3& point);

  };

}

#endif // RIGID_BODY_H
