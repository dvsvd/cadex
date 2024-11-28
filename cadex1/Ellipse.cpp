#define _USE_MATH_DEFINES
#include <stdexcept>
#include <cmath>
#include "Ellipse.h"
#include "MathFunctions.h"

Ellipse::Ellipse(float a, float b, const Vector3D& center)
{
	if (a <= 0.f || b <= 0.f)
		throw std::logic_error("Invalid radius value");
	m_a = a;
	m_b = b;
	m_center = center;
}

bool Ellipse::ValidateNum(float n)
{
	return !(isnan(n) || isinf(n));
}

Vector3D Ellipse::point(float t)
{
	if (!ValidateNum(t))
		throw std::domain_error("Parameter t was given an invalid value");
	t = std::fmod(t, 2.f * static_cast<float>(M_PI) + FLT_MIN); // restrict t to 0 <= t <= 2pi
	float x = m_center.x() + m_a * std::cos(t);
	float y = m_center.y() + m_b * std::sin(t);
	return Vector3D(x, y);
}

Vector3D Ellipse::derivative(float t)
{
	if (!ValidateNum(t))
		throw std::domain_error("Parameter t was given an invalid value");
	t = std::fmod(t, 2.f * static_cast<float>(M_PI)); // restrict t to 0 <= t < 2pi
	// r'(t) = (-asint, bcost)
	float sin = std::sin(t);
	float cos = std::cos(t);
	float x = -m_a * sin;
	float y = m_b * cos;
	float norm = std::sqrt(m_a * m_a * sin * sin + m_a * m_a * cos * cos);
	// Return unit tangent vector
	return Vector2D(x / norm, y / norm);
}
