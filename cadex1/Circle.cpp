#define _USE_MATH_DEFINES
#include <stdexcept>
#include <cmath>
#include "MathFunctions.h"

#include "Circle.h"

Circle::Circle(float radius, const Vector3D& center)
	: Ellipse(radius, radius, center)
{
}

Vector3D Circle::point(float t)
{
	t = std::fmod(t, 2.f * static_cast<float>(M_PI)); // restrict t to 0 <= t < 2pi
	float x = m_center.x() + m_a * std::cos(t);
	float y = m_center.y() + m_a * std::sin(t);
	return Vector3D(x, y);
}

std::array<Vector3D, 2> Circle::derivative(float t)
{
	if (!ValidateNum(t))
		throw std::domain_error("Parameter t was given an invalid value");
	t = std::fmod(t, 2.f * static_cast<float>(M_PI)); // restrict t to 0 <= t < 2pi
	float deriv = -math::cot(t);
	Vector3D pt = point(t);
	// Calculate tangent line
	float y1 = pt.y() + deriv * (1.f - pt.x());
	float y2 = pt.y() + deriv * (-1.f - pt.x());
	Vector2D pt1 = (1.f, y1);
	Vector2D pt2 = (-1.f, y2);
	return std::array<Vector3D, 2> {std::move(pt1), std::move(pt2)};
}



