#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
void info_bills(int &bill_1h, int &bill_2h, int &bill_5h, int &bill_1k, int &bill_2k, int &bill_5k, int &sum)
{
    std::cout << "At the ATM now:\n"
              << bill_1h << "\t100\truble banknotes;\n"
              << bill_2h << "\t200\truble banknotes;\n"
              << bill_5h << "\t500\truble banknotes;\n"
              << bill_1k << "\t1000\truble banknotes;\n"
              << bill_2k << "\t2000\truble banknotes;\n"
              << bill_5k << "\t5000\truble banknotes;\n"
              << "Total amount:\t" << sum
              << std::endl;
}
void read_file(int &bill_1h, int &bill_2h, int &bill_5h, int &bill_1k, int &bill_2k, int &bill_5k, int &sum)
{
    std::ifstream bills("bills.bin", std::ios::binary);
    while (!bills.eof())
    {
        int temp(0);
        bills.read((char *)&temp, sizeof(temp));
        sum += temp;
        if (temp == 100)
        {
            bill_1h++;
            continue;
        }
        if (temp == 200)
        {
            bill_2h++;
            continue;
        }
        if (temp == 500)
        {
            bill_5h++;
            continue;
        }
        if (temp == 1000)
        {
            bill_1k++;
            continue;
        }
        if (temp == 2000)
        {
            bill_2k++;
            continue;
        }
        if (temp == 5000)
        {
            bill_5k++;
            continue;
        }
    }
}
void plus()
{
    std::ofstream bills("bills.bin", std::ios::binary);
    for (int i = 0; i < 10; i++)
    {
        int value[] = {100, 200, 500, 1000, 2000, 5000};
        bills.write((char *)&value[rand() % 6], sizeof(value[0]));
    }
}
void saving_state(int &bill_1h, int &bill_2h, int &bill_5h, int &bill_1k, int &bill_2k, int &bill_5k)
{
    int value[] = {100, 200, 500, 1000, 2000, 5000};
    std::ofstream bills("bills.bin", std::ios::binary);
    for (int i = 0; i < bill_1h; i++)
    {
        bills.write((char *)&value[0], sizeof(value[0]));
    }
    for (int i = 0; i < bill_2h; i++)
    {
        bills.write((char *)&value[1], sizeof(value[0]));
    }
    for (int i = 0; i < bill_5h; i++)
    {
        bills.write((char *)&value[2], sizeof(value[0]));
    }
    for (int i = 0; i < bill_1k; i++)
    {
        bills.write((char *)&value[3], sizeof(value[0]));
    }
    for (int i = 0; i < bill_2k; i++)
    {
        bills.write((char *)&value[4], sizeof(value[0]));
    }
    for (int i = 0; i < bill_5k; i++)
    {
        bills.write((char *)&value[5], sizeof(value[0]));
    }
}
int function_min_bill(int &bill_1h, int &bill_2h, int &bill_5h, int &bill_1k, int &bill_2k, int &bill_5k)
{
    while (true)
    {
        if (bill_1h != 0)
            return 100;
        if (bill_2h != 0)
            return 200;
        if (bill_5h != 0)
            return 500;
        if (bill_1k != 0)
            return 1000;
        if (bill_2k != 0)
            return 2000;
        if (bill_5k != 0)
            return 5000;
    }
}
void minus(int &bill_1h, int &bill_2h, int &bill_5h, int &bill_1k, int &bill_2k, int &bill_5k, int &sum)
{
    int min_bill = function_min_bill(bill_1h, bill_2h, bill_5h, bill_1k, bill_2k, bill_5k);
    std::cout << "Enter how much money you want to withdraw: ";
    int money;
    std::cin >> money;
    if (/*!(money % min_bill) &&*/ money <= sum) // money%200<bill_1h
    {
        int temp_arr[6] = {0, 0, 0, 0, 0, 0};
        int temp_money = money;
        if ((bool)bill_5k && temp_money / 5000)
        {
            temp_arr[0] = temp_money / 5000 > bill_5k ? bill_5k : temp_money / 5000;
            temp_money -= temp_arr[0] * 5000;
        }
        if ((bool)bill_2k && temp_money / 2000)
        {
            temp_arr[1] = temp_money / 2000 > bill_2k ? bill_2k : temp_money / 2000;
            temp_money -= temp_arr[1] * 2000;
        }
        if ((bool)bill_1k && temp_money / 1000)
        {

            temp_arr[2] = temp_money / 1000 > bill_1k ? bill_1k : temp_money / 1000;
            temp_money -= temp_arr[2] * 1000;
        }
        if ((bool)bill_5h && temp_money / 500)
        {
            temp_arr[3] = temp_money / 500 > bill_5h ? bill_5h : temp_money / 500;
            temp_money -= temp_arr[3] * 500;
        }
        if ((bool)bill_2h && temp_money / 200)
        {
            temp_arr[4] = temp_money / 200 > bill_2h ? bill_2h : temp_money / 200;
            temp_money -= temp_arr[4] * 200;
        }
        if ((bool)bill_1h && temp_money / 100)
        {
            temp_arr[5] = temp_money / 100 > bill_1h ? bill_1h : temp_money / 100;
            temp_money -= temp_arr[5] * 100;
            ;
        }
        if (money - temp_money == money)
        {
            sum -= money;
            bill_5k -= temp_arr[0]; // temp_money / 5000 > bill_5k ? bill_5k : temp_money / 5000;
            bill_2k -= temp_arr[1]; // temp_money / 2000 > bill_2k ? bill_2k : temp_money / 2000;
            bill_1k -= temp_arr[2]; // temp_money / 1000 > bill_1k ? bill_1k : temp_money / 1000;
            bill_5h -= temp_arr[3]; // temp_money / 500 > bill_5h ? bill_5h : temp_money / 500;
            bill_2h -= temp_arr[4]; // temp_money / 200 > bill_2h ? bill_2h : temp_money / 200;
            bill_1h -= temp_arr[5]; // temp_money / 100 > bill_1h ? bill_1h : temp_money / 100;

            info_bills(bill_1h, bill_2h, bill_5h, bill_1k, bill_2k, bill_5k, sum);

            saving_state(bill_1h, bill_2h, bill_5h, bill_1k, bill_2k, bill_5k);
        }
        else
            std::cout << "This operation is not possible: the requested amount cannot be\n withdrawn due to the lack of suitable banknotes in the machine" << std::endl;
    }
    else
        std::cout << "This operation is not possible: the requested amount cannot be\n withdrawn due to the lack of suitable banknotes in the machine" << std::endl;
}
int main()
{
    std::srand(std::time(nullptr));
    int bill_1h(0), bill_2h(0), bill_5h(0), bill_1k(0), bill_2k(0), bill_5k(0), sum(0);
    std::ifstream bills("bills.bin", std::ios::binary);
    if (bills.is_open())
    {
        read_file(bill_1h, bill_2h, bill_5h, bill_1k, bill_2k, bill_5k, sum);
        info_bills(bill_1h, bill_2h, bill_5h, bill_1k, bill_2k, bill_5k, sum);
        std::string action;
        std::cout << "Do you want to withdraw or deposit money into your account? ";
        std::cin >> action;
        if (action == "+")
            plus();
        if (action == "-")
            minus(bill_1h, bill_2h, bill_5h, bill_1k, bill_2k, bill_5k, sum);
    }
    else
    {
        while (true)
        {
            std::cout << "ATM empty" << std::endl;
            std::string action;
            std::cout << "Should I add money to the ATM? ";
            std::cin >> action;
            if (action == "+")
            {
                plus();
                break;
            }
        }
    }
}