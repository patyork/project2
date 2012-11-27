#ifndef RENDER_ENGINE_H
#define RENDER_ENGINE_H

#include <memory>

#include <X11/Xlib.h>
#include <GL/glew.h>
#include <GL/glxew.h>

namespace simphys {
  
  class SimWorld;
  using std::shared_ptr;
  
  class RenderEngine {
  private:
    GLXContext ctx;
    // we use a raw pointer here for compatibility with Xlib.
    Display* dpy;
    Window w;
    int windowHeight;
    int windowWidth;
    shared_ptr<SimWorld> sw;

    GLuint texture;
    
    void setupWindow();
    void setupGL();
    
  public:
    /*
      Initialize window dimensions.
    */
    RenderEngine();
    
    /*
      Initialize the X window and the OpenGL context.
    */
    void init();
    
    /*
      Set the display of the rendering engine.
    */
    void setDisplay(Display* d);
    
    /*
      Draw the world.
    */
    void draw() const;
    
    /*
      Set the simulation world.
    */
    void setSimWorld(shared_ptr<SimWorld> simworld);
    shared_ptr<SimWorld> getSimWorld() const;
    
  };
}

#endif // RENDER_ENGINE_H
