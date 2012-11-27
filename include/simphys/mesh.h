#ifndef MESH_H
#define MESH_H

#include <memory>

#include <GL/glew.h>
#include <GL/gl.h>

namespace simphys {

  class SimObject3D;
  using std::shared_ptr;

  class Mesh {
  private:
    shared_ptr<SimObject3D> owner;
    
  public:
    /*
      Set the owner of this sprite.
    */
    void setOwner(shared_ptr<SimObject3D> newOwner);
    
    /*
      Code responsible for drawing the mesh to the screen.
    */
    void draw() const;
  };

}


#endif // MESH_H
