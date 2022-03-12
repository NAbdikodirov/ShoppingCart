//P01ShoppingCart 
//  The program imitates the shopping cart programs like Walmart, where
//  customers can add products as they wish and process several steps to
//  complete purchases.
//Nurillo Abdikodirov

#include <iostream>
#include "ShoppingCart.cpp"

using namespace std;

// declare function prototypes
char getMenuChoice();
void processMenuChoice(char, ShoppingCart &);

// main function
int main()
{
    // required variables
    string custName;
    char choice;

    // display caption
    cout << "**** Shopping Cart ****\n"
         << endl;

    // input customer's name
    cout << "Enter customer's name: ";
    getline(cin, custName);

    cout << endl;

    // create an object of ShoppingCart
    ShoppingCart sc(custName);

    // display the customer's name and current date
    cout << "Customer Name: " << sc.getCustomerName() << "\tToday's Date: " << sc.getCurrentDate() << endl;

    // input user's choice by invoking the getMenuChoice() function
    choice = getMenuChoice();

    // loop till the user selects to quit
    while (choice != 'q')
    {
        cout << endl;
        // process the user's choice by invoking the processMenuChoice()
        processMenuChoice(choice, sc);
        // input the user's choice again
        choice = getMenuChoice();
    }

    return 0;
}

// function to input the user's choice from the menu
char getMenuChoice()
{
    // required variables
    string menuOptions = "adcpoq";
    char choice = ' ';
    size_t index;

    // display the menu
    cout << "\n-- Online Shopping Menu --" << endl;
    cout << "\ta - Add item to cart\n\td - Remove item from cart" << endl;
    cout << "\tc - Change item quantity\n\tp - Change item price" << endl;
    cout << "\to - Output shopping cart\n\tq - Quit" << endl;

    do
    {
        // input the user's choice
        cout << "Enter your choice: ";
        cin >> choice;

        // check if the choice is valid
        index = menuOptions.find(choice);

        // if not then display an invalid message
        if (index == string::npos)
            cout << "Invalid choice!" << endl;
    } while (index == string::npos); // loop till a valid choice is entered

    // return the validated choice
    return choice;
}

// function to process the choice entered by the user
void processMenuChoice(char choice, ShoppingCart &theCart)
{
    // required variables
    string name = "";
    double price = 0.0;
    int quantity = 0;

    // switch the user's choice
    switch (choice)
    {
        // if the user chooses to add an item to the cart
    case 'a':
    {
        // input the item's name, quantity and price
        cout << "Enter item name: ";
        cin >> name;
        cout << "Enter item price: ";
        cin >> price;
        cout << "Enter item quantity: ";
        cin >> quantity;
        // create an Item object with the entered details
        Item item(name, price, quantity);
        // add the item to the cart by invoking the additemToCart() function
        theCart.addItemToCart(item);
    }
    break;

    // if the user chooses to delete an item from the cart
    case 'd':
    {
        // input the item's name
        cout << "Enter item name: ";
        cin >> name;
        // invoke the removeItemFromCart() function to remove the given item from the cart
        theCart.removeItemFromCart(name);
    }
    break;

    // if the user chooses to change the quantity of an item
    case 'c':
    {
        // input the item's name and new quantity
        cout << "Enter item name: ";
        cin >> name;
        cout << "Enter the new quantity: ";
        cin >> quantity;
        // invoke the changeItemQuantity() function to change the given item's quantity
        theCart.changeItemQuantity(name, quantity);
    }
    break;

    // if the user chooses to change the price of an item
    case 'p':
    {
        // input the item's name and new price
        cout << "Enter item name: ";
        cin >> name;
        cout << "Enter the new price: ";
        cin >> price;
        // invoke the changeItemPrice() function to change the given item's price
        theCart.changeItemPrice(name, price);
    }
    break;

    // if the user chooses to output the cart information
    case 'o':
        // invoke the outputCartInfo() function to display each item's details
        theCart.outputCartInfo();
        break;
    }
}