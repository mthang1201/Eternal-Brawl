#include "vector2f.hpp"

Vector2f::Vector2f() : m_x(0.0f), m_y(0.0f) {}

Vector2f::Vector2f(float x, float y) : m_x(x), m_y(y) {}

void Vector2f::print()
{
    std::cout << m_x << ", " << m_y << std::endl;
}

void Vector2f::setX(float x) { m_x = x; }
void Vector2f::setY(float y) { m_y = y; }

Vector2f &operator+=(Vector2f &v1, const Vector2f &v2)
{
    v1.m_x += v2.m_x;
    v1.m_y += v2.m_y;
    return v1;
}
