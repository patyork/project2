#include "simphys/simobject3D.h"
#include "simphys/mesh.h"
#include "simphys/particle.h"

#include <iostream>
#include <string>

#include <GL/gl.h>

namespace simphys {

  void Mesh::setOwner(shared_ptr<SimObject3D> newOwner) {
    owner = newOwner;
  }
  
  void Mesh::draw() const {
    
    // TODO change the pointer to point to a rigid body.
    shared_ptr<Particle> p = owner->getState();
    auto pos = p->getPosition();
    float x = pos.getX();
    float y = pos.getY();
    float z = pos.getZ();

    /*
      TODO 

      Since we're using old-fashioned OpenGL, we'll use glRotate
      below. This function expects an angle and an axis. You should
      store the orientation of your rigid body as a quaternion (for
      the reasons we discussed in class), which means at this point
      you'll need to convert from a quaternion representation to an
      axis-angle representation. This is in the slides and was a
      question on exam 2.
    */
    float angle = 0.0f;
    float x_axis = 0.0f;
    float y_axis = 0.0f;
    float z_axis = 0.0f;

    // You can ignore these lines - they set up drawing a sphere.
    GLUquadricObj *obj = gluNewQuadric();
    gluQuadricNormals(obj, GLU_SMOOTH);

    // save state
    glPushMatrix();

    /*
      Translate the sphere to its current (x,y,z) coordinates
     */
    glTranslatef(x,y,z);

    /* 
       TODO

       At some point you'll need to apply a rotation, and you'll
       probably want to put the call that does that after the call to
       glTranslatef. Here's the call:

       glRotatef(angle, x_axis, y_axis, z_axis);

       A few points to note:

       0. Play around with this, and make sure that you're rotating
       about the object's center of mass rather than the origin of the
       global coordinate system. If you find that the object swings
       around rather than rotating in place, you'll need to fix
       that. The method for doing so is in the slides, but if you
       can't find it, ask on Piazza.

       1. When you have a sequence of transformations in OpenGL, the
       last one that you write before drawing is the first one that's
       applied. So here, when we call translate followed by rotate,
       the net effect is that we rotate first then translate. You'll
       learn why this is the case if you take graphics. 
    */

    /*
      Draw a sphere. The second argument is a radius, and the third
      and fourth arguments are the number of subdivisions along
      latitude and longitude.
     */
    gluSphere(obj, 1.001f, 8, 8);

    // restore state
    glPopMatrix();
  }
}
