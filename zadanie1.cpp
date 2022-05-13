#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

class Fraction
{
    constexpr int64_t gcd(int64_t a, int64_t b) { return b == 0 ? a : gcd(b, a % b); } // or C++17's std::gcd
    int64_t n, d;

public:
    constexpr Fraction(int64_t n, int64_t d = 1) : n(n / gcd(n, d)), d(d / gcd(n, d)) {}
    constexpr int64_t num() const { return n; }
    constexpr int64_t den() const { return d; }
    constexpr Fraction &operator*=(const Fraction &rhs)
    {
        int64_t new_n = n * rhs.n / gcd(n * rhs.n, d * rhs.d);
        d = d * rhs.d / gcd(n * rhs.n, d * rhs.d);
        n = new_n;
        return *this;
    }
    constexpr Fraction &operator+=(const Fraction &rhs)
    {
        int64_t new_n = n * rhs.d + d * rhs.n;
        int64_t new_d = d * rhs.d;
        n = new_n / gcd(new_n, new_d);
        d = new_d / gcd(new_n, new_d);
        return *this;
    }
    constexpr Fraction &operator-=(const Fraction &rhs)
    {
        int64_t new_n = n * rhs.d - d * rhs.n;
        int64_t new_d = d * rhs.d;
        n = new_n / gcd(new_n, new_d);
        d = new_d / gcd(new_n, new_d);
        return *this;
    }
    constexpr Fraction &operator/=(const Fraction &rhs)
    {
        int64_t new_n = n * rhs.d;
        int64_t new_d = d * rhs.n;
        n = new_n / gcd(new_n, new_d);
        d = new_d / gcd(new_n, new_d);
        return *this;
    }
};
std::ostream &operator<<(std::ostream &out, const Fraction &f)
{
    return out << f.num() << '/' << f.den();
}
constexpr bool operator==(const Fraction &lhs, const Fraction &rhs)
{
    return lhs.num() == rhs.num() && lhs.den() == rhs.den();
}
constexpr bool operator!=(const Fraction &lhs, const Fraction &rhs)
{
    return !(lhs == rhs);
}
constexpr Fraction operator*(Fraction lhs, const Fraction &rhs)
{
    return lhs *= rhs;
}
constexpr Fraction operator+(Fraction lhs, const Fraction &rhs){
    int64_t new_n = lhs.num() * rhs.den() + lhs.den() * rhs.num();
    int64_t new_d = lhs.den() * rhs.den();
    return Fraction(new_n, new_d);
}
constexpr Fraction operator-(Fraction lhs, const Fraction &rhs){
    int64_t new_n = lhs.num() * rhs.den() - lhs.den() * rhs.num();
    int64_t new_d = lhs.den() * rhs.den();
    return Fraction(new_n, new_d);
}
constexpr Fraction operator/(Fraction lhs, const Fraction &rhs){
    int64_t new_n = lhs.num() * rhs.den();
    int64_t new_d = lhs.den() * rhs.num();
    return Fraction(new_n, new_d);
}
constexpr double to_double(const Fraction &f){
    return double(f.num()) / f.den();
}
constexpr Fraction to_fraction(double number){
    //multiply number by 10 until it is whole number
    int counter = 0;
    while(number != std::floor(number)){
        number *= 10;
        counter++;
    }
    //convert to fraction
    int64_t n = std::floor(number);
    int64_t d = std::pow(10, counter);
    return Fraction(n, d);
}
constexpr Fraction flip(const Fraction &f){
    return Fraction(f.den(), f.num());
}
int main()
{
    Fraction sum = Fraction(0);
    for (int64_t i = 1; i <= 100; ++i)
    {
        sum += Fraction(1, i * (i + 1));
    }
    std::cout << sum << '\n';
    std::cout << to_double(sum) << '\n';
    Fraction sum2 = Fraction(0);
    for (int64_t i = 1; i <= 20; ++i)
    {
        sum2 += Fraction(pow(-1, i+1), i);
    }
    std::cout << sum2 << '\n';
    std::cout << to_double(sum2) << '\n';
    Fraction sum3 = Fraction(0);
    for (int64_t i = 1; i <= 15; ++i)
    {
        sum3 += Fraction(1, pow(2, i)*i);
    }
    std::cout << sum3 << '\n';
    std::cout << to_double(sum3) << '\n';
    std::cout << to_fraction(4.78) << '\n';
    // double x = (sqrt(5)+1)/2;
    // for(int i = 0; i < 20; i++){
    //     double y = floor(x);
    //     double z = x-y;
    //     Fraction a = to_fraction(z);
    //     Fraction b = flip(a);
    //     std::cout << y << ' ';
    //     x = to_double(b);
    // }
    // std::cout << std::endl;
    // x = M_E;
    // for(int i = 0; i < 20; i++){
    //     double y = floor(x);
    //     double z = x-y;
    //     Fraction a = to_fraction(z);
    //     Fraction b = flip(a);
    //     std::cout << y << ' ';
    //     x = to_double(b);
    // }


}
