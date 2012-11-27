#ifndef CLOCK_H
#define CLOCK_H

#include <chrono>

/*
  A class representing a clock, based on code from Game Engine
  Architecture.

  The clock doesn't actually measure real time. Instead, it receives
  measurements of real time and increments an internal counter of
  "ticks" based on its input. This allows us to decouple "real" time
  from the time measured by our clocks.
*/

namespace simphys {
  
  template<typename Res>
  class Clock {
  private:

    // Is this clock updating?
    bool paused;
    
    // We can scale time to speed it up or slow it down.
    float timeScale;
    
    // The number of clock ticks since creation.
    Res ticks;
    
  public:

    /*
      Constructor. We pass in a starting time, which may default to
      zero.
    */
    Clock(Res startTime);

    // getter and setter for timeScale
    void setScale(float newScale);
    float getScale() const;

    // getter and setter for paused state
    void setPaused(bool isPaused);
    bool getPaused() const;
    
    /*
      return the number of ticks since creation. Notice that updates
      will be conducted in terms of the tick count using this setup.
    */
    Res getTicks() const;

    /*
      Update the current clock's tick count based on a given interval
      of real time and the clock's time scale and pause state.
      
      Typically, this interval will be computed using a clock that
      measures time in the "real" world.
    */
    void update(Res dt);

  };
  
}

#include "clock.hpp"

#endif // CLOCK_H
