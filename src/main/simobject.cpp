#include <string>
#include <functional>

#include "simphys/simobject.h"

namespace simphys {

  SimObject::SimObject(std::string name_)
    : name{name_} {
  
    std::hash<std::string> hash_fn;
    id = hash_fn(name);
    
  }

  std::string SimObject::getName() const {
    return name;
  }

  size_t SimObject::getId() const {
    return id;
  }

  /*
    The default comparison for simulation objects is via comparison of
    their ids. This may be overridden in derived classes.
  */
  bool SimObject::operator==(const SimObject& other) const {
    return id == other.id;
  }

}
