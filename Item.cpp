//P01ShoppingCart 
//  The program imitates the shopping cart programs like Walmart, where
//  customers can add products as they wish and process several steps to
//  complete purchases.
//Nurillo Abdikodirov

#include "Item.h"

// define the parameterized constructor
Item::Item(string name, double price, int quantity)
{
    // initialize all the data members
    this->itemName = name;
    this->itemPrice = price;
    this->quantity = quantity;
}

// define setters for all the data members
void Item::setItemName(string name) { this->itemName = name; }
void Item::setItemPrice(double price) { this->itemPrice = price; }
void Item::setItemQuantity(int quantity) { this->quantity = quantity; }

// define getters for all the data members
string Item::getItemName() const { return this->itemName; }
double Item::getItemPrice() const { return this->itemPrice; }
int Item::getItemQuantity() const { return this->quantity; }

// define a function that displays the item's information
void Item::outputItemInfo()
{
    cout << "Item Name: " << itemName << "\nItem Price: " << itemPrice << "\nItem Quantity: " << quantity << endl;
}