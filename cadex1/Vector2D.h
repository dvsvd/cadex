#pragma once
#include "Vector3D.h"

class Vector2D : public Vector3D
{
private:
	using Vector3D::setZ;
	using Vector3D::z;
public:
	Vector2D(float x = 0.f, float y = 0.f);
};

