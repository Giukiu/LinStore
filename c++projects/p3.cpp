#include <iostream>  /*简化条件句*/
int main()
{
    int i = 5;
    i > 10 ? std::cout << "Yes" : std::cout << "No" << std::endl;

    bool a = true;
    std::cout << (a ? "Hello" : "World");
    return 0;
}