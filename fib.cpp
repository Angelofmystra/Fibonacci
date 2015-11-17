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

int main()
{
	std::cout << fib<5>::value << "\n";
	std::cout << fib<10>::value << "\n";
	std::cout << fib<15>::value << "\n";
	std::cout << fib<45>::value << "\n";
	return 0;
}