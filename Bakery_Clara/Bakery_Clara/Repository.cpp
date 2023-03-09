#include "Repository.h"
#include "Domain.h"
#include <iostream>

void BakeryRepository::addOrder(Bakery* bk)
{
	order_repo.push_back(bk);
}

Bakery* BakeryRepository::removeOrder(int id) //pop_back()
{
	Bakery* bakery = nullptr;
	auto index = find_if(order_repo.begin(), order_repo.end(), [id](Bakery* bakery)->bool { return bakery->get_Id() == id; });
	if (index != order_repo.end())
	{
		bakery = *index;
		order_repo.erase(index);
	}
	return bakery;
}

void BakeryRepository::updateOrderbyId(int Id, int new_cal, int new_price, int new_id)
{
	for (int i = 0; i <= size(order_repo); i++)
		if (order_repo[i]->get_Id() == Id)
		{
			this->order_repo[i]->set_calories(new_cal);
			this->order_repo[i]->set_price(new_price);
			this->order_repo[i]->set_Id(new_id);
		}
	
}

void BakeryRepository::displayByPriceLower(int price)
{
	int ok = 0;
	for(int i=0;i<order_repo.size();i++)
		if (order_repo[i]->get_price() < price)
		{
			cout<<order_repo[i];
			ok++;
		}
	if (ok == 0)
		cout << "There are no orders with price smaller then:" << price << "!!" << endl;
	
}

string BakeryRepository::to_string()
{
	string result = "";
	for (auto it : order_repo)
	{
		result += it->to_String() + "\n";
	}
	return result;
}



std::ostream& operator<<(std::ostream& stream, BakeryRepository orderepo)
{
	
	for (unsigned int i = 0; i < orderepo.order_repo.size(); i++)
	{
		stream << orderepo.order_repo[i]->to_String();
	}
	return stream;
}
