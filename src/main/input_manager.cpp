#include "simphys/input_manager.h"
#include "simphys/sim_engine.h"

#include <GL/glxew.h>
#include <iostream>
#include <utility>

namespace simphys {

  void InputManager::init() {
    
  }

  void InputManager::setParentEngine(std::shared_ptr<SimEngine> p) {
    parent = p;
  }

 
  void InputManager::poll() {
    XEvent newEvent;

    /*
      If there aren't any X events pending, return.
    */
    if (XPending(dpy) == 0) {
      return;
    }

    XNextEvent(dpy, &newEvent);
    
    switch(newEvent.type) {
    case KeyPress:
      if (XLookupKeysym(&newEvent.xkey, 0) == XK_q) {
	std::cout << "Q pressed. Quitting." << std::endl;
	exit(0);
      }

      if (XLookupKeysym(&newEvent.xkey, 0) == XK_p) {
	std::cout << "P pressed." << std::endl;
	auto clock = parent->clock();
	if (clock->getPaused()) {
	  std::cout << "Setting paused to false." << std::endl;
	  clock->setPaused(false);	  
	} else {
	  std::cout << "Setting paused to true." << std::endl;
	  clock->setPaused(true);
	}
      }
      
      if (XLookupKeysym(&newEvent.xkey, 0) == XK_Return) {
	std::cout << "You hit enter!" << std::endl;
      }
      
      if (XLookupKeysym(&newEvent.xkey, 0) == XK_space) {
	std::cout << "You hit space!" << std::endl;
      }
      
      if (XLookupKeysym(&newEvent.xkey, 0) == XK_Up) {
	std::cout << "You hit up!" << std::endl;
      }
      
      if (XLookupKeysym(&newEvent.xkey, 0) == XK_1) {
	std::cout << "You hit 1!" << std::endl;
      }
      
      if (XLookupKeysym(&newEvent.xkey, 0) == XK_BackSpace) {
	std::cout << "You hit backspace!" << std::endl;
      }
      
      break;
      
    case MotionNotify:
      mousePos = std::make_pair((newEvent.xmotion).x, (newEvent.xmotion).y);
      break; 
    } 
  }
}
