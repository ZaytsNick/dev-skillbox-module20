#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(nullptr));
    int x, y;
    std::cout << "Enter weight and height: ";
    std::ofstream file("pic.txt");
    std::cin >> x >> y;
    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < x; ++j)
        {
            file << std::rand() % 2;
        }
        file << '\n';
    }
}