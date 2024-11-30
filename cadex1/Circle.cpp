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
	if (!ValidateNum(t))
		throw std::domain_error("Parameter t was given an invalid value");
	t = std::fmod(t, 2.f * static_cast<float>(M_PI)); // restrict t to 0 <= t < 2pi
	float x = m_center.x() + m_a * std::cos(t);
	float y = m_center.y() + m_a * std::sin(t);
	return Vector3D(x, y);
}

Vector3D Circle::derivative(float t)
{
	if (!ValidateNum(t))
		throw std::domain_error("Parameter t was given an invalid value");
	t = std::fmod(t, 2.f * static_cast<float>(M_PI)); // restrict t to 0 <= t < 2pi
	// r'(t) = (-rsint, rcost)
	float sin = std::sin(t);
	float cos = std::cos(t);
	float x = -m_a * sin;
	float y = m_a * cos;
	// Return unit tangent vector
	return Vector2D(x, y);
}



