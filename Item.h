#ifndef ITEM_H
#define ITEM_H

#include <iostream>

using namespace std;

class Item
{
	private:
	/** name of this Item */
		string name;
	/** price of this Item */
		double unitPrice;
	/** quantity of this Item */
		int quantity;
	public:
			/** CONSTRUCTORS*/
	/** Default Constructor 
	/* @pre None
	/* @post sets the Item name = " ", price = 0.0, quantity = 0 by default*/
		Item();

	/** Constructor with parameters 
	/* @param initName the name of the Item
	/* @param initPrice the price of the Item
	/* @param initQuantity the quantity of the Item
	/* @pre None
	/* @post sets the Item to(initName, initPrice, initQuantity)*/		
		Item(string initName, double initUnitPrice, int initQuantity);

			/** MODIFICATION MEMBER FUNCTIONS*/
	/** set the Item's name to a new value
	/* @param updateName the value of the Item's name
	/* @pre None
	/* @post Item's name changed to(updateName)*/
		void setName(string updateName);

	/** set the Item's price to a new value
	/* @param updatePrice the value of the Item's price
	/* @pre None
	/* @post Item's price changed to(updatePrice)*/
		void setUnitPrice(double updateUnitPrice);

	/** set the Item's quantity to a new value
	/* @param updateQuantity the value of the Item's quantity
	/* @pre None
	/* @post Item's quantity changed to(updateQuantity)*/
		void setQuantity(int updateQuantity);

			/** CONSTANT MEMBER FUNCTIONS*/
	/** returns the name of the item
	/* @pre None
	/* @post The value returned is the name of the Item.*/	
		string getName() const {return name;};

	/** returns the price of the item
	/* @pre None
	/* @post The value returned is the price of the Item.*/
		double getUnitPrice() const {return unitPrice;};

	/** returns the quantity of the item
	/* @pre None
	/* @post The value returned is the quantity of the Item.*/
		int getQuantity() const {return quantity;};

	/** compares two Items by name and price and returns bool value
/* @param item1 is the lhs Item for comparison	
/* @param item2 is the rhs Item for comparison
/* @pre None
/* @post item1 and item2 are compared by both name and price.
If name and price match, function returns true; Else, function returns false. */
		bool operator==(const Item& item2) const;

			/** FRIEND NONMEMBER FUNCTIONS*/
	/** writes the string name, double price and int quantity of an Item to the istream
	/* Friend Class to Item
	/* @param ins is the istream 
	/* @param target is a Item
	/* @pre None
	/* @post the name, price, and quantity of target are modified by user input
	and written to ins. The return value is the istream ins.*/	
		friend istream& operator>>(istream& ins, Item& target);

	/** writes the name, price, and quantity to the ostream		
/* @param outs is the ostream, 
/* @param source is a fraction
/* @pre None
/* @post the name, the price, and the quantity of source have been 
	written to outs. The return value is the ostream outs.*/
		friend ostream& operator<<(ostream& outs, Item& source);
};

#include "Item.cpp"
#endif