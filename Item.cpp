/** FILE: Item.cpp */
/** CLASS IMPLEMENTED: Item (See Item.h for documentation.) */

#include <iostream>
#include <iomanip>
#include "Item.h"

using namespace std;

Item::Item()
{
	name = " ";		// Default Constructor
	unitPrice = 0.00;
	quantity = 0;
}

Item::Item(string initName, double initUnitPrice, int initQuantity)
{
	name = initName;			// Constructor sets name to string value
	unitPrice = initUnitPrice;		// Constructor sets price to double value
	quantity = initQuantity;	// Constructor sets quantity to int value
}

void Item::setName(const string updateName)
{
	name = updateName;
}

void Item::setUnitPrice(const double updateUnitPrice)
{
	unitPrice = updateUnitPrice;
}

void Item::setQuantity(const int updateQuantity)
{
	quantity = updateQuantity;
}

bool Item::operator==(const Item& item2) const
{
	// if lhs == rhs, return true
	return
		(name == item2.getName())
		&&
		(unitPrice == item2.getUnitPrice());
}

//NON-MEMBER FRIEND FUNCTIONS
istream& operator>>(istream& ins, Item& target)
{
	// Library facilities used: iostream
	// Friend of: Item class
	cin >> target.name >> target.unitPrice >> target.quantity;
	return ins;
} 

ostream& operator<<(ostream& outs, Item& source)
{
	// Library facilities used: iostream and iomanip
	// Friend of: Item class
	outs  << setw(20) << left << source.name << "$" << setw(20) << left << source.unitPrice << setw(20) << left << source.quantity;
	return outs;
}
