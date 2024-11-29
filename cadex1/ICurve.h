#pragma once
#include "Vector3D.h"

class ICurve {
public:
	virtual Vector3D point(float t) = 0;
	virtual Vector3D derivative(float t) = 0;
	virtual ~ICurve() {};
};