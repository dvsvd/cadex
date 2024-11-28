#define _USE_MATH_DEFINES
#include <stdexcept>
#include <cmath>
#include "MathFunctions.h"
#include "Helix.h"

Helix::Helix(float radius, float step, const Vector3D& center)
	: Circle(radius, center)
{
	if (step <= 0.f)
		throw std::logic_error("Invalid step value");
	m_step = step;
}

Vector3D Helix::point(float t)
{
	// Get the point's projecton to OXY plane
	Vector3D pt = Circle::point(t);
	//int n = std::floor(t / (2.f * static_cast<float>(M_PI)));
	float z = m_center.z() + m_step * t / (2.f * static_cast<float>(M_PI));
	pt.setZ(z);
	return pt;
}

std::array<Vector3D, 2> Helix::derivative(float t)
{
	if (!ValidateNum(t))
		throw std::domain_error("Parameter t was given an invalid value");
	t = std::fmod(t, 2.f * static_cast<float>(M_PI)); // restrict t to 0 <= t < 2pi
	float deriv = -math::cot(t);
	Vector3D pt = point(t);
	// Calculate tangent line
	float y1 = pt.y() + deriv * (1.f - pt.x());
	float y2 = pt.y() + deriv * (-1.f - pt.x());
	Vector2D pt1(1.f, y1);
	Vector2D pt2(-1.f, y2);
	return std::array<Vector3D, 2> {std::move(pt1), std::move(pt2)};
}
