#ifndef QUATERNION_H
#define QUATERNION_H

namespace simphys {
  
  class Quaternion {
  private:
    float w;
    float x;
    float y;
    float z;

  public:
    Quaternion() 
      : w{0.0f}
    , x{0.0f}
    , y{0.0f}
    , z{0.0f} { }

    Quaternion(float w_, float x_, float y_, float z_)
      : w{w_}
    , x{x_}
    , y{y_}
    , z{z_} { }

    // TODO - OTHER MEMBER FUNCTIONS AS APPROPRIATE
  };

  // TODO - OTHER FUNCTIONS AS APPROPRIATE

} // namespace simphys


#endif // QUATERNION_H
