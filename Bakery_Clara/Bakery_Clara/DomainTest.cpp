#include "DomainTest.h"
#include <cassert>
#include"Domain.h"
#include <iostream>

void DomainTest::runAllDomainTests()
{
	test_gettersBakery();
	test_settersBakery();
	test_gettersCostumer();
	test_settersCostumer();
	test_gettersCake();
	test_settersCake();
	std::cout << "Domain tests ended \n";
}

void DomainTest::test_gettersBakery()
{
	Bakery order;
	order.set_calories(1231);
	assert(order.get_calories() == 1231);
	order.set_Id(120);
	assert(order.get_Id() == 120);
	order.set_price(100);
	assert(order.get_price() == 100);
}

void DomainTest::test_settersBakery()
{
	Bakery secondorder;
	secondorder.set_price(230);
	assert(secondorder.get_price() == 230);
	secondorder.set_calories(3000);
	assert(secondorder.get_calories() == 3000);
	secondorder.set_Id(3331);
	assert(secondorder.get_Id() == 3331);
}

void DomainTest::test_gettersCostumer()
{
	BakeryCostumer costumer12;
	costumer12.set_name("Marla Jacobs");
	assert(costumer12.get_name() == "Marla Jacobs");
	costumer12.set_phonenr(07314251);
	assert(costumer12.get_phonenr() == 07314251);
	costumer12.set_CId(12000);
	assert(costumer12.get_CId() == 12000);
}

void DomainTest::test_settersCostumer()
{
	BakeryCostumer costumer13;
	costumer13.set_name("Jackson Wang");
	assert(costumer13.get_name() == "Jackson Wang");
	costumer13.set_phonenr(07122324);
	assert(costumer13.get_phonenr() == 07122324);
	costumer13.set_CId(13000);
	assert(costumer13.get_CId() == 13000);
}

void DomainTest::test_gettersCake()
{
	Cake cake1;
	cake1.set_filling("Vanilla");
	assert(cake1.get_filling() == "Vanilla");
	cake1.set_spoonge("Blue Angel");
	assert(cake1.get_spoonge() == "Blue Angel");
	cake1.set_Ctype("Wedding");
	assert(cake1.get_Ctype() == "Wedding");
}

void DomainTest::test_settersCake()
{
	Cake cake2;
	cake2.set_filling("Chocolate");
	cake2.set_spoonge("Red Velvet");
	cake2.set_Ctype("Birthday");
	
	assert(cake2.get_filling() == "Chocolate");
	assert(cake2.get_spoonge() == "Red Velvet");
	assert(cake2.get_Ctype() == "Birthday");
}




