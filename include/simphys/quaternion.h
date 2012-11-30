// Implementation of the Quaternion class

#include <cmath>
#include "simphys/vec3.h"
#include "simphys/mat33.h"

#ifndef QUATERNION_H
#define QUATERNION_H

namespace simphys
{
	class Quaternion{
	private:
		float w,x,y,z;
	
	public:
	     Quaternion();
  		Quaternion(const vec3 v);

  		Quaternion(const float a, const float b, const float c, const float d);

  		float getW() const;

  		float getX() const;

  		float getY() const;

  		float getZ() const;

  		void setW(float newW);

  		void setX(float newX);

  		void setY(float newY);

  		void setZ(float newZ);

  		float norm() const;

  		void normalize();

  		mat33 getMatrix() const;

  		Quaternion operator+(const Quaternion& other);

  		Quaternion operator*(const Quaternion& other);
  	};

  Quaternion operator*(const float f, const Quaternion& q);
}

#endif
