/** FILE: ShoppingCart.cpp */
/** CLASS IMPLEMENTED: ShoppingCart inherited from Box<Item> (See ShoppingCart.h for documentation.) */

#include "ShoppingCart.h"

ShoppingCart::ShoppingCart()
{
	Bag<Item>();		// Default constructor
	totalPrice = 0.0;
}

bool ShoppingCart::add(const Item& newEntry)
{
	/** Utilize superclass Bag<Item>::add() function
		Check if Item can be added to ShoppingCart
		If return true, add an item to ShoppingCart */
	if(Bag<Item>::add(newEntry))		
	{
		// If can add, add to current totalPrice by (newEntry's price x newEntry's quantity)
		totalPrice += (newEntry.getUnitPrice() * newEntry.getQuantity());	
	}
}

bool ShoppingCart::remove(const Item& anEntry)
{
	/** Utilize superclass Bag<Item>::remove() function
		Check if Item is contained in ShoppingCart
		If return true, remove Item from ShoppingCart */
	if(Bag<Item>::remove(anEntry))										
	{
		// If can remove, subtract from current totalPrice by (anEntry's price x anEntry's quantity)
		// Assumes user input correct quantity */
		totalPrice -= (anEntry.getUnitPrice() * anEntry.getQuantity());		
	}
}
