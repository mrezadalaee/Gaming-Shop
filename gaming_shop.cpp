#include <iostream>
#include <vector>
#include <stdlib.h>
#include <windows.h>
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
std::vector<Products> games;
bool isNumber(const std::string s);

void add()
{
    std::string mojody, price;
    system("cls");
    Products game;
    std::cout << "name: ";
    std::cin >> game.name;
    std::cout << "category ";
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
        std::cout << "mojody should be an int";
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
        std::cout << "price should be an int";
        return;
    }
    games.push_back(game);
    system("cls");
    std::cout << "\n Added \n";
    Sleep(1350);
    system("cls");
    std::cout << "Back to menu.";
    Sleep(1350);
    system("cls");
    std::cout << "Back to menu..";
    Sleep(1350);
    system("cls");
    std::cout << "Back to menu...";
    Sleep(1350);
    system("cls");

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
    if (games.empty())
    {
        system("cls");
        std::cout << "\n not found 404\n";
        return;
    }
    std::string name;
    system("cls");
    std::cout << "name:";
    std::cin >> name;
    for (int i = 0; i <= games.size(); i++)
    {
        if (name == games[i].name)
        {
            games.erase(games.begin() + i);
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
    for (int i = 0; i <= games.size(); i++)
    {
        if (name == games[i].name)
        {
            system("cls");
            std::cout << "Found!" << std::endl;
            std::cout << games[i].name << std::endl;
            std::cout << games[i].price << std::endl;
            std::cout << games[i].mojody << std::endl;

            break;
        }
    }
    return;
}

void show()
{
    int size = games.size();
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
        std::cout << games[i].name << std::endl;
        std::cout << games[i].price << std::endl;
        std::cout << games[i].mojody << std::endl;
    }
    return;
}
void calculate()
{
    int size = games.size();
    long double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += games[i].price;
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
            std::cout << "Login page.\n";
            Sleep(1500);
            system("cls");
            std::cout << "Login page..\n";
            Sleep(1500);
            system("cls");
            std::cout << "Login page...\n";
            Sleep(1500);
        }
        else if (choice2 == 2)
        {
            system("cls");
            std::cout << "going to menu.";
            Sleep(1500);
            system("cls");
            std::cout << "going to menu..";
            Sleep(1500);
            system("cls");
            std::cout << "going to menu...";
            Sleep(1500);
        }
        else
        {
            system("cls");
            std::cout << "Auth page.";
            Sleep(1500);
            system("cls");
            std::cout << "Auth page..";
            Sleep(1500);
            system("cls");
            std::cout << "Auth page...";
            Sleep(1500);
        }
    }

    if (choice2 == 1)
    {
        system("cls");
        std::string password;
        std::cout << "enter password: ";
        std::cin >> password;
        system("cls");

        if (password == Password)
        {

            int choice;
            do
            {
                std::cout << "\n------ menu------\n";
                std::cout << "1. Add game\n";
                std::cout << "2. Delete Game\n";
                std::cout << "3. Search Game\n";
                std::cout << "4. Show All Games \n";
                std::cout << "5. Calculate price \n";
                std::cout << "6. wallet charge \n";
                std::cout << "7. Exit\n";
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
                case 7:
                    std::cout << "\n Exit\n";
                    break;
                case 6:
                    walletCharge();
                    break;
                default:
                    std::cout << "\n Invalid\n";
                }

            } while (choice != 7);
        }
        else
        {
            std::cout<<"Wrong...";
            Sleep(1500);
            menu();
        }
    }
    else if (choice2 == 1)
    {
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