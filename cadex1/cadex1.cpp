// cadex1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _USE_MATH_DEFINES

#include <iostream>
#include <vector>
#include <random>
#include <memory>

#include "ICurve.h"
#include "Ellipse.h"
#include "Circle.h"
#include "Helix.h"

template <
	class InputIterator, class OutputIterator,
	class UnaryOperator, class Pred
>
OutputIterator transform_if(InputIterator first1, InputIterator last1,
	OutputIterator result, UnaryOperator op, Pred pred)
{
	while (first1 != last1)
	{
		if (pred(*first1)) {
			*result = op(*first1);
			++result;
		}
		++first1;
	}
	return result;
}

float sumOfRadii(const std::vector<std::shared_ptr<CadexShapes::Circle>>& vec);

int main()
{
	std::vector<std::shared_ptr<CadexShapes::ICurve>> vec;
	std::mt19937 rd;
	std::uniform_int_distribution<> rngi;
	std::uniform_real_distribution<float> rngf(0.f, 500.f);
	//Fill the vector "in random manner" (task 2)
	size_t size = 4 + rngi(rd) % 12;
	vec.reserve(size);
	for (size_t i = 0; i < size; i++)
	{
		// ROLL THE DICE
		int n = rngi(rd) % 3;
		switch (n)
		{
		case 0: // Ellipse
		{
			vec.push_back(std::make_shared<CadexShapes::Ellipse>(rngf(rd), rngf(rd)));
			break;
		}
		case 1: // Circle
			vec.push_back(std::make_shared<CadexShapes::Circle>(rngf(rd)));
			break;
		case 2: // Helix
			vec.push_back(std::make_shared<CadexShapes::Helix>(rngf(rd), rngf(rd)));
			break;
		default:
			break;
		}
	}
	// Task 3
	const float t = static_cast<float>(M_PI_4);
	for (auto& e : vec)
	{
		CadexShapes::Vector3D pt = e->point(t);
		CadexShapes::Vector3D deriv = e->derivative(t);
		std::cout << "Curve: " << typeid(*e).name() << std::endl
			<< "Point: (" << pt.x() << "; " << pt.y() << "; " << pt.z() << ')' << std::endl
			<< "Derivative: (" << deriv.x() << "; " << deriv.y() << "; " << deriv.z() << ')' << std::endl;
	}
	//Task 4; Contravariant shallow copy
	std::vector<std::shared_ptr<CadexShapes::Circle>> vec2;
	transform_if(vec.begin(), vec.end(), std::back_inserter(vec2),
		[](auto e) { return std::dynamic_pointer_cast<CadexShapes::Circle>(e); },
		[](auto ptr) { return typeid(CadexShapes::Circle) == typeid(*ptr); });
	//Task 5
	std::sort(vec2.begin(), vec2.end(),
		[](auto a, auto b) { return a->r() < b->r(); });
	//Task 6
	float fSumOfRadii = sumOfRadii(vec2);
	std::cout << "Sum of radii in vec2: " << fSumOfRadii << std::endl;
	return 0;
}

float sumOfRadii(const std::vector<std::shared_ptr<CadexShapes::Circle>>& vec)
{
	float fSum = 0.f;
#pragma omp parallel for reduction(+:fSum)
	for (int i = 0; i < vec.size(); i++)
	{
		fSum += vec[i]->r();
	}
	return fSum;
}

