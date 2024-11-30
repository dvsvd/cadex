#pragma once
#include "pch.h"
#include "framework.h"
#include "cadexDll.h"
#include "Vector3D.h"

namespace CadexShapes {

class CADEXDLL_API ICurve {
public:
	virtual Vector3D point(float t) = 0;
	virtual Vector3D derivative(float t) = 0;
	virtual ~ICurve() {};
};
}