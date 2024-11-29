#pragma once
#include "Circle.h"
class Helix : public Circle
{
protected:
	float m_step;
public:
	using Ellipse::b;
	Helix(float radius, float b, const Vector3D& center = Vector3D());
	~Helix() = default;
	/*
	* point - calculates a point of the helix
	* PARAMETERS:
	*	- t - parameter of parametric helix equation
	* RETURN:
	*	Vector3D representing the calculated point
	*/
	Vector3D point(float t) override;
	/*
	* derivative - calculates the first derivative of the helix
	* PARAMETERS:
	*	- t - parameter of parametric helix equation
		representing the point of the helix
	* RETURN:
	* Unit tangent vector at the point of parameter t
	*/
	Vector3D derivative(float t) override;
	const float& step() const { return m_step; };
};

