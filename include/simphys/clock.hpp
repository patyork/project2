#include "clock.h"

template<typename Res>
simphys::Clock<Res>::Clock(Res startTime) 
  : paused{false}
  , timeScale{1.0f}
  , ticks{startTime} {  }

template<typename Res>
void simphys::Clock<Res>::setScale(float newScale) {
  timeScale = newScale;
}

template <typename Res>
float simphys::Clock<Res>::getScale() const {
  return timeScale;
}

template <typename Res>
void simphys::Clock<Res>::setPaused(bool isPaused) {
  paused = isPaused;
}

template <typename Res>
bool simphys::Clock<Res>::getPaused() const {
  return paused;
}

template <typename Res>
Res simphys::Clock<Res>::getTicks() const {
  return ticks;
}

template <typename Res>
void simphys::Clock<Res>::update(Res dt) {
  if (!paused) {
    ticks += dt * timeScale;
  }
}
