#ifndef SIM_OBJECT_3D_H
#define SIM_OBJECT_3D_H

#include <memory>

#include "particle.h"
#include "mesh.h"
#include "simobject.h"

namespace simphys {

  using std::shared_ptr;

  // forward declarations
  class Mesh;
  class Particle;
  class Quaternion;

  class SimObject3D : public SimObject {
  private:
    // coordinates of centroid.
    shared_ptr<Particle> state;
    
    // quaternion representation of orientation
    shared_ptr<Quaternion> orientation;

    // visual representation.
    shared_ptr<Mesh> mesh;

  public:

    SimObject3D(Particle p, Mesh s);

    /*
      Return a shared pointer to the physics state of this object.
    */
    shared_ptr<Particle> getState() const;
    
    /*
      Set the sprite for this object.
    */
    void setMesh(shared_ptr<Mesh> spr_ptr);

    /*
      Return a shared pointer to this sprite.
    */
    shared_ptr<Mesh> getMesh() const;

  };

}

#endif // SIM_OBJECT_3D_H
