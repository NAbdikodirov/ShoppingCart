//P01ShoppingCart 
//  The program imitates the shopping cart programs like Walmart, where
//  customers can add products as they wish and process several steps to
//  complete purchases.
//Nurillo Abdikodirov

#include "ShoppingCart.h"

// define parameterized constructor
ShoppingCart::ShoppingCart(string name)
{
    // initialize the customer's name and current date
    this->customerName = name;
    this->currentDate = getDateString();
}

// define getter for the customer's name
string ShoppingCart::getCustomerName() const { return this->customerName; }
// define getter for the current date
string ShoppingCart::getCurrentDate() const { return this->currentDate; }

// function that returns the size of the cart
int ShoppingCart::getItemCount() const { return cart.size(); }

// function that returns the index of an item in the cart
int ShoppingCart::findItemInCart(string name)
{
    // required variables
    bool found = false;
    int i;

    // loop through the cart items
    for (i = 0; i < cart.size(); i++)
    {
        // if the given item is found in the cart
        if (cart[i].getItemName().compare(name) == 0)
        {
            // set found to true and break the loop
            found = true;
            break;
        }
    }

    // if the item is found then return the index of that item
    if (found)
        return i;
    // else return the size of the cart
    else
        return cart.size();
}

// a function to add an item to the cart
void ShoppingCart::addItemToCart(Item item)
{
    // if the item is not present in the cart
    if (findItemInCart(item.getItemName()) >= cart.size())
    {
        // add the item to the cart & display an appropriate message
        cart.push_back(item);
        cout << item.getItemName() << " is added to the cart!" << endl;
    }
    // else display that the item is already present
    else
    {
        cout << item.getItemName() << " is already present in the cart!" << endl;
    }
}

// function to change the quantity of an item present in the cart
void ShoppingCart::changeItemQuantity(string name, int quantity)
{
    // get the given item's index in the cart
    int index = findItemInCart(name);

    // if the item is not present in the cart
    if (index >= cart.size())
    {
        // display an appropriate message
        cout << name << " is not present in the cart!" << endl;
    }
    // else the item is present in the cart
    else
    {
        // invoke the setter for item's quantity and set the new quantity
        cart[index].setItemQuantity(quantity);
        // display an appropriate message
        cout << name << "'s quantity changed to " << quantity << endl;
    }
}

// function to change the price of an item present in the cart
void ShoppingCart::changeItemPrice(string name, double price)
{
    // get the given item's index in the cart
    int index = findItemInCart(name);

    // if the item is not present in the cart
    if (index >= cart.size())
    {
        // display an appropriate message
        cout << name << " is not present in the cart!" << endl;
    }
    // else the item is present in the cart
    else
    {
        // invoke the setter for item's price and set the new price
        cart[index].setItemPrice(price);
        // display an appropriate message
        cout << name << "'s price changed to " << price << endl;
    }
}

// function to remove an item from the cart
void ShoppingCart::removeItemFromCart(string name)
{
    // get the given item's index in the cart
    int index = findItemInCart(name);

    // if the item is not present in the cart
    if (index >= cart.size())
    {
        // display an appropriate message
        cout << name << " is not present in the cart!" << endl;
    }
    else
    {
        // remove the given item from the cart
        cart.erase(cart.begin() + index);
        // display an appropriate message
        cout << name << " is removed from the cart!" << endl;
    }
}

// function to display the cart information
void ShoppingCart::outputCartInfo()
{
    // loop through the items in the cart
    for (Item i : cart)
    {
        // invoke each item's outputItemInfo() function to display its information
        i.outputItemInfo();
        cout << endl;
    }
}