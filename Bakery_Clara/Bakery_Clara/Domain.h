#pragma once
#include <string>
#include <ostream>


using namespace std;

class Bakery
{
private:
	float calories;
	float price;
	int id_order;
public:
	//default constructor for base class
	Bakery();

	//constructor with parameters
	//parameter-> calories: how many calories does it have
	//parameter-> price: the price of the order
	//parameter->id_order: the id of the order
	Bakery(float calories, float price, int id_order);

	//display method
	virtual string to_String(); 

	//getter for the private fields
	float get_calories() const;
	float get_price() const;
	int get_Id() const;

	//setter for the private fields
	void set_calories(float calories);
	void set_price(float price);
	void set_Id(int id_order);
};


class BakeryCostumer : public Bakery
{
private:
	string costumer_name;
	int phone_nr;
	int id_costumer;
public:
	//default constructor for the direved class
	BakeryCostumer();

	//constructor with parameters
	//parameter-> name:the name of the costumer
	//parameter-> phone_nr: the number of the costumer
	//parameter->id_costumer: the id of the costumer
	BakeryCostumer(float calories, float id_order, int price, string costumer_name, int phone_nr, int id_costumer);

	//display method were we use polymorphism to override the base class visrtual function
	string to_String() override;

	//getter for the private fields
	string get_name() const;
	int get_phonenr()const;
	int get_CId() const;

	//setter for the private fields
	void set_name(string costumer_name);
	void set_phonenr(int phone_nr);
	void set_CId(int id_costumer);
};

class Cake : public Bakery
{
public:
	//default constructor for the derived class
	Cake();

	//constructor with parameters
	//parameter-> filling:the type of filling for the cake
	//parameter-> spoonge_type: the type of spoonge for the cake
	//parameter->cake_type: the type of cake
	Cake(float calories, float id_order, int price, string filling, string spoonge_type, string cake_type);

	//display method were we use polymorphism to override the base class visrtual function
	string to_String()override;


	//getter for the private fields
	string get_filling()const;
	string get_spoonge()const;
	string get_Ctype() const;
	

	//setter for the private fields
	void set_filling(string filling);
	void set_spoonge(string spoonge_type);
	void set_Ctype(string cake_type);

private:
	string filling;
	string spoonge_type;
	string cake_type;
};

