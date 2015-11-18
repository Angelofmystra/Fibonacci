#include <iostream>
// incomplete definition
template <unsigned long long n> struct fib;
// base cases
template<> struct fib<0> { const static auto value = 0; };
template<> struct fib<1> { const static auto value = 1; };
// recursive definition
template<unsigned long long n> struct fib {
	const static auto value = fib<n - 1>::value + fib<n - 2>::value;
};

template <unsigned long long n> struct fact;
template<> struct fact<0> { const static auto value = 1; };
template<unsigned long long n> struct fact {
	const static auto value = n*fact<n - 1>::value;
};

template<unsigned long long n> struct hanoi;
template<> struct hanoi<1> { const static auto value = 1; };
template<unsigned long long n> struct hanoi {
	const static auto value = 2 * hanoi<n - 1>::value + 1;
};
/*

There is a problem with this template but I am unsure as to how to solve it.

template <unsigned long long x, unsigned long long y> struct gcd;
template <unsigned long long x, unsigned long long y> struct gcd<x, 0> {
	const static auto value = x;
};
template <unsigned long long x, unsigned long long y> struct gcd<x, y> {
	const static auto value = gcd<y, x%y>::value;
};
*/

int main()
{
	std::cout << fib<5>::value << "\n";
	std::cout << fib<10>::value << "\n";
	std::cout << fib<15>::value << "\n";
	std::cout << fib<45>::value << "\n";

	std::cout << fact<5>::value << "\n";
	std::cout << hanoi<4>::value << "\n";
	//std::cout << gcd<111,259>::value << "\n";
	return 0;
}