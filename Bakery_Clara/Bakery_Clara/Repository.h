#pragma once
#include "Domain.h"
#include <vector>
class BakeryRepository
{
private:
	std::vector<Bakery*> order_repo;
public:
	// Adds an element of type bakery to the repository
	//parameter bk-> the order we want to add to our repo
	void addOrder(Bakery* bk);

	//Removes an order by the id from the repository
	//parameter id-> the order we want to remove from our repo
	Bakery* removeOrder(int id);

	//Updates the order by a given id
	void updateOrderbyId(int Id, int new_cal, int new_price,int new_id);

	//Displays all the orders that have a price lower than the given one
	//parameter price-> the value we compare the orders with
	void displayByPriceLower(int price);

	//gets all orders in the repo
	std::vector<Bakery*> GetOrder() { return order_repo; }

	//display method
	friend std::ostream& operator<<(std::ostream& stream, BakeryRepository orderepo);
	string to_string();

};

