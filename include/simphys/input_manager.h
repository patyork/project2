#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <utility>
#include <memory>

#include <GL/glxew.h>

namespace simphys {

  class SimEngine;

  /*
    Class abstracting user input.
  */
  class InputManager {
  private:
    /*
      Input manager's copy of the display. This is initialized by the
      main simulation engine and shared with the rendering system.
    */
    Display* dpy;
    
    std::shared_ptr<SimEngine> parent;

    std::pair<int, int> mousePos;
    
  public:
    
    /*
      Set the display
    */
    void setDisplay(Display* d) {
      dpy = d;
    }
    
    /*
      Set parent engine.
    */
    void setParentEngine(std::shared_ptr<SimEngine> p);

    /*
      Perform any necessary initialization aside from getting the
      Display. Currently a no-op.
    */
    void init();
    
    /*
      Wait for and process user input.
    */
    void poll();
    
    /*
      Get the current mouse position.
    */
    std::pair<int,int> getMousePos() const {
      return mousePos;
    }
  };

}

#endif // INPUT_MANAGER_H
