#include <iostream>
#include "Vector2.h"

int main() {
    // 创建两个向量
    Vector2 vec1(3.0f, 4.0f);
    Vector2 vec2(1.0f, 2.0f);

    // 计算点积和叉乘
    float dotProduct = vec1.Dot(vec2);
    float crossProduct = vec1.Cross(vec2);

    // 输出结果
    std::cout << "Dot Product: " << dotProduct << std::endl;
    std::cout << "Cross Product: " << crossProduct << std::endl;

    // 使用运算符重载
    Vector2 sum = vec1 + vec2;
    Vector2 difference = vec1 - vec2;
    Vector2 scaled = vec1 * 2.0f;
    Vector2 divided = vec1 / 2.0f;

    // 输出结果
    std::cout << "Sum: (" << sum.x << ", " << sum.y << ")" << std::endl;
    std::cout << "Difference: (" << difference.x << ", " << difference.y << ")" << std::endl;
    std::cout << "Scaled: (" << scaled.x << ", " << scaled.y << ")" << std::endl;
    std::cout << "Divided: (" << divided.x << ", " << divided.y << ")" << std::endl;

    // 计算向量的反射
    Vector2 normal(1.0f, 1.0f);
    Vector2 reflected = vec1.Reflect(normal);
    std::cout << "Reflected: (" << reflected.x << ", " << reflected.y << ")" << std::endl;

    // 获取向量的长度
    float mag = vec1.magnitude();
    std::cout << "Magnitude of vec1: " << mag << std::endl;

    // 计算向量之间的距离
    float distance = Vector2::Distance(vec1, vec2);
    std::cout << "Distance between vec1 and vec2: " << distance << std::endl;

    // 线性插值
    Vector2 lerped = Vector2::Lerp(vec1, vec2, 0.5f);
    std::cout << "Lerped: (" << lerped.x << ", " << lerped.y << ")" << std::endl;

    // 求单位向量
    Vector2 normalized = vec1.normalize(vec1);
    std::cout << "Normalized vec1: (" << normalized.x << ", " << normalized.y << ")" << std::endl;

    return 0;
}
