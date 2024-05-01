#pragma once
#include <iostream>

class Vector2f
{
public:
	Vector2f();
	Vector2f(float x, float y);
	void print();

	float getX() const { return m_x; }
	float getY() const { return m_y; }

	void setX(float x);
	void setY(float y);

	void setPos(float x, float y)
	{
		this->m_x = x;
		this->m_y = y;
	}

	float length2()
	{
		return m_x * m_x + m_y * m_y;
	}

	float length()
	{
		return (float)sqrt(length2());
	}
	// Vector2f operator+(const Vector2f &v2) const;
	Vector2f operator=(const Vector2f& v2);
	Vector2f& operator+=(const Vector2f& v2);
	Vector2f operator-(const Vector2f& v2)
	{
		return Vector2f(m_x - v2.getX(), m_y - v2.getY());
	}
	Vector2f operator*(float k)
	{
		return Vector2f(m_x * k, m_y * k);
	}	
	Vector2f normalize()
	{
		return *this * (1 / length());
	}
	bool operator==(const Vector2f& v2);
	bool operator!=(const Vector2f& v2);

	// Vector2f operator*(float scalar);

private:
	float m_x;
	float m_y;
};