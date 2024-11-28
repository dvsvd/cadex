#define _USE_MATH_DEFINES
#include <stdexcept>
#include <cmath>
#include "MathFunctions.h"
#include "Helix.h"

Helix::Helix(float radius, float b, const Vector3D& center)
	: Circle(radius, center)
{
	if (b <= 0.f)
		throw std::logic_error("Invalid step value");
	m_step = b * 2.f * static_cast<float>(M_PI);
	m_b = b;
}

Vector3D Helix::point(float t)
{
	// Get the point's projecton to OXY plane
	Vector3D pt = Circle::point(t);
	float z = m_center.z() + m_b * t;
	pt.setZ(z);
	return pt;
}

Vector3D Helix::derivative(float t)
{
	if (!ValidateNum(t))
		throw std::domain_error("Parameter t was given an invalid value");
	t = std::fmod(t, 2.f * static_cast<float>(M_PI)); // restrict t to 0 <= t < 2pi
	// r'(t) = (-rsint, rcost, b)
	float sin = std::sin(t);
	float cos = std::cos(t);
	float x = -m_a * sin;
	float y = m_a * cos;
	float z = m_b;
	float norm = std::sqrt(m_a * m_a * sin * sin + m_a * m_a * cos * cos + m_b * m_b);
	// Return unit tangent vector
	return Vector3D(x / norm, y / norm, z / norm);
}
