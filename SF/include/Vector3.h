#ifndef VECTOR_3_H
#define VECTOR_3_H

#include <cmath>
#include <ostream>

namespace SF
{
	/// <summary> Defines a three-dimensional vector </summary> 
	__declspec(dllexport) class Vector3
	{
	public:
		/// <summary> Constructs and initializes a three-dimensional vector instance to zero </summary> 
		Vector3()
		{
			val_[0] = 0.0f;
			val_[1] = 0.0f;
			val_[2] = 0.0f;
		}

		Vector3& operator=(const Vector3 &right)
		{
			if (this == &right)
				return *this;

			val_[0] = right.val_[0];
			val_[1] = right.val_[1];
			val_[2] = right.val_[2];

			return *this;
		}

		/// <summary> Constructs and initializes a three-dimensional vector from the specified three-dimensional vector </summary> 
		Vector3(const Vector3& vector)
		{
			val_[0] = vector[0];
			val_[1] = vector[1];
			val_[2] = vector[2];
		}

		/// <summary> Constructs and initializes a three-dimensional vector from the specified three-element array </summary> 
		explicit Vector3(const float val[3])
		{
			val_[0] = val[0];
			val_[1] = val[1];
			val_[2] = val[2];
		}

		/// <summary> Constructs and initializes a three-dimensional vector from the specified xyz-coordinates </summary> 
		Vector3(float vx, float vy, float vz)
		{
			val_[0] = vx;
			val_[1] = vy;
			val_[2] = vz;
		}

		float getLength()
		{
			return sqrt(pow(x(), 2) + pow(y(), 2) + pow(z(), 2));
		}

		/// <summary> Returns the x-coordinate of this three-dimensional vector </summary> 
		float x() const
		{
			return val_[0];
		}

		/// <summary> Returns the y-coordinate of this three-dimensional vector </summary> 
		float y() const
		{
			return val_[1];
		}

		/// <summary> Returns the z-coordinate of this three-dimensional vector </summary> 
		float z() const
		{
			return val_[2];
		}

		/// <summary> Returns the specified coordinate of this three-dimensional vector </summary> 
		float operator[](size_t i) const
		{
			return val_[i];
		}

		/// <summary> Returns a reference to the specified coordinate of this three-dimensional vector </summary> 
		float& operator[](size_t i)
		{
			return val_[i];
		}

		/// <summary> Computes the negation of this three-dimensional vector </summary> 
		Vector3 operator-() const
		{
			return Vector3(-val_[0], -val_[1], -val_[2]);
		}

		/// <summary> Computes the dot product of this three-dimensional vector with the specified three-dimensional vector </summary> 
		float operator*(const Vector3& vector) const
		{
			return val_[0] * vector[0] + val_[1] * vector[1] + val_[2] * vector[2];
		}

		/// <summary> Computes the scalar multiplication of this three-dimensional vector with the specified scalar value </summary> 
		Vector3 operator*(float scalar) const
		{
			return Vector3(val_[0] * scalar, val_[1] * scalar, val_[2] * scalar);
		}

		/// <summary> Computes the scalar division of this three-dimensional vector with the specified scalar value </summary> 
		Vector3 operator/(float scalar) const
		{
			const auto invScalar = 1.0f / scalar;

			return Vector3(val_[0] * invScalar, val_[1] * invScalar, val_[2] * invScalar);
		}

		/// <summary> Computes the vector sum of this three-dimensional vector with the specified three-dimensional vector </summary> 
		Vector3 operator+(const Vector3& vector) const
		{
			return Vector3(val_[0] + vector[0], val_[1] + vector[1], val_[2] + vector[2]);
		}

		/// <summary> Computes the vector difference of this three-dimensional vector with the specified three-dimensional vector </summary> 
		Vector3 operator-(const Vector3& vector) const
		{
			return Vector3(val_[0] - vector[0], val_[1] - vector[1], val_[2] - vector[2]);
		}

		/// <summary> Tests this three-dimensional vector for equality with the specified three-dimensional vector </summary> 
		bool operator==(const Vector3& vector) const
		{
			return 
				(fabs(val_[0] - vector[0]) < FLT_EPSILON) 
				&& (fabs(val_[1] - vector[1]) < FLT_EPSILON) 
				&& (fabs(val_[2] - vector[2]) < FLT_EPSILON);
		}

		/// <summary> Tests this three-dimensional vector for inequality with the specified three-dimensional vector </summary> 
		bool operator!=(const Vector3& vector) const
		{
			return
				(fabs(val_[0] - vector[0]) > FLT_EPSILON)
				&& (fabs(val_[1] - vector[1]) > FLT_EPSILON)
				&& (fabs(val_[2] - vector[2]) > FLT_EPSILON);
		}

		/// <summary> Sets the value of this three-dimensional vector to the scalar multiplication of itself with the specified scalar value </summary> 
		Vector3& operator*=(float scalar)
		{
			val_[0] *= scalar;
			val_[1] *= scalar;
			val_[2] *= scalar;

			return *this;
		}

		/// <summary> Sets the value of this three-dimensional vector to the scalar division of itself with the specified scalar value </summary> 
		Vector3& operator/=(float scalar)
		{
			const auto invScalar = 1.0f / scalar;

			val_[0] *= invScalar;
			val_[1] *= invScalar;
			val_[2] *= invScalar;

			return *this;
		}

		/// <summary> Sets the value of this three-dimensional vector to the vector sum of itself with the specified three-dimensional vector </summary> 
		Vector3& operator+=(const Vector3& vector)
		{
			val_[0] += vector[0];
			val_[1] += vector[1];
			val_[2] += vector[2];

			return *this;
		}

		/// <summary> Sets the value of this three-dimensional vector to the vector difference of itself with the specified three-dimensional vector </summary> 
		Vector3& operator-=(const Vector3& vector)
		{
			val_[0] -= vector[0];
			val_[1] -= vector[1];
			val_[2] -= vector[2];

			return *this;
		}

	private:
		float val_[3];
	};


	/// <summary> Computes the scalar multiplication of the specified three-dimensional vector with the specified scalar value </summary> 
	inline Vector3 operator*(float scalar, const Vector3& vector)
	{
		return Vector3(scalar * vector[0], scalar * vector[1], scalar * vector[2]);
	}

	/// <summary> Computes the cross product of the specified three-dimensional vectors </summary> 
	inline Vector3 cross(const Vector3& vector1, const Vector3& vector2)
	{
		return Vector3(
			vector1[1] * vector2[2] - vector1[2] * vector2[1], 
			vector1[2] * vector2[0] - vector1[0] * vector2[2], 
			vector1[0] * vector2[1] - vector1[1] * vector2[0]
			);
	}

	/// <summary> Inserts the specified three-dimensional vector into the specified output stream </summary> 
	inline std::ostream& operator<<(std::ostream& os, const Vector3& vector)
	{
		os << "(" << vector[0] << "," << vector[1] << "," << vector[2] << ")";

		return os;
	}

	/// <summary> Computes the length of a specified three-dimensional vector </summary> 
	inline float abs(const Vector3& vector)
	{
		return std::sqrt(vector * vector);
	}

	/// <summary> Computes the squared length of a specified three-dimensional vector </summary> 
	inline float absSq(const Vector3& vector)
	{
		return vector * vector;
	}

	/// <summary> Computes the normalization of the specified three-dimensional vector </summary> 
	inline Vector3 normalize(const Vector3& vector)
	{
		return vector / abs(vector);
	}
}

#endif
