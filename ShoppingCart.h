#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include "Item.h"
#include "Bag.h"

class ShoppingCart : public Bag<Item>
{
	private:
	/** total price of Items in the ShoppingCart */
		double totalPrice;
	public:
			/** CONSTRUCTORS*/
	/** Default Constructor 
	/* @pre None
	/* @post initializes Bag<Item> default values and sets
	totalPrice to 0.0 by default*/
		ShoppingCart();
		
			/** CONSTANT MEMBER FUNCTIONS*/
	/** returns the total price of Items in the ShoppingCart
	/* @pre None
	/* @post The value returned is the totalPrice of Items in the ShoppingCart.*/	
		double getTotalPrice() const { return totalPrice;}

			/** MODIFICATION MEMBER FUNCTIONS*/
	/** Adds a new entry to this ShoppingCart and adjusts totalPrice.
    /* @param newEntry The object to be added as a new entry.
	/* @pre None
    /* @post  If successful, newEntry is stored in the ShoppingCart and
       the count of items in the bag has increased by 1. The totalPrice
	   is increased by the (price x quantity) of new entry. 
    /* @return  True if addition was successful, or false if not. */
		bool add(const Item& newEntry);

	/** Removes an entry from this ShoppingCart, if possible, and adjusts totalPrice.
    /* @param anEntry The object to be removed.
	/* @pre Desired item for removal is in ShoppingCart.
    /* @post If successful, anEntry is removed from the ShoppingCart and
       the count of items in the bag has decreased by 1. The totalPrice
	   is decreased by the (price x quantity) of an entry. 
    /* @return  True if removal was successful, or false if not. */		
		bool remove(const Item& anEntry);
};

#include "ShoppingCart.cpp"
#endif