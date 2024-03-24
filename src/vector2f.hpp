#pragma once

#include <iostream>

class Vector2f
{
public:
    Vector2f();
    Vector2f(float x, float y);
    void print();

    float getX() { return m_x; }
    float getY() { return m_y; }

    void setX(float x);
    void setY(float y);

    float length();
    // Vector2f operator+(const Vector2f &v2) const;
    friend Vector2f &operator+=(Vector2f &v1, const Vector2f &v2);
    // Vector2f operator*(float scalar);

private:
    float m_x;
    float m_y;
};