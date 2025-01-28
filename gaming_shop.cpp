#include <iostream>
#include <vector>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
long int wallet = 0;
long int *walletAdrress = &wallet;
const std::string Password = "admin1admin";
struct Products
{
    std::string name;
    int price;
    int mojody;
    std::string category;
};
struct ShopingCart {
    std::string productName;

};
std::vector<Products> products;
bool isNumber(const std::string s);

void sleepPrint(std::string message)
{

    Sleep(1000);
    system("cls");
    std::cout << message << ".";
    Sleep(1000);
    system("cls");
    std::cout << message << "..";
    Sleep(1000);
    system("cls");
    std::cout << message << "...";
    Sleep(1000);
    system("cls");
}
void showWalletMojodi()
{
    system("cls");
    std::cout << "Mojody is: " << *walletAdrress << "\n";
    Sleep(500);
    sleepPrint("Back to menu");

    return;
}

void add()
{
    std::string mojody, price;
    system("cls");
    Products game;
    std::cout << "name: ";
    std::cin >> game.name;
    std::cout << "category: ";
    std::cin >> game.category;
    std::cout << "mojody: ";
    std::cin >> mojody;
    if (isNumber(mojody))
    {

        game.mojody = std::stoi(mojody);
    }
    else
    {
        system("cls");
        std::cout << "mojody should be an string";
        return;
    }
    std::cout << "price: ";
    std::cin >> price;
    if (isNumber(price))
    {

        game.price = std::stoi(price);
    }
    else
    {
        system("cls");
        std::cout << "price should be an string";
        return;
    }
    products.push_back(game);
    system("cls");
    std::cout << "\n Added \n";
    sleepPrint("back to menu");

    return;
}
void walletCharge()
{
    std::cout << "Cheghadr mi khahid charge konid?\n";
    long int value;
    std::cin >> value;
    *walletAdrress += value;

    return;
}
void deleteGame()
{
    if (products.empty())
    {
        system("cls");
        std::cout << "\n not found 404\n";
        return;
    }
    std::string name;
    system("cls");
    std::cout << "name:";
    std::cin >> name;
    for (int i = 0; i <= products.size(); i++)
    {
        if (name == products[i].name)
        {
            products.erase(products.begin() + i);
            break;
        }
    }
    system("cls");
    std::cout << "\n Deleted\n";
    return;
}

void search()
{
    std::string name;
    system("cls");
    std::cout << "name:";
    std::cin >> name;
    for (int i = 0; i <= products.size(); i++)
    {
        if (name == products[i].name)
        {
            system("cls");
            std::cout << "Found!" << std::endl;
            std::cout << products[i].name << std::endl;
            std::cout << products[i].price << std::endl;
            std::cout << products[i].mojody << std::endl;

            break;
        }
    }
    return;
}

void show()
{
    int size = products.size();
    if (size == 0)
    {
        system("cls");
        std::cout << std::endl
                  << "There is not any game" << std::endl;
        return;
    }
    system("cls");
    for (int i = 0; i < size; i++)
    {
        std::cout << "Game " << i + 1 << std::endl;
        std::cout << products[i].name << std::endl;
        std::cout << products[i].price << std::endl;
        std::cout << products[i].mojody << std::endl;
        std::cout << "----------------------------\n";
    }
    std::cout << "prees spase to go to menu\n";
    char chert = getch();
    while (chert != ' ')
    {
        chert = getch();
    }

    system("cls");
    sleepPrint("Back to menu");
    return;
}
void calculate()
{
    int size = products.size();
    long double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += (products[i].price * products[i].mojody);
    }
    system("cls");
    std::cout << std::endl
              << "majmo is:"
              << sum << std::endl;
    return;
}
void menu()
{
    int choice2;

    while (choice2 != 1 && choice2 != 2)
    {
        system("cls");
        std::cout << "---- Auth ---- \n";
        std::cout << "1. Admin \n";
        std::cout << "2. User \n";
        std::cin >> choice2;
        if (choice2 != 1 && choice2 != 2)
        {
            system("cls");
            std::cout << "1 OR 2";
            Sleep(1500);
            system("cls");
            sleepPrint("loging page");
        }
        else if (choice2 == 2)
        {
            system("cls");
            sleepPrint("going to menu");
        }
        else
        {
            system("cls");
            sleepPrint("Auth page");
        }
    }

    if (choice2 == 1)
    {
        system("cls");
        std::string password;
        // std::cout << "enter password: ";
        // std::cin >> password;
        // system("cls");

        if (true)
        {

            int choice;
            do
            {
                std::cout << "\n------ menu------\n";
                std::cout << "1. Add Product\n";
                std::cout << "2. Delete Product\n";
                std::cout << "3. Search Product\n";
                std::cout << "4. Show All Products \n";
                std::cout << "5. Calculate price \n";
                std::cout << "6. wallet charge \n";
                std::cout << "7. Wallet mojody\n";
                std::cout << "8. Exit\n";
                std::cout << "Your Choice?: ";
                std::cin >> choice;

                switch (choice)
                {
                case 1:
                    add();
                    break;
                case 2:
                    deleteGame();
                    break;
                case 3:
                    search();
                    break;
                case 4:
                    show();
                    break;
                case 5:
                    calculate();
                    break;
                case 8:
                    std::cout << "\n Exit\n";
                    break;
                case 7:
                    showWalletMojodi();
                    break;
                case 6:
                    walletCharge();

                    break;
                default:
                    std::cout << "\n Invalid\n";
                }

            } while (choice != 8);
        }
        else
        {
            std::cout << "Wrong...";
            Sleep(1500);
            menu();
        }
    }
    else if (choice2 == 1)
    {
        //search
        //sabad

    }
}

int main()
{
    menu();
    return 0;
}

bool isNumber(const std::string s)
{
    for (char c : s)
    {
        if (!isdigit(c))
        {
            return false;
        }
    }
    return true;
}