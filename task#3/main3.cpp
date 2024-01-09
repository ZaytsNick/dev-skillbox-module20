#include <iostream>
#include <string>
#include <fstream>

int main()
{
    std::ifstream river("river.txt");
    std::ofstream basket("basket.txt", std::ios::app);
    std::string wish;
    int answer(0);
    std::cout << "Enter what kind of fish do you want to catch: ";
    std::cin >> wish;
    while (!river.eof())
    {
        std::string temp;
        river >> temp;
        if (temp == wish)
        {
            answer++;
            basket<<temp<<std::endl;
        }
    }
    river.close();
    basket.close();
    std::cout<<"Was caught: "<<answer<<' '<< wish;
}