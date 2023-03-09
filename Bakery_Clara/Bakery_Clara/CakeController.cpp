#include "CakeController.h"
# include<iostream>

BakeryController::BakeryController()
{
}

BakeryController::BakeryController(BakeryRepository& repo)
{
	this->bakery_controller = repo;
}

bool BakeryController::removeOrder_controller(int id)
{
	Bakery* bk = bakery_controller.removeOrder(id);
	if (bk)
	{
		UndoStack.push(std::make_pair(ActionType::REMOVE, bk));
	}
	return true;
}

void BakeryController::addOrder_controller(Bakery* bk)
{
	this->bakery_controller.addOrder(bk);
	UndoStack.push(std::make_pair(ActionType::ADD, bk));
}

void BakeryController::updateOrder_controller(int Id, int new_cal, int new_price, int new_id)
{
	this->bakery_controller.updateOrderbyId(Id, new_cal, new_price, new_id);
}

void BakeryController::displayByPriceLower(int price)
{
	this->bakery_controller.displayByPriceLower(price);
}

bool BakeryController::UNDO()
{
	//ADD
	if (this->UndoStack.top().first == ActionType::ADD)
	{
		this->RedoStack.push(std::make_pair(ActionType::ADD, this->UndoStack.top().second));
		this->UndoStack.pop();
		this->bakery_controller.removeOrder(this->RedoStack.top().second->get_Id());
		return true;
	}
	//REMOVE
	else
		if (this->UndoStack.top().first == ActionType::REMOVE)
		{
			this->RedoStack.push(std::make_pair(ActionType::REMOVE, this->UndoStack.top().second));
			this->UndoStack.pop();
			this->bakery_controller.addOrder(this->RedoStack.top().second);
			return true;
		}
		else
			if (this->UndoStack.size() == 0)
				return false;
}

bool BakeryController::REDO()
{
	//ADD
	if (this->RedoStack.top().first == ActionType::ADD)
	{
		this->UndoStack.push(std::make_pair(ActionType::ADD, this->RedoStack.top().second));
		this->RedoStack.pop();
		this->bakery_controller.addOrder(this->UndoStack.top().second);
		return true;
	}
	//REMOVE
	else
		if (this->RedoStack.top().first == ActionType::REMOVE)
		{
			this->UndoStack.push(std::make_pair(ActionType::REMOVE, this->RedoStack.top().second));
			this->RedoStack.pop();
			this->bakery_controller.removeOrder(this->UndoStack.top().second->get_Id());
			return true;
		}
		else
			if (this->RedoStack.size() == 0)
			{
				return false;
			}
	return false;
}

string BakeryController::to_string()
{
	return bakery_controller.to_string();
}

void BakeryController::display()
{
	cout << bakery_controller;
}

