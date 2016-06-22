#ifndef VECTOR_2_H
#define VECTOR_2_H

#include <cmath>
#include <ostream>

#define M_PI 3.1415926535897932384626433832795

namespace SF
{
	/// <summary> Defines a two-dimensional vector </summary>
	class Vector2
	{
	public:
		/// <summary> Constructs and initializes a two-dimensional vector instance to (0.0, 0.0) </summary> 
		Vector2() : x_(0.0f), y_(0.0f) { }

		Vector2& operator=(const Vector2 &right)
		{
			if (this == &right)
				return *this;

			x_ = right.x_;
			y_ = right.y_;

			return *this;
		}

		/// <summary> Constructs and initializes a two-dimensional vector from the specified two-dimensional vector </summary> 
		Vector2(const Vector2& vector) : x_(vector.x()), y_(vector.y()) { }

		/// <summary> Constructs and initializes a two-dimensional vector from the specified xy-coordinates </summary> 
		Vector2(float x, float y) : x_(x), y_(y) { }

		/// <summary> Destroys this two-dimensional vector instance </summary> 
		~Vector2() { }

		/// <summary> Returns the x-coordinate of this two-dimensional vector </summary> 
		float x() const 
		{
			return x_;
		}

		/// <summary> Returns the y-coordinate of this two-dimensional vector </summary> 
		float y() const
		{
			return y_;
		}

		/// <summary> Computes the negation of this two-dimensional vector </summary> 
		Vector2 operator-() const
		{
			return Vector2(-x_, -y_);
		}

		/// <summary> Computes the dot product of this two-dimensional vector with the specified two-dimensional vector </summary> 
		float operator*(const Vector2& vector) const
		{
			return x_ * vector.x() + y_ * vector.y();
		}

		/// <summary> Computes the scalar multiplication of this  two-dimensional vector with the specified scalar value </summary> 
		Vector2 operator*(float s) const
		{
			return Vector2(x_ * s, y_ * s);
		}

		/// <summary> Computes the scalar division of this two-dimensional vector with the specified scalar value </summary> 
		Vector2 operator/(float s) const
		{
			const auto invS = 1.0f / s;

			return Vector2(x_ * invS, y_ * invS);
		}

		/// <summary> Computes the vector sum of this two-dimensional vector with the specified two-dimensional vector </summary> 
		Vector2 operator+(const Vector2& vector) const
		{
			return Vector2(x_ + vector.x(), y_ + vector.y());
		}

		/// <summary> Computes the vector difference of this two-dimensional vector with the specified two-dimensional vector </summary> 
		Vector2 operator-(const Vector2& vector) const
		{
			return Vector2(x_ - vector.x(), y_ - vector.y());
		}

		/// <summary> Tests this two-dimensional vector for equality with the specified two-dimensional vector </summary> 
		bool operator==(const Vector2& vector) const
		{
			return
				(fabs(x_ - vector.x()) < FLT_EPSILON)
				&& (fabs(y_ - vector.y()) < FLT_EPSILON);
		}

		/// <summary> Tests this two-dimensional vector for inequality with the specified two-dimensional vector </summary> 
		bool operator!=(const Vector2& vector) const
		{
			return
				(fabs(x_ - vector.x()) > FLT_EPSILON)
				&& (fabs(y_ - vector.y()) > FLT_EPSILON);
		}

		/// <summary> Sets the value of this two-dimensional vector to the scalar multiplication of itself with the specified scalar value </summary> 
		Vector2& operator*=(float s)
		{
			x_ *= s;
			y_ *= s;

			return *this;
		}

		/// <summary> Sets the value of this two-dimensional vector to the scalar division of itself with the specified scalar value </summary> 
		Vector2& operator/=(float s)
		{
			const auto invS = 1.0f / s;
			x_ *= invS;
			y_ *= invS;

			return *this;
		}

		/// <summary> Sets the value of this two-dimensional vector to the vector sum of itself with the specified two-dimensional vector </summary> 
		Vector2& operator+=(const Vector2& vector)
		{
			x_ += vector.x();
			y_ += vector.y();

			return *this;
		}

		/// <summary> Sets the value of this two-dimensional vector to the vector difference of itself with the specified two-dimensional vector </summary> 
		Vector2& operator-=(const Vector2& vector)
		{
			x_ -= vector.x();
			y_ -= vector.y();

			return *this;
		}

		float GetLengthSquared(void) const
		{
			return x_ * x_ + y_ * y_;
		}

		Vector2 normalized()
		{
			auto length = sqrt(pow(x_, 2) + pow(y_, 2));

			if(length < FLT_EPSILON)
				return *this;

			return Vector2(x_ / length, y_ / length);
		}

		double polarAngle() const
		{
			return atan2(y(), x());
		}

		double angleTo(Vector2 *other) const
		{
			auto angleThis = polarAngle();
			auto angleOther = other->polarAngle();

			auto diffAngle = angleOther - angleThis;
            
			if(diffAngle > M_PI)
				diffAngle -= M_PI;
			else if (diffAngle <= -M_PI)
				diffAngle += 2 * M_PI;

			return diffAngle;
		}

		Vector2 LeftNormalVector() const
		{
			return Vector2(-y(), x());
		}

	private:
		float x_;
		float y_;
	};


	/// <summary> Computes the scalar multiplication of the specified two-dimensional vector with the specified scalar value </summary> 
	inline Vector2 operator*(float s, const Vector2& vector)
	{
		return Vector2(s * vector.x(), s * vector.y());
	}

	/// <summary> Inserts the specified two-dimensional vector into the specified output stream /// </summary> 
	inline std::ostream& operator<<(std::ostream& os, const Vector2& vector)
	{
		os << "(" << vector.x() << "," << vector.y() << ")";

		return os;
	}

	/// <summary> Computes the length of a specified two-dimensional vector </summary> 
	inline float abs(const Vector2& vector)
	{
		return std::sqrt(vector * vector);
	}

	/// <summary> Computes the squared length of a specified two-dimensional vector </summary> 
	inline float absSq(const Vector2& vector)
	{
		return vector * vector;
	}

	/// <summary> Computes the determinant of a two-dimensional square matrix with rows consisting of the specified two-dimensional vectors </summary> 
	inline float det(const Vector2& vector1, const Vector2& vector2)
	{
		return vector1.x() * vector2.y() - vector1.y() * vector2.x();
	}

	/// <summary> Computes the normalization of the specified two-dimensional vector </summary> 
	inline Vector2 normalize(const Vector2& vector)
	{
		return vector / abs(vector);
	}

	inline float getLength(const Vector2& vector)
	{
		return sqrt(pow(vector.x(), 2) + pow(vector.y(), 2));
	}

	inline float getCos(Vector2 a, Vector2 b)
	{
		return a * b / (getLength(a) * getLength(b));
	}
}

#endif
