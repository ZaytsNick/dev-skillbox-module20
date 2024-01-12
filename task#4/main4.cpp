#include <iostream>
#include <fstream>
#include <string>
int main()
{
    std::string bin_data="*.bin";
    std::ofstream bin(bin_data, std::ios::app);
    if(bin.is_open())
    {
        std::cout<<"В банкомате сейчас "<< "купюр";//каждного наминала
        std::cout<<"Общая сумма";
    }
    else
    {
        std::cout<<"ATM empty";
    }
    char move('=');
    std::cout<<"Do you want to withdraw or deposit money into your account? ";
    std::cin>>move;
    switch (move)
    {
    case '+'/* constant-expression */:
        /* code */
        break;
        
    case '-'/* constant-expression */:
        /* code */
        break;
    
    default:
        break;
    }
}