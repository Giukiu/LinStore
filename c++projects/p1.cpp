#include <iostream>
/*创建命名空间*/
namespace first {
	int x = 1;
	int y = 1;
	int t = 2;
}
int main()
{
	using namespace first;
	std::cout << t + x;
	return 0;
}