#include <iostream>

int main() {
	int a, b;
	double result;
	std::cin >> a >> b;
	result = (double)a / b;
	std::cout << std::fixed;
	std::cout.precision(9);
	std::cout << result << std::endl;
	return 0;
}