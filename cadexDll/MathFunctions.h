#pragma once
#define _USE_MATH_DEFINES

#include <functional>
#include <iostream>
#include <limits>
#include <cmath>

namespace math {

// From https://stackoverflow.com/a/1559956/27575278

template <class T, class R = T>
using RealFunc = std::function<R(T)>;
template <class T, class R = T>
using RealFuncDerivative = std::function<R(std::function<R(T)>, T)>;

template <class T, class R = T>
R derivative(RealFunc<T,R> f, T x) {
    T h = sqrt(std::numeric_limits<T>::epsilon());
    return (f(x + h) - f(x - h)) / (static_cast<T>(2.0) * h);
}

template <class T>
bool checkRelativelyEqual(T a, T b, T relativeEpsilon)
{
    T diff = fabs(a - b);
    a = fabs(a);
    b = fabs(b);
    T largest = fmax(a, b);

    return diff <= largest * relativeEpsilon;
}

template <class T, class R = T>
R cot(T x)
{
    R res;
    if (math::checkRelativelyEqual(x, static_cast<T>(M_PI_2),
        std::numeric_limits<float>::epsilon()) ||
        math::checkRelativelyEqual(x, static_cast<T>(3. * M_PI_2),
            std::numeric_limits<float>::epsilon()))
    {
        return static_cast<R>(0.);
    }
    return static_cast<R>(1.) / std::tan(x);
}
}
