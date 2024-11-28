#pragma once
#include "Vector3D.h"
#include "Vector2D.h"

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
	*	- t - parameter of parametric ellipse equation
		representing the point of the ellipse
	* RETURN:
	* Unit tangent vector at the point of parameter t
	*/
	virtual Vector3D derivative(float t);
	const float& a() const { return m_a; };
	const float& b() const { return m_b; };
	const Vector3D& center() const { return m_center; };
	~Ellipse() = default;
};

