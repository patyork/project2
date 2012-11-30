/*
    A rigid body for a physics simulation.
*/

#include "simphys/rigid_body.h"

typedef std::chrono::duration<float, std::ratio<1,1> > fseconds;

namespace simphys {

  

/*
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
    
    // Current Color of the particle
    Color rgb;

    // Damping parameter 
    float damping;

    // 1.0f / mass
    float invMass;
    
    // Radius of the particle
    float radius;*/
    


    RigidBody::RigidBody()
      : pos{0.0f, 0.0f, 0.0f}
      , vel{0.0f, 0.0f, 0.0f}
      , acc{0.0f, 0.0f, 0.0f}
      , accumulatedForces{0.0f, 0.0f, 0.0f}
      , angacc{0.0f, 0.0f, 0.0f}
      , angvel{0.0f, 0.0f, 0.0f}
      , orientation{1.0f, 0.0f, 0.0f, 0.0f}
      , inverseInertia{1.0f, 1.0f, 1.0f}
      , accumulatedTorque{0.0f, 0.0f, 0.0f}
      , damping{1.0f}
      , invMass{1.0f}
      , radius{40.0f}
    {}
      
    // setters
    void RigidBody::setPosition(const vec3& newPos)
    {
      pos = newPos;
    }
    
    void RigidBody::setVelocity(const vec3& newVel)
    {
      vel = newVel;
    }
    
    void RigidBody::setAcceleration(const vec3& newAcc)
    {
      acc = newAcc;
    }
    
    void RigidBody::setAngularAcceleration(const vec3& newAngAcc)
    {
      angacc = newAngAcc;
    }
    
    void RigidBody::setAngularVelocity(const vec3& newAngVel)
    {
      angvel = newAngVel;
    }
    
    void RigidBody::setOrientation(const Quaternion& newOrientation)
    {
      float w = newOrientation.getW();
      float x = newOrientation.getX();
      float y = newOrientation.getY();
      float z = newOrientation.getZ();
      
      orientation = Quaternion(w, x, y, z);
    }
    
    void RigidBody::setInverseInertia(const vec3& newInvInertia)
    {
      inverseInertia = newInvInertia;
    }
    
    void RigidBody::setDamping(float d)
    {
      damping = d;
    }
    
    void RigidBody::setMass(float m)
    {
      if(m != 0)
        invMass = 1 / m;
      // We cannot divide by 0, and infinity is hardly a useful thing to have
      // Instead, let's take m = 0 to mean that the user wanted 0 INVERSE mass
      else
        invMass = 0;
    }
    
    void RigidBody::setRadius(float r)
    {
      radius = r;
    }

    // getters
    vec3 RigidBody::getPosition() const
    {
      return pos;
    }
    
    vec3 RigidBody::getVelocity() const
    {
      return vel;
    }
    
    vec3 RigidBody::getAcceleration() const
    {
      return acc;
    }
    
    vec3 RigidBody::getAngularAcceleration() const
    {
      return angacc;
    }
    
    vec3 RigidBody::getAngularVelocity() const
    {
      return angvel;
    }
    
    Quaternion RigidBody::getOrientation() const
    {
      return orientation;
    }
    
    vec3 RigidBody::getInverseInertia() const
    {
      return inverseInertia;
    }
    
    float RigidBody::getDamping() const
    {
      return damping;
    }
    
    float RigidBody::getMass() const
    {
      if(invMass != 0)
        return 1 / invMass;
      // Again, we cannot divide by 0, so let's return what the user likely used to set the inverse mass to 0
      else
        return 0;
    }
    
    float RigidBody::getRadius() const
    {
      return radius;
    }

    // Update the position, velocity, angular orientation and angular velocity of this particle.
    void RigidBody::integrate(fseconds duration)
    {
    // don't move objects that have "infinite mass."
    if (invMass <= 0.0f) {
      return;
    }

    // update position using Euler integration
    pos = pos + duration.count() * vel;

    vec3 resultantAcc = acc;
    resultantAcc = resultantAcc + (invMass * accumulatedForces);

    // update velocity using Euler integration
    vel = vel + duration.count() * resultantAcc;

    // incorporate damping
    vel = vel * damping;

    clearForces();
    
    // Update angular position and velocity
    Quaternion qAngVel = Quaternion(angvel);
    orientation = orientation + duration.count() / 2 * qAngVel * orientation;
    
    vec3 resAngAcc = angacc;
    
    // Compute the product of the inverse inertia tensor and the torque accumulator
    float alphaX = inverseInertia.getX() * accumulatedTorque.getX();
    float alphaY = inverseInertia.getY() * accumulatedTorque.getY();
    float alphaZ = inverseInertia.getZ() * accumulatedTorque.getZ();

    resAngAcc = resAngAcc + vec3{alphaX, alphaY, alphaZ};
    
    angvel = angvel + duration.count() * resAngAcc;
    angvel = angvel * damping;
    
    clearTorques();
    }
    
    // clear the force accumulation vector
    void RigidBody::clearForces()
    {
      accumulatedForces = vec3{0.0f, 0.0f, 0.0f};
    }
    
    // clear the torque accumulator
    void RigidBody::clearTorques()
    {
      accumulatedTorque = vec3{0.0f, 0.0f, 0.0f};
    }

    // Apply a force to this particle
    void RigidBody::applyForce(const vec3& force)
    {
      accumulatedForces = accumulatedForces + force;
    }
    
    // Apply a torque at a point
    void RigidBody::applyTorque(const vec3& force, const vec3& point)
    {
      // Compute the torque
      vec3 torque = (point - pos).crossProduct(force);
      
      // Apply the torque
      accumulatedTorque = accumulatedTorque + torque;
    }
}
