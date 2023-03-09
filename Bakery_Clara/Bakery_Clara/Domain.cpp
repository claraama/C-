#include "Domain.h"

Bakery::Bakery()
{
	this->calories = 0;
	this->id_order = 0;
	this->price = 0;
}

Bakery::Bakery(float calories, float price, int id_order)
{
	this->calories = calories;
	this->price = price;
	this->id_order = id_order;
}

string Bakery::to_String()
{
	return "The cake has calories: " + std::to_string(this->calories)+ "with cake id order:" + std::to_string(this->id_order) + " and price: " + std::to_string(this->price);
}

/*

bool Cake::operator==(const Cake &other) const
{
	return price==other.price && id_order=other.id_order && cake_type==other.cake_type;
}
*/

/*

bool Cake::operator!=(const Cake& other) const
{
	return !(other == *this);
}
*/

float Bakery::get_calories() const
{
	return this->calories;
}

float Bakery::get_price() const
{
	return this->price;
}

int Bakery::get_Id() const
{
	return this->id_order;
}

void Bakery::set_calories(float calories)
{
	this->calories = calories;
}

void Bakery::set_price(float price)
{
	this->price = price;
}

void Bakery::set_Id(int id_order)
{
	this->id_order = id_order;
}


BakeryCostumer::BakeryCostumer()
{
	this->costumer_name = "";
	this->phone_nr = 0;
	this->id_costumer = 0;
}

BakeryCostumer::BakeryCostumer(float calories, float id_order, int price, string costumer_name, int phone_nr, int id_costumer):
Bakery(calories, id_order, price)
{
	this->costumer_name = costumer_name;
	this->phone_nr = phone_nr;
	this->id_costumer = id_costumer;
}

string BakeryCostumer::to_String()
{
	string rep = Bakery::to_String();
	rep += this->costumer_name;
	rep += this->phone_nr;
	rep += this->id_costumer;
	return rep;
}

string BakeryCostumer::get_name() const
{
	return this->costumer_name;
}

int BakeryCostumer::get_phonenr() const
{
	return this->phone_nr;
}

int BakeryCostumer::get_CId() const
{
	return this->id_costumer;
}

void BakeryCostumer::set_name(string costumer_name)
{
	this->costumer_name = costumer_name;
}

void BakeryCostumer::set_phonenr(int phone_nr)
{
	this->phone_nr = phone_nr;
}

void BakeryCostumer::set_CId(int id_costumer)
{
	this->id_costumer = id_costumer;
}

Cake::Cake()
{
	this->filling = "";
	this->spoonge_type = "";
	this->cake_type = "";
}

Cake::Cake(float calories, float id_order, int price, string filling, string spoonge_type, string cake_type):
	Bakery(calories, id_order, price)
{
	this->filling = filling;
	this->spoonge_type = spoonge_type;
	this->cake_type = cake_type;
}

string Cake::to_String()
{
	string repr = Bakery::to_String();
	repr += this->filling;
	repr += this->spoonge_type;
	repr += this->cake_type;
	return repr;
}

string Cake::get_filling() const
{
	return this->filling;
}

string Cake::get_spoonge() const
{
	return this->spoonge_type;
}

string Cake::get_Ctype() const
{
	return this->cake_type;
}

void Cake::set_filling(string filling)
{
	this->filling = filling;
}

void Cake::set_spoonge(string spoonge_type)
{
	this->spoonge_type = spoonge_type;
}

void Cake::set_Ctype(string cake_type)
{
	this->cake_type = cake_type;
}

