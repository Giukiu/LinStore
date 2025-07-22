#include <iostream>

int main()
{
    int correct = 6;
    int questions = 10;
    double score = correct / (double)questions * 100;       /*显示类型转换*/

    std::cout << score << "%";
    char c;
    std::cin >> c;
    switch (c) {        /*显式类型转换*/
        case 'A':
            std::cout << "hello";
            break;
        case 'B':
            std::cout << "world";
            break;
    }
    return 0;
}