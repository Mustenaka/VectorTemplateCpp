#include <math.h>
#include <iostream>

struct Vector2
{
    float x, y;

    Vector2(float _x, float _y) : x(_x), y(_y) {}

    // 计算向量的点积
    float Dot(const Vector2 &other) const
    {
        return x * other.x + y * other.y;
    }

    // 计算向量的叉乘
    float Cross(const Vector2 &other) const
    {
        return x * other.y - y * other.x;
    }

    // 重载加法运算符
    Vector2 operator+(const Vector2 &other) const
    {
        return Vector2(x + other.x, y + other.y);
    }

    // 重载减法运算符
    Vector2 operator-(const Vector2 &other) const
    {
        return Vector2(x - other.x, y - other.y);
    }

    // 重载乘法运算符（向量与标量相乘）
    Vector2 operator*(float scalar) const
    {
        return Vector2(x * scalar, y * scalar);
    }

    // 重载除法运算符（向量除以标量）
    Vector2 operator/(float scalar) const
    {
        return Vector2(x / scalar, y / scalar);
    }

    // 重载乘法运算符（float 乘以 Vector2）
    friend Vector2 operator*(float scalar, const Vector2 &vec)
    {
        return Vector2(vec.x * scalar, vec.y * scalar);
    }

    // 重载除法运算符(float 除以 Vector2)
    friend Vector2 operator/(float scalar, const Vector2 &vec)
    {
        return Vector2(vec.x / scalar, vec.y / scalar);
    }

    // 计算向量的反射
    Vector2 Reflect(const Vector2 &normal) const
    {
        float dotProduct = Dot(normal);
        return *this - 2 * dotProduct * normal;
    }

    // 获取数量级
    float magnitude() const
    {
        return (float)std::sqrt((double)x * (double)x + (double)y * (double)y);
    }

    // 获取未开方数量级，这个性能更好，在高频使用时用这个更好
    float sqrMagnitude() const
    {
        return x * x + y * y;
    }

    // 计算向量之间的距离
    static float Distance(const Vector2 &a, const Vector2 &b)
    {
        float dx = b.x - a.x;
        float dy = b.y - a.y;
        return std::sqrt(dx * dx + dy * dy);
    }

    // 线性插值
    static Vector2 Lerp(const Vector2 &a, const Vector2 &b, float t)
    {
        return Vector2(a.x + (b.x - a.x) * t, a.y + (b.y - a.y) * t);
    }

    // 求的单位向量
    Vector2 normalize(const Vector2 &v)
    {
        float mag = v.magnitude();
        if (mag != 0)
        {
            return {v.x / mag, v.y / mag};
        }
        else
        {
            // 处理零向量的情况，如果向量长度为0，返回原始向量
            return v;
        }
    }
};