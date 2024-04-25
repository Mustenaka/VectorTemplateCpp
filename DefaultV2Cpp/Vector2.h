#ifndef VECTOR2_H
#define VECTOR2_H

#include <cmath>
#include <string>
#include <sstream>

struct Vector2
{
    float x, y;

    Vector2(float _x, float _y) : x(_x), y(_y) {}

    // 计算向量的点积
    float Dot(const Vector2 &other) const;

    // 计算向量的叉乘
    float Cross(const Vector2 &other) const;

    // 重载加法运算符
    Vector2 operator+(const Vector2 &other) const;

    // 重载减法运算符
    Vector2 operator-(const Vector2 &other) const;

    // 重载乘法运算符（向量与标量相乘）
    Vector2 operator*(float scalar) const;

    // 重载除法运算符（向量除以标量）
    Vector2 operator/(float scalar) const;

    // 重载乘法运算符（float 乘以 Vector2）
    friend Vector2 operator*(float scalar, const Vector2 &vec);

    // 重载除法运算符(float 除以 Vector2)
    friend Vector2 operator/(float scalar, const Vector2 &vec);

    // 计算向量的反射
    Vector2 Reflect(const Vector2 &normal) const;

    // 获取数量级
    float magnitude() const;

    // 获取未开方数量级，这个性能更好，在高频使用时用这个更好
    float sqrMagnitude() const;

    // 计算向量之间的距离
    static float Distance(const Vector2 &a, const Vector2 &b);

    // 线性插值
    static Vector2 Lerp(const Vector2 &a, const Vector2 &b, float t);

    // 求的单位向量
    Vector2 normalize(const Vector2 &v);

    // 格式化输出字符串
    std::string toString() const;
};

#endif // VECTOR2_H
