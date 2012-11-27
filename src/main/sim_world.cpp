#include <memory>
#include <vector>

#include "simphys/sim_world.h"
#include "simphys/simobject3D.h"

namespace simphys {

  SimWorld::SimWorld()
    : objects{} { }

  void SimWorld::add(std::shared_ptr<SimObject3D> obj) {
    objects.push_back(obj);
  }

  std::vector<shared_ptr<SimObject3D> > SimWorld::getObjects() const {
    return objects;
  }

}
