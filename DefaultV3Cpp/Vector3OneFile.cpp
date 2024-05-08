#include <math.h>
#include <iostream>

struct Vector3
{
    float x, y, z;

    Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

    // 计算向量的点积
    float Dot(const Vector3 &other) const
    {
        return x * other.x + y * other.y + z * other.z;
    }

    // 计算向量的叉乘
    Vector3 Cross(const Vector3 &other) const
    {
        return Vector3(y * other.z - z * other.y,
                       z * other.x - x * other.z,
                       x * other.y - y * other.x);
    }

    // 重载加法运算符
    Vector3 operator+(const Vector3 &other) const
    {
        return Vector3(x + other.x, y + other.y, z + other.z);
    }

    // 重载减法运算符
    Vector3 operator-(const Vector3 &other) const
    {
        return Vector3(x - other.x, y - other.y, z - other.z);
    }

    // 重载乘法运算符（向量与标量相乘）
    Vector3 operator*(float scalar) const
    {
        return Vector3(x * scalar, y * scalar, z * scalar);
    }

    // 重载除法运算符（向量除以标量）
    Vector3 operator/(float scalar) const
    {
        return Vector3(x / scalar, y / scalar, z / scalar);
    }

    // 重载乘法运算符（float 乘以 Vector3）
    friend Vector3 operator*(float scalar, const Vector3 &vec)
    {
        return Vector3(vec.x * scalar, vec.y * scalar, vec.z * scalar);
    }

    // 重载除法运算符(float 除以 Vector3)
    friend Vector3 operator/(float scalar, const Vector3 &vec)
    {
        return Vector3(vec.x / scalar, vec.y / scalar, vec.z / scalar);
    }

    // 计算向量的反射
    Vector3 Reflect(const Vector3 &normal) const
    {
        float dotProduct = Dot(normal);
        return *this - 2 * dotProduct * normal;
    }

    // 获取数量级
    float magnitude() const
    {
        return (float)std::sqrt((double)x * (double)x + (double)y * (double)y + (double)z * (double)z);
    }

    // 获取未开方数量级，这个性能更好，在高频使用时用这个更好
    float sqrMagnitude() const
    {
        return x * x + y * y + z * z;
    }

    // 计算向量之间的距离
    static float Distance(const Vector3 &a, const Vector3 &b)
    {
        float dx = b.x - a.x;
        float dy = b.y - a.y;
        float dz = b.z - a.z;
        return std::sqrt(dx * dx + dy * dy + dz * dz);
    }

    // 线性插值
    static Vector3 Lerp(const Vector3 &a, const Vector3 &b, float t)
    {
        return Vector3(a.x + (b.x - a.x) * t, a.y + (b.y - a.y) * t, a.z + (b.z - a.z) * t);
    }

    // 求的单位向量
    Vector3 normalize() const
    {
        float mag = magnitude();
        if (mag != 0)
        {
            return {x / mag, y / mag, z / mag};
        }
        else
        {
            // 处理零向量的情况，如果向量长度为0，返回原始向量
            return *this;
        }
    }
};
