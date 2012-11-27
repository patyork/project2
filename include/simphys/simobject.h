#ifndef SIMOBJECT_H
#define SIMOBJECT_H

#include <string>
#include <chrono>

namespace simphys {
  
  /*
    An object in the simulation. This class may be extended to object
    more specific state/behavior.

    \author Richard Kelley
   */
  class SimObject {
  private:
    size_t id;
    std::string name;

  public:
    SimObject(std::string name_);

    // getters
    std::string getName() const;
    size_t getId() const;

    // comparison
    virtual bool operator==(const SimObject& other) const;
  };

}

#endif // SIMOBJECT_H
