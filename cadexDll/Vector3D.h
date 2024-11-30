#pragma once
#include "pch.h"
#include "framework.h"
#include "cadexDll.h"

namespace CadexShapes {

class CADEXDLL_API Vector3D
{
protected:
	float m_x;
	float m_y;
	float m_z;
public:
	Vector3D(float x = 0.f, float y = 0.f, float z = 0.f);
	Vector3D(const Vector3D&) = default;
	Vector3D(Vector3D&&) = default;
	Vector3D& operator=(const Vector3D&) = default;
	Vector3D& operator=(Vector3D&&) = default;
	~Vector3D() = default;

	inline const float& x() const { return m_x; };
	inline const float& y() const { return m_y; };
	inline const float& z() const { return m_z; };
	inline void setX(float x) { m_x = x; }
	inline void setY(float y) { m_y = y; }
	inline void setZ(float z) { m_z = z; }
};
}
