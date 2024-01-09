#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ofstream file("database_pay.txt",std::ios::app);

    std::string name, second_name, date;
    int pay;
    std::cout<<"Enter record(For example: Name Second_name DD.MM.YYYY pay):"<<std::endl;
    std::cin >> name >> second_name >> date >> pay;
    file << name << '\t' << second_name << '\t' << date << '\t' << pay << std::endl;
    file.close();
}