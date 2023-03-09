#pragma once
#include <string>
#include <ostream>
#include "Domain.h"
#include "Repository.h"
#include<stack>

enum class ActionType {
	ADD,
	REMOVE
};

class BakeryController
{
private:
	BakeryRepository bakery_controller;
	std::stack<pair<ActionType, Bakery*>>UndoStack;
	std::stack<pair<ActionType, Bakery*>>RedoStack;
public:
	//Default constructor
	BakeryController();

	//Constructor with parameter
	//parameter repo -> the object we store the object in
	BakeryController(BakeryRepository& repo);

	//removes an Order from the repository
	//paramter id-> the id of the order we want to remove
	bool removeOrder_controller(int id);

	// adds an order to the repository
	//parameter bk-> the order we want to add to the repository
	void addOrder_controller(Bakery* bk);


	//updates an order based on a given id
	//parametr Id-> the given Id for which the update will be made
	//parametr new_id-> the new id which will be the updated one
	//parametr new_cal->the new calorie which will be the updated one
	//parametr new_price-> the new price which will be the updated one
	void updateOrder_controller(int Id, int new_cal, int new_price, int new_id);

	//displays the orders that have the price bellow a given one
	//parameter price-> the price by which the filtering is made
	void displayByPriceLower(int price);

	// Displays all the objects stored in the repository
	std::vector<Bakery*> getController() { return bakery_controller.GetOrder();}

	//undo redo operations

	/// If the action was ADD, the order added will be removed
	/// If the action was REMOVE, the order removed will be added back 
	bool UNDO(); //undo the last performed operation


	// If the action was ADD, the order which was removed by the undo() will be added again to our repo
	//If the action was REMOVE, the order which was added after the undo() will be removed again from our repo
	bool REDO(); //redo the last performed operation

	//display method
	string to_string();
	void display();

	
};

