#pragma once
#include <cmath>
#include <cassert>
#include <cfloat>
#include "../MathLibrary/VMath/Vector2.h"

struct Vector4
{
	union
	{
		float v[4];
		struct { float x, y, z, w; };
		Vector2 xy;
	};
	Vector4() {}
	Vector4(float a_x, float a_y, float a_z, float a_w)
		: x(a_x), y(a_y), z(a_z), w(a_w) {}

	float magnitude() const { return sqrtf(x*x + y*y + z*z + w*w); }

	float &operator[](unsigned idx)			{ return v[idx]; }
	float  operator[](unsigned idx) const	{ return v[idx]; }
};

// Direction Between Vectors:
//(A-B).normal()
// Distance Between Vectors:
//(A-B).magnitude()

inline Vector4 operator+(const Vector4  &lhs, const Vector4 &rhs)
{
	return Vector4(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w);
}

inline Vector4 operator-(const Vector4  &lhs, const Vector4 &rhs)
{
	return Vector4(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w);
}

inline Vector4 operator/(const Vector4 &lhs, float rhs)
{
	return Vector4(lhs.x / rhs, lhs.y / rhs, lhs.z / rhs, lhs.w / rhs);
}

inline Vector4 operator*(const Vector4 &lhs, float rhs)
{
	return{ lhs.x*rhs,lhs.y*rhs,lhs.z*rhs,lhs.w*rhs };
}

// Dot production tells us how much one vector extends
// in the direction of another vector
inline float dot(const Vector4 &lhs, const Vector4 &rhs)
{
	return lhs.x * rhs.x + rhs.y * lhs.y + rhs.z*lhs.z + rhs.w*lhs.w;
}

//#define EPSILON 0.0001f

inline bool operator==(const Vector4 &lhs, const Vector4 &rhs)
{
	// return lhs.x == rhs.x && lhs.y == rhs.y;
	return
		rhs.x - FLT_EPSILON < lhs.x && lhs.x < rhs.x + FLT_EPSILON &&
		rhs.y - FLT_EPSILON < lhs.y && lhs.y < rhs.y + FLT_EPSILON &&
		rhs.z - FLT_EPSILON < lhs.z && lhs.z < rhs.z + FLT_EPSILON &&
		rhs.w - FLT_EPSILON < lhs.w && lhs.w < rhs.w + FLT_EPSILON;

	//return fabsf(rhs.x - lhs.x) < FLT_EPSILON &&
	//       fabsf(rhs.y - lhs.y) < FLT_EPSILON;
}

inline Vector4 normal(const Vector4 &a)
{
	//assert(magnitude() != 0 && "Divide by Zero");
	return a / a.magnitude();
}