// Implementation of the Quaternion class

#include "simphys/quaternion.h"

namespace simphys
{
  Quaternion::Quaternion()
  {
    w = 1.0f;
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
  }
  
  Quaternion::Quaternion(const vec3 v)
  {
    w = 0;
    x = v.getX();
    y = v.getY();
    z = v.getZ();
  }

  Quaternion::Quaternion(const float a, const float b, const float c,
      const float d)
    : w(a), x(b), y(c), z(d)
  {
    // The quaternion's only data are these four floats
  }

  float Quaternion::getW() const
  {
    return w;
  }

  float Quaternion::getX() const
  {
    return x;
  }

  float Quaternion::getY() const
  {
    return y;
  }

  float Quaternion::getZ() const
  {
    return z;
  }

  void Quaternion::setW(float newW)
  {
    w = newW;
  }

  void Quaternion::setX(float newX)
  {
    x = newX;
  }

  void Quaternion::setY(float newY)
  {
    y = newY;
  }

  void Quaternion::setZ(float newZ)
  {
    z = newZ;
  }

  float Quaternion::norm() const
  {
    // Norm of a quaternion is similar to norm of a vector
    return sqrt(w * w + x * x + y * y + z * z);
  }

  void Quaternion::normalize()
  {
    // Get the norm of the vector
    float n = norm();

    // Divide each element by the norm
    w = w / n;
    x = x / n;
    y = y / n;
    z = z / n;
  }

  mat33 Quaternion::getMatrix() const
  {
    // Copy the calling quaternion
    Quaternion q(w, x, y, z);

    // Normalize it (we want a rotation matrix)
    q.normalize();

    // Compute the matrix elements
    float a = 2 * (q.w * q.w + q.x * q.x) - 1;
    float b = 2 * (q.x * q.y - q.w * q.z);
    float c = 2 * (q.x * q.z + q.w * q.y);
    float d = 2 * (q.x * q.y + q.w * q.z);
    float e = 2 * (q.w * q.w + q.y * q.y) - 1;
    float f = 2 * (q.y * q.z - q.w * q.x);
    float g = 2 * (q.x * q.z - q.w * q.y);
    float h = 2 * (q.y * q.z + q.w * q.x);
    float i = 2 * (q.w * q.w + q.z * q.z) - 1;
    return mat33{a, b, c, d, e, f, g, h, i};
  }

  Quaternion Quaternion::operator+(const Quaternion& other)
  {
    // Simply add componentwise
    return Quaternion(w + other.w, x + other.x, y + other.y, z + other.z);
  }

  Quaternion Quaternion::operator*(const Quaternion& other)
  {
    float newW = w * other.w - x * other.x - y * other.y - z * other.z;
    float newX = w * other.x + x * other.w + y * other.z - z * other.y;
    float newY = w * other.y - x * other.z + y * other.w + z * other.x;
    float newZ = w * other.z + x * other.y - y * other.x + z * other.w;
    return Quaternion(newW, newX, newY, newZ);
  }

  Quaternion operator*(const float f, const Quaternion& q)
  {
    return Quaternion(f * q.getW(), f * q.getX(), f * q.getY(), f * q.getZ());
  }
}
