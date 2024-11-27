#pragma once
#include "Vector3D.h"
#include "Vector2D.h"
#include <array>
#include <vector>

class Ellipse
{
protected:
	float m_a;
	float m_b;
	Vector3D m_center;

	static bool ValidateNum(float n);
public:
	Ellipse(float a, float b, const Vector3D& center = Vector3D());
	/*
	* point - calculates a point of the ellipse
	* PARAMETERS:
	*	- t - parameter of parametric ellipse equation
	* RETURN:
	*	Vector3D representing the calculated point
	*/
	virtual Vector3D point(float t);
	/*
	* derivative - calculates the first derivative of the ellipse
	* PARAMETERS:
	*	- ts - std::vector of floats, for which derivative points are calculated
	* RETURN:
	*	vector of points representing derivative function of the ellipse
	*/
	virtual std::array<Vector3D, 2> derivative(const std::vector<float>& ts);
	/*
	* derivative - calculates the first derivative of the ellipse
	* PARAMETERS:
	*	- begin - begin of t range
	*	- end - end of t range
	*	- h - step of t range (t[n+1] = t[n] + h)
	* RETURN:
	*	vector of Vector3D points representing derivative function of the ellipse
	*/
	virtual std::array<Vector3D, 2> derivative(float begin, float end, float h);
	virtual std::array<Vector3D, 2> derivative(float t);
	const float& a() const { return m_a; };
	const float& b() const { return m_b; };
	const Vector3D& center() const { return m_center; };
	~Ellipse() = default;
};

