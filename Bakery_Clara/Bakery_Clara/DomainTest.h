#pragma once
class DomainTest
{
private:
	//base class tests
	static void test_gettersBakery();
	static void test_settersBakery();

	//derved class Bakery Costumer tests
	static void test_gettersCostumer();
	static void test_settersCostumer();
	
	//derived class Cake tests
	static void test_gettersCake();
	static void test_settersCake();
	
public:
	static void runAllDomainTests();
};

