#include <iostream>
#include <vector>
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
void menu();

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
    std::cout << "1. Add more \n";
    std::cout << "2. Back to menu \n";
    char choice = getch();
    while (choice != '1' && choice != '2')
    {
        std::cout << "chose base on the list\n";
        choice = getch();
    }
    if (choice == '1')
    {
        add();
    }
    else if (choice == '2')
    {
        sleepPrint("back to menu");
        return;
    }
}
void shopWalletCharge()
{
    system("cls");
    std::cout << "Cheghadr mi khahid charge konid?\n";
    long int value;
    std::cin >> value;
    *shopWalletAdrress += value;
    system("cls");
    std::cout << "Charged \n";
    Sleep(500);
    std::cout << "1. charge more? \n";
    std::cout << "2. Back to menu \n";
    char choice = getch();
    while (choice != '1' && choice != '2')
    {
        std::cout << "\n chose base on the list";
        choice = getch();
    }
    if (choice == '1')
    {
        shopWalletCharge();
    }
    else if (choice == '2')
    {
        sleepPrint("Back to menu");
        return;
    }
}
void userWalletCharge()
{
    system("cls");
    std::cout << "Cheghadr mi khahid charge konid?\n";
    long int value;
    std::cin >> value;
    *userWalletAdrress += value;
    system("cls");
    std::cout << "Charged \n";
    Sleep(500);
    std::cout << "1. charge more? \n";
    std::cout << "2. Back to menu \n";
    char choice = getch();
    while (choice != '1' && choice != '2')
    {
        std::cout << "\n chose base on the list";
        choice = getch();
    }
    if (choice == '1')
    {
        userWalletCharge();
    }
    else if (choice == '2')
    {
        sleepPrint("Back to menu");
        return;
    }
}
void deleteProduct()
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
    Sleep(500);
    sleepPrint("Back to menu");
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
        Sleep(1500);
        sleepPrint("Back to menu");
        return;
    }
    for (int i = 0; i <= products.size(); i++)
    {
        if (name == products[i].name)
        {
            system("cls");
            std::cout << "Found! \n"
                      << std::endl;
            std::cout << "Name: " << products[i].name << std::endl;
            std::cout << "Price: " << products[i].price << std::endl;
            std::cout << "Mojody: " << products[i].mojody << std::endl;
            break;
        }
    }

    std::cout << "Not found, 404 \n";
    std::cout << "\n1. Search more\n";
    std::cout << "2. Back to menu\n";
    char choice = getch();
    while (choice != '1' && choice != '2')
    {
        choice = getch();
    }
    if (choice == '1')
    {
        search();
    }
    else if (choice == '2')
    {
        sleepPrint("Back to menu");
        return;
    }
    Sleep(1500);
    sleepPrint("Back to menu");
    return;
}

void show()
{
    int size = products.size();
    if (size == 0)
    {
        system("cls");
        std::cout << std::endl
                  << "There is not any product" << std::endl;
        return;
    }
    system("cls");
    for (int i = 0; i < size; i++)
    {
        std::cout << "Product " << i + 1 << std::endl;
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
                  << "There is not any product in shop" << std::endl;
        Sleep(1500);
        sleepPrint("Back to menu");
        return;
    }
    system("cls");
    for (int i = 0; i < size; i++)
    {
        std::cout << "Product " << i + 1 << std::endl;
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

            // if(item.productName.find(products[i].name)){
            //     std::cout<<"you already have this product in your cart";
            //     Sleep(3000);
            //     return;
            // }
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
            system("cls");
            std::cout << "Added to your cart\n";
            Sleep(1000);
            std::cout << "1. Do you want to add more product to your cart? \n";
            std::cout << "2. Back to menu \n";
            char choice = getch();
            while (choice != '1' && choice != '2')
            {
                std::cout << "chose base on the list\n";
                choice = getch();
            }
            if (choice == '1')
            {
                addToCart();
            }
            else if (choice == '2')
            {
                return;
            }
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
    system("cls");
    if (cart.totalPrice == 0)
    {
        std::cout << "You do not have any product in your cart";
        Sleep(1000);
        sleepPrint("Back to menu");
        return;
    }
    std::cout << "The products in your cart:\n";
    for (int i = 0; i < cart.items.size(); i++)
    {
        std::cout << i + 1 << "." << cart.items[i].productName << std::endl;
        std::cout << "    " << "price:" << cart.items[i].price << std::endl;
    }
    std::cout << "press enter to go to menu";
    char chert = getch();
    while (chert != ' ')
    {
        chert = getch();
    }

    return;
}

void checkout()
{
    system("cls");
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
        std::cout << "the post bring your baste to your home\n";
        Sleep(2500);
        sleepPrint("Back to menu");

        return;
    }
}
void menu()
{
    system("cls");
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
                std::cout << "\n------ menu ------\n";
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
                    deleteProduct();
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
        system("cls");

        do
        {
            std::cout << "\n------ menu ------\n";
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