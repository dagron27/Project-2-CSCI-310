/* This program allows a user to add, remove, and modify a virtual ShoppingCart. 
@file location: /home/STCLOUDSTATE/mm8755tt/PROJECTS/PROJECT_2/project2.cpp
@Author: Daniel Leone. CSCI 301-Section 54
@StarID: mm8755tt
@Due Date: Jul 3, 2023
@Instructor: Dr. Jie Meichsner

The user will add items to their shopping cart. The program will take the user input 
in the form of "name price quantity" to create an item to add to the user's shopping 
cart. It will continue to prompt the user to add items until the user decides not to 
add anymore. The user can add up to a maximum of 6 items, after which items can be 
input but will not be added to the shopping cart. The list of items in the shopping 
cart, as well as the total price, will be displayed for review.

After review, the user will be given the option to modify their cart. If he or she
chooses to modify, the program will prompt the user to either add items, remove items, 
or change quantities of existing items. The program will inform the user if he or 
she tries to remove or modify an item that is not in the cart. Once all modifications 
are complete, the updated list of items in the shopping cart, as well as the updated 
total price, will be displayed with a "Thanks for shopping..." message. 
*/

#include "ShoppingCart.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Prototypes
void lineBorder();							// set number of lines for display top or bottom border
void displayTotal(ShoppingCart& cart);		// displays shopping cart contents and total price
void menuAddToCart(ShoppingCart& cart);		// initial menu for user to add items to shopping cart
void menuModifyOrder(ShoppingCart& cart);	// modify menu after user reviews initial order


int main()
{
	ShoppingCart sCart;
	cout << "\nWelcome to XXX SHOPPING CENTER." << endl;
	// Allows user to do initial adding to his or her shopping cart
	menuAddToCart(sCart);

	// Display initial order
	cout << "Here is your order: " << endl;
	lineBorder();
	displayTotal(sCart);
	lineBorder();
	cout << endl << endl;

	// After review, allows user to modify shopping cart contents if desired
	menuModifyOrder(sCart);

	// Display updated order
	cout << "Here is your updated order: " << endl;
	lineBorder();
	cout << "You have ordered the following items: " << endl;
	displayTotal(sCart);
	cout << "Thanks for shopping in XXX SHOPPING CENTER." << endl;
	lineBorder();
	cout << endl << endl;

	return 0;
};

// initial menu for user to add items to shopping cart
void menuAddToCart(ShoppingCart& cart){
	Item tmpItem;

	cout << "Enter the item you selected as the following order: " << endl;
	cout << "name unitPrice quantity" << endl;
	cout << "(Name can not contain any space. Otherwise errors happen!)" << endl;	
	// loop utilized for the adding phase
	bool adding = true;
	while(adding)
	{
		// Adds item to shopping cart
		cout << "--> "; cin >> tmpItem;
		cart.add(tmpItem);

		// loop used for user selection after adding an item
		bool exit = false;
		while(!exit){
			char selection;
			cout << "Want to continue y/n-->"; cin >> selection;
			if(selection=='y'){
				exit = true;		// breaks out of selection loop
			}else if(selection=='n'){
				adding = false;		// breaks out of main loop
				exit = true;		// breaks out of selection loop
			}else{
				cout << "Invalid selection." << endl;
				continue;
			}
			cout << endl;
		}
	}
}	

// allows the user to add an item to cart during order modification
void modifyAdd(ShoppingCart& cart){
	cout << "Enter the item to add as the following order: " << endl;
	cout << "name unitPrice quantity" << endl;

	Item tmpItem;
	cout << "--> "; cin >> tmpItem;
	cart.add(tmpItem);
	cout << "The item has been added." << endl;
}

// allows the user to remove an item, if item is in cart, during order modification
void modifyRemove(ShoppingCart& cart){
	cout << "Enter the item to remove as the following order: " << endl;
	cout << "name unitPrice quantity" << endl;

	Item tmpItem;
	cout << "--> "; cin >> tmpItem;
	if(cart.remove(tmpItem)){
		cout << "The item has been removed." << endl;
	}else{
		cout << "No such item in your shopping cart!" << endl;
	}
}

// allows the user to modify an item quantity, if item is in cart, during order modification
void modifyChangeQuantity(ShoppingCart& cart){

	Item tmpItem;
	cout << "Enter the item to change as the following order: " << endl;
	cout << "name unitPrice quantity" << endl;
	cout << "--> "; cin >> tmpItem;
	
	if(cart.contains(tmpItem)){	// check to see if the item is in the cart
		bool entering = true;
		while(entering){
			int newQuantity;
			cout << "Enter a new quantity --> "; cin >> newQuantity;
			
			// if newQuantity is greater than 0, removes old item with old quantity and adds tmpItem with updated quantity
			if(newQuantity > 0){
				cart.remove(tmpItem);
				tmpItem.setQuantity(newQuantity);
				cart.add(tmpItem);
				cout << "The quantity has been modified." << endl;
				entering = false;	// breaks entering loop
			}else{
				cout << newQuantity << " is not a valid input." << endl;
			}
		}
	}else{
		cout << "No such item in your shopping cart!" << endl;		
	}
}

// menu to modify cart after review
void menuModifyOrder(ShoppingCart& cart){
	// functions used: modifyAdd(), modifyRemove(), modifyChangeQuantity()
	bool modifyOrder = true;
	while(modifyOrder){
		char selection;
		cout << "Want to modify your order? y/n-->"; cin >> selection;
		if(selection=='y'){
			int choice;
			cout << "What do you want? Enter 1: add 2: remove 3: change quantity\n--> "; cin >> choice;
			if(choice==1){
				modifyAdd(cart);
			}
			else if(choice==2){
				modifyRemove(cart);
			}
			else if(choice==3){
				modifyChangeQuantity(cart);
			}
			else{
				cout << "Invalid selection." << endl;
			}
		}else if(selection=='n'){
			modifyOrder = false;	// breaks main loop
		}else{
			cout << "Invalid selection." << endl << endl;
			continue;
		}
		cout << endl;
	}	
}

// creates a line for console display
void lineBorder(){
	for(int i = 0; i<50; i++)
		{ cout << "-"; }	
}

// display shopping cart contents and total price
void displayTotal(ShoppingCart& cart){
	// Library facilities used: iomanip
	// setw() keeps columns aligned with item display
	cout << endl << setw(20) << left << "Name"<< setw(20) << left <<"Unit_Price"<< setw(20) << left << "Quantity" << endl;

	// creates a vector<Item> set by copying shopping cart contents via Bag<Item>::toVector()
	// iterates through contents and displays to console
	vector<Item> v = cart.toVector();
	for(int i = 0; i < cart.getCurrentSize(); i++){
		cout << v[i] << endl;
	}
	
	// display total price
	cout << "The total charge is $" << cart.getTotalPrice() << endl;
}