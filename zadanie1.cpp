#include <iostream>
#include <math.h>

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
constexpr Fraction operator+(Fraction lhs, const Fraction &rhs)
{
    int64_t new_n = lhs.num() * rhs.den() + lhs.den() * rhs.num();
    int64_t new_d = lhs.den() * rhs.den();
    return Fraction(new_n, new_d);
}
constexpr Fraction operator+=(Fraction lhs, const Fraction &rhs)
{
    int64_t new_n = lhs.num() * rhs.den() + lhs.den() * rhs.num();
    int64_t new_d = lhs.den() * rhs.den();
    return Fraction(new_n, new_d);
}
constexpr Fraction operator-(Fraction lhs, const Fraction &rhs)
{
    int64_t new_n = lhs.num() * rhs.den() - lhs.den() * rhs.num();
    int64_t new_d = lhs.den() * rhs.den();
    return Fraction(new_n, new_d);
}
constexpr Fraction operator-=(Fraction lhs, const Fraction &rhs)
{
    int64_t new_n = lhs.num() * rhs.den() - lhs.den() * rhs.num();
    int64_t new_d = lhs.den() * rhs.den();
    return Fraction(new_n, new_d);
}
constexpr Fraction operator/(Fraction lhs, const Fraction &rhs)
{
    int64_t new_n = lhs.num() * rhs.den();
    int64_t new_d = lhs.den() * rhs.num();
    return Fraction(new_n, new_d);
}
constexpr Fraction operator/=(Fraction lhs, const Fraction &rhs)
{
    int64_t new_n = lhs.num() * rhs.den();
    int64_t new_d = lhs.den() * rhs.num();
    return Fraction(new_n, new_d);
}

constexpr double to_double(const Fraction &f)
{
    return double(f.num()) / f.den();
}
int main()
{
    int N = 100;
    double sum = 0;
    Fraction sum1(0);
    double fract = 0;
    for (int i = 1; i <= 100; i++)
    {
        Fraction f1(1, (i * (i + 1)));
        fract = to_double(f1);
        sum += fract;
        sum1 = sum1+f1;
        std::cout << i << " " << sum1 << "   " << to_double(sum1) << std::endl;
    }
    std::cout << "suma a): " << sum << std::endl;
    N = 20;
    sum = 0;
    fract = 0;
    sum1 = 0;
    for (int i = 1; i <= 20; i++)
    {
        Fraction f1(pow((-1),i+1),i);
        fract = to_double(f1);
        sum += fract;
        sum1 = sum1+f1;
        std::cout << i << " " << sum1 << "   " << to_double(sum1) << std::endl;
    }
    std::cout << "suma b): " << sum << std::endl;
    N = 15;
    sum = 0;
    fract = 0;
    sum1 = 0;
    for (int i = 1; i <= 15; i++)
    {
        Fraction f1(1,pow(2,1)*i);
        fract = to_double(f1);
        sum += fract;
        sum1 = sum1+f1;
        std::cout << i << " " << sum1 << "   " << to_double(sum1) << std::endl;
    }
    std::cout << "suma c): " << sum << std::endl;
    double ulamek = (sqrt(5)+1)/2;
    for(int i = 0; i < 1; i++){
        int ulamek2 = floor(ulamek);
        double ulamek3 = ulamek - ulamek2;
        std::cout << ulamek3;
        double ulamek4 = 2/ulamek3;
        std::cout << ulamek2 << " ";
        ulamek = ulamek4;
    }

}
