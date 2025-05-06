#include <iostream>
int main()
{
	std::cout << "**************计算开始**************\n";
	int number1, number2;
	char op;
	std::cout << "enter + - * /" << std::endl;
	std::cin >> op;
	std::cout << "enter number1: ";
	std::cin >> number1;
	std::cout << "enter number2: ";
	std::cin >> number2;
	switch (op) {
		
	case '+':
		std::cout << number1 << " + " << number2 << " = " << number1 + number2;
		break;
	case '-':
		std::cout << number1 << " - " << number2 << " = " << number1 - number2;
		break;
	case '*':
		std::cout << number1 << " × " << number2 << " = " << number1 * number2;
		break;
	case'/':
		std::cout << number1 << " ÷ " << number2 << " = " << number1 / number2;
		break;
	default:
		std::cout << "That wasn't a valid response" << std::endl;
	}
	std::cout << "\n********************结束************************";
	return 0;
}