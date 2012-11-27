#ifndef SIM_WORLD_H
#define SIM_WORLD_H

#include "simphys/simobject3D.h"

#include <memory>
#include <vector>

namespace simphys {

  using std::shared_ptr;
  using simphys::SimObject3D;

  /*
    A container for simulation objects.
    \author Richard Kelley.
  */
  class SimWorld {
  private:
    std::vector<shared_ptr<SimObject3D> > objects;

  public:
    SimWorld();

    /*
      Add an object to the world.
    */
    void add(shared_ptr<SimObject3D> obj);
    
    /*
      Get the objects in the world.
    */
    std::vector<shared_ptr<SimObject3D> > getObjects() const;

  };

}

#endif // SIM_WORLD_H
