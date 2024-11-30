#pragma once
#include "pch.h"
#include "framework.h"
#include "cadexDll.h"
#include "Vector3D.h"

namespace CadexShapes {

class CADEXDLL_API Vector2D : public Vector3D
{
private:
	using Vector3D::setZ;
	using Vector3D::z;
public:
	Vector2D(float x = 0.f, float y = 0.f);
};
}
