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

std::array<Vector3D, 2> Ellipse::derivative(float t)
{
	if (!ValidateNum(t))
		throw std::domain_error("Parameter t was given an invalid value");
	t = std::fmod(t, 2.f * static_cast<float>(M_PI)); // restrict t to 0 <= t < 2pi
	float deriv = -m_b * math::cot(t) / m_a;
	Vector3D pt = point(t);
	// Calculate tangent line
	float y1 = pt.y() + deriv * (1.f - pt.x());
	float y2 = pt.y() + deriv * (-1.f - pt.x());
	Vector2D pt1(1.f, y1);
	Vector2D pt2(-1.f, y2);
	return std::array<Vector3D, 2> {std::move(pt1), std::move(pt2)};
}
