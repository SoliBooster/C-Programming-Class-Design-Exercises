//===========================================
//设计并实现一个有理数类Rational，要求：
//1：用两个整数的比来描述有理数；
//2：能够进行加减乘除等算术运算；
//3：以分数形式输出有理数；
//4：提供double类型到有理数的类型转换；
//5：合理的初始化，注意检测分母和除数为0的错误，默认分子为0,分母为1；
//编写测试程序。
//===========================================

#include <iostream>
#include <stdexcept> // 用于异常处理
#include <cmath>    // 用于 std::abs 函数

// 用于简化分数
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

class Rational {
public:
    // 默认构造函数，分子为0，分母为1
    Rational(int numerator = 0, int denominator = 1) {
        if (denominator == 0) {
            throw std::invalid_argument("Denominator cannot be zero.");
        }
        int gcdValue = gcd(std::abs(numerator), std::abs(denominator));
        numerator_ = numerator / gcdValue;
        denominator_ = denominator / gcdValue;
        if (denominator_ < 0) { // 保证分母为正
            numerator_ = -numerator_;
            denominator_ = -denominator_;
        }
    }

    // 类型转换构造函数，从 double 类型到 Rational 类型
    Rational(double value) {
        numerator_ = static_cast<int>(value * 1000000); // 将 double 转换为整数
        denominator_ = 1000000;
        int gcdValue = gcd(std::abs(numerator_), std::abs(denominator_));
        numerator_ /= gcdValue;
        denominator_ /= gcdValue;
        if (denominator_ < 0) { // 保证分母为正
            numerator_ = -numerator_;
            denominator_ = -denominator_;
        }
    }

    // 加法
    Rational operator+(const Rational& other) const {
        int num = numerator_ * other.denominator_ + other.numerator_ * denominator_;
        int den = denominator_ * other.denominator_;
        return Rational(num, den);
    }

    // 减法
    Rational operator-(const Rational& other) const {
        int num = numerator_ * other.denominator_ - other.numerator_ * denominator_;
        int den = denominator_ * other.denominator_;
        return Rational(num, den);
    }

    // 乘法
    Rational operator*(const Rational& other) const {
        int num = numerator_ * other.numerator_;
        int den = denominator_ * other.denominator_;
        return Rational(num, den);
    }

    // 除法
    Rational operator/(const Rational& other) const {
        if (other.numerator_ == 0) {
            throw std::invalid_argument("Cannot divide by zero.");
        }
        int num = numerator_ * other.denominator_;
        int den = denominator_ * other.numerator_;
        return Rational(num, den);
    }

    // 输出有理数
    friend std::ostream& operator<<(std::ostream& os, const Rational& r) {
        os << r.numerator_;
        if (r.denominator_ != 1) {
            os << '/' << r.denominator_;
        }
        return os;
    }

private:
    int numerator_;
    int denominator_;
};

// 测试程序
int main() {
    try {
        Rational r1(3, 4);   // 3/4
        Rational r2(5, 6);   // 5/6

        std::cout << "r1: " << r1 << std::endl;
        std::cout << "r2: " << r2 << std::endl;

        Rational r3 = r1 + r2;
        std::cout << "r1 + r2: " << r3 << std::endl;

        Rational r4 = r1 - r2;
        std::cout << "r1 - r2: " << r4 << std::endl;

        Rational r5 = r1 * r2;
        std::cout << "r1 * r2: " << r5 << std::endl;

        Rational r6 = r1 / r2;
        std::cout << "r1 / r2: " << r6 << std::endl;

        Rational r7 = 1.5; // double 到有理数的转换
        std::cout << "1.5 as Rational: " << r7 << std::endl;

    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
