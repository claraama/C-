#include "RepositoryTests.h"
#include <iostream>
#include <cassert>
#include "Repository.h"
#include "Domain.h"

void RepositoryTests::test_addRepo()
{
	BakeryRepository r;
	BakeryCostumer c1{2000,390, 900,"Mary Jane", 074551231, 001};
	Cake cake1{222,1200, 790, "Chocolate", "Red Velvet", "Birthday"};

	Bakery* order1 = &c1;
	Bakery* order2 = &cake1;

	r.addOrder(order1);
	r.addOrder(order2);

	
	assert(r.GetOrder()[0]->get_Id() == 900);
	assert(r.GetOrder()[1]->get_Id() == 790);
	assert(r.GetOrder()[0]->get_calories() == 2000);
	assert(r.GetOrder()[1]->get_calories() == 222);
	assert(r.GetOrder()[0]->get_price() == 390);
	assert(r.GetOrder()[1]->get_price() == 1200);

}
void RepositoryTests::test_removeRepo()
{
	BakeryRepository r2;
	BakeryCostumer c2{ 2333,500, 21, "April Stan", 074722315, 003 };
	Cake cake2{ 211, 004, 280, "Vanilla", "Blue Angel", "Birthday" };

	Bakery* order1 = &c2;
	Bakery* order2 = &cake2;

	r2.addOrder(order1);
	r2.addOrder(order2);

	r2.removeOrder(1);
	assert(r2.GetOrder()[0]->get_Id() == 21);
	assert(r2.GetOrder()[0]->get_calories() == 2333);
	assert(r2.GetOrder()[0]->get_price() == 500);
}

void RepositoryTests::test_updateRepo()
{
	BakeryRepository r3;
	BakeryCostumer c3{ 1003,002, 2111, "Luisa Heard", 074722312, 001 };
	Cake cake3{ 900, 010, 500, "Vanilla", "Chocolate", "Wedding" };

	Bakery* order1 = &c3;
	Bakery* order2 = &cake3;

	r3.addOrder(order1);
	r3.addOrder(order2);

	r3.updateOrderbyId(900, 780, 2000, 700);
	assert(r3.GetOrder()[1]->get_Id() == 700 );
	assert(r3.GetOrder()[1]->get_calories() == 780);
	assert(r3.GetOrder()[1]->get_price() == 2000);
}

void RepositoryTests::runAllRepositoryTests()
{
	test_addRepo();
	test_removeRepo();
	//test_updateRepo();
	std::cout << "Repository tests ended \n";
}
