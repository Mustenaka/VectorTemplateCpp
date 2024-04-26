# Vector2

This is a lightweight C++ header-only library providing a simple implementation of 2D vectors and common vector operations.

## Features

- **Vector Operations:** Supports basic vector operations such as addition, subtraction, scalar multiplication, division, dot product, cross product, reflection, magnitude, squared magnitude, distance calculation, linear interpolation, normalization, and formatting to string.
- **Efficient:** Provides optimized implementations for common vector operations to ensure better performance, especially in high-frequency usage scenarios.
- **Header-only:** All functionality is contained within a single header file for easy integration into existing projects without the need for additional compilation steps.

## Usage

To use `Vector2` in your project, simply include the `Vector2.h` header file and start using the provided functionality.

Example:

```cpp
#include "Vector2.h"

int main() {
    Vector2 vec1(1.0f, 2.0f);
    Vector2 vec2(3.0f, 4.0f);

    Vector2 sum = vec1 + vec2;
    Vector2 difference = vec1 - vec2;
    float dotProduct = vec1.Dot(vec2);
    // Perform other operations...

    return 0;
}
```

Implemented Methods
- float Dot(const Vector2 &other) const: Calculates the dot product of two vectors.
- float Cross(const Vector2 &other) const: Calculates the cross product of two vectors (Note: not meaningful for 2D vectors).
- Vector2 operator+(const Vector2 &other) const: Overloads the addition operator to perform vector addition.
- Vector2 operator-(const Vector2 &other) const: Overloads the subtraction operator to perform vector subtraction.
- Vector2 operator*(float scalar) const: Overloads the multiplication operator to perform scalar-vector multiplication.
- Vector2 operator/(float scalar) const: Overloads the division operator to perform vector division by a scalar.
- Vector2 Reflect(const Vector2 &normal) const: Calculates the reflection of a vector given a surface normal.
- float magnitude() const: Calculates the magnitude (length) of the vector.
- float sqrMagnitude() const: Calculates the squared magnitude of the vector (more efficient for frequent use).
- static float Distance(const Vector2 &a, const Vector2 &b): Calculates the distance between two vectors.
- static Vector2 Lerp(const Vector2 &a, const Vector2 &b, float t): Performs linear interpolation between two vectors.
- Vector2 normalize(const Vector2 &v): Normalizes the vector to unit length.
- std::string toString() const: Formats the vector as a string.
