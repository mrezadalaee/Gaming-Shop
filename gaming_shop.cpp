#include <iostream>
#include <vector>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
long int shopWallet = 0;
long int userWallet = 0;
long int *shopWalletAdrress = &shopWallet;
long int *userWalletAdrress = &userWallet;
const std::string Password = "admin1admin";
struct Products
{
    std::string name;
    int price;
    int mojody;
    std::string category;
};
struct CartItem
{
    std::string productName;
    int price;
};
struct Cart
{
    long int totalPrice = 0;
    std::vector<CartItem> items;
};
Cart cart;
std::vector<CartItem> cartItems; // cart items
std::vector<Products> products;

bool isNumber(const std::string s);

void sleepPrint(std::string message)
{

    Sleep(1500);
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
void showShopWalletMojodi()
{
    system("cls");
    std::cout << "Mojody is: " << *shopWalletAdrress << "\n";
    Sleep(500);
    sleepPrint("Back to menu");

    return;
}
void showUserWalletMojodi()
{
    system("cls");
    std::cout << "Mojody is: " << *userWalletAdrress << "\n";
    Sleep(500);
    sleepPrint("Back to menu");

    return;
}

void add()
{
    std::string mojody, price;
    system("cls");
    Products product;
    std::cout << "name: ";
    std::cin >> product.name;
    std::cout << "category: ";
    std::cin >> product.category;
    std::cout << "mojody: ";
    std::cin >> mojody;
    if (isNumber(mojody))
    {

        product.mojody = std::stoi(mojody);
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

        product.price = std::stoi(price);
    }
    else
    {
        system("cls");
        std::cout << "price should be an string";
        return;
    }
    products.push_back(product);
    system("cls");
    std::cout << "\n Added \n";
    sleepPrint("back to menu");

    return;
}
void shopWalletCharge()
{
    std::cout << "Cheghadr mi khahid charge konid?\n";
    long int value;
    std::cin >> value;
    *shopWalletAdrress += value;

    return;
}
void userWalletCharge()
{
    std::cout << "Cheghadr mi khahid charge konid?\n";
    long int value;
    std::cin >> value;
    *userWalletAdrress += value;

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
    if (products.empty())
    {
        system("cls");
        std::cout << "\n not found 404\n";
        return;
    }
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
void addToCart()
{
    system("cls");
    CartItem item;

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
        std::cout << "----------------------------\n \n";
    }
    std::string productToAdd;
    int tedad;
    std::cout << "enter the product that you want to buy: ";

    std::cin >> productToAdd;
    CartItem cartitem;
    for (int i = 0; i < products.size(); i++)
    {
        if (products[i].name == productToAdd && products[i].mojody != 0)
        {
            item.productName = products[i].name;
            item.price = products[i].price;
            cartItems.push_back(item);
            cart.items = cartItems;
            long int sum = 0;
            for (int j = 0; j < cartItems.size(); j++)
            {
                sum += cartItems[j].price;
            }
            cart.totalPrice = sum;

            return;
        }
        else if (products[i].name == productToAdd && products[i].mojody == 0)
        {
            system("cls");
            std::cout << "Not enogh product mojody";
            sleepPrint("Back to menu");
            return;
        }
    }
    std::cout << "Not found!";
    return;
}

void seeCart()
{
    if (cart.totalPrice == 0)
    {
        std::cout << "You do not have any product in your cart";
        return;
    }
    std::cout << "The products in your cart:\n";
    for (int i = 0; i < cart.items.size(); i++)
    {
        std::cout << i << "." << cart.items[i].productName << std::endl;
        std::cout << "    " << "price:" << cart.items[i].price << std::endl;
    }
    return;
}

void checkout()
{
    if (cart.totalPrice > *userWalletAdrress)
    {
        std::cout << "You do not have enohg money, pleas charge your wallet.";
        Sleep(500);
        sleepPrint("Going to charge page");
        userWalletCharge();
    }
    else
    {
        *userWalletAdrress -= cart.totalPrice;
        cart.totalPrice = 0;
        for (int i = 0; i < products.size(); i++)
        {
            for (int j = 0; j < cart.items.size(); j++)
            {
                if (products[i].name == cart.items[i].productName)
                {
                    products[i].mojody--;
                }
            }
        }

        cart.items.clear();
        std::cout << "Finished... \n";
        std::cout << "the post bring your baste to your home";
        return;
    }
}
void menu()
{
    int AUchoice;
    int menuChoice;

    while (AUchoice != 1 && AUchoice != 2)
    {
        system("cls");
        std::cout << "---- Auth ---- \n";
        std::cout << "1. Admin \n";
        std::cout << "2. User \n";
        std::cin >> AUchoice;
        if (AUchoice != 1 && AUchoice != 2)
        {
            system("cls");
            std::cout << "1 OR 2";
            Sleep(1500);
            system("cls");
            sleepPrint("loging page");
        }
        else if (AUchoice == 2)
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

    if (AUchoice == 1)
    {
        system("cls");
        std::string password;
        // std::cout << "enter password: ";
        // std::cin >> password;
        // system("cls");

        if (true)
        {

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
                std::cin >> menuChoice;

                switch (menuChoice)
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
                    menu();
                    break;
                case 7:
                    showShopWalletMojodi();
                    break;
                case 6:
                    shopWalletCharge();

                    break;
                default:
                    std::cout << "\n Invalid\n";
                }

            } while (menuChoice != 9);
        }
        else
        {
            std::cout << "Wrong...";
            Sleep(1500);
            menu();
        }
    }
    else if (AUchoice == 2)
    {
        do
        {
            std::cout << "\n------ menu------\n";
            std::cout << "1. Search Product\n";
            std::cout << "2. wallet charge \n";
            std::cout << "3. Wallet mojody\n";
            std::cout << "4. Show All Products \n";
            std::cout << "5. Add To Cart \n";
            std::cout << "6. checkout \n";
            std::cout << "7. See Cart\n";
            std::cout << "8. Exit\n";
            std::cout << "Your Choice?: ";
            std::cin >> menuChoice;

            switch (menuChoice)
            {
            case 1:
                search();
                break;
            case 2:
                userWalletCharge();
                break;
            case 3:
                showUserWalletMojodi();
                break;
            case 4:
                show();
                break;
            case 5:
                addToCart();
                break;
            case 6:
                checkout();
                break;
            case 7:
                seeCart();

                break;
            case 8:
                std::cout << "\n Exit\n";
                menu();
                break;
            default:
                std::cout << "\n Invalid\n";
            }

        } while (menuChoice != 9);
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