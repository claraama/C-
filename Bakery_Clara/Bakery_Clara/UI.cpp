# include<iostream>
#include "Domain.h"
#include "Repository.h"
#include"CakeController.h"
#include "DomainTest.h"
#include "RepositoryTests.h"


using namespace std;

void displayMenu() {
	cout << "Please select your option:" << endl;
	cout << "1.  ADD a new order to the bakery" << endl;
	cout << "2.  DISPLAY all the bakery offers" << endl;
	cout << "3.  REMOVE by ID Order" << endl;
	cout << "4.  EDIT by ID Order" << endl;
	cout << "5.  UNDO last operation" << endl;
	cout << "6.  REDO last operation" << endl;
	cout << "7.  FILTER by price" << endl;
	cout << "8.  quit" << endl;
}

void start() {
	

	BakeryRepository Repo;
	BakeryCostumer c1{2000,001, 1232, "Andrew Lane", 074551230, 003 };
	Cake cake1{ 2300, 003, 1000, "Cream Chesse", "Red Velvet", "Birthday" };

	Bakery* order1 = &c1; //pointer primeste adressa  din memorie a lui c1
	Bakery* order2 = &cake1;

	Repo.addOrder(order1);
	Repo.addOrder(order2);

	displayMenu();
	BakeryController bakery_ctr;
	int command;
	cout << "Insert your option: \n";
	cin >> command;


	while (command != 8)
	{
		if (command == 1)
		{
			bool command_type;
			cout << "What kind of object do you want to add? Type 1 for Costumer and 0 for Cake! \n";
			cin >> command_type;
			if (command_type == 1) //we call the Costumer constructor
			{
				float calories;
				int id_order;
				float price;
				string costumer_name;
				int phone_nr;
				int id_costumer;

				cout << " Give calories: \n";
				cin >> calories;
				cout << " Give the id order: \n";
				cin >> id_order;
				cout << " Give the price: \n";
				cin >> price;
				cout << " Give the name of the costumer: \n";
				cin >> costumer_name;
				cout << " Give the phone number of the costumer: \n";
				cin >> phone_nr;
				cout << " Give the id of the costumer: \n";
				cin >> id_costumer;

				BakeryCostumer c1{ calories, price,id_order, costumer_name, phone_nr, id_costumer };
				Bakery* bk1 = &c1;
				bakery_ctr.addOrder_controller(bk1);

			}
			else if (command_type == 0) //we call the Cake constructor
			{
				float calories;
				int id_order;
				float price;
				string filling, spoonge_type, cake_type;
				cout << " Give calories: \n";
				cin >> calories;
				cout << " Give the id order: \n";
				cin >> id_order;
				cout << " Give the price: \n";
				cin >> price;
				cout << " Give the filling type of the cake: \n";
				cin >> filling;
				cout << " Give the spoonge type of the cake: \n";
				cin >> spoonge_type;
				cout << " Give the type of the cake: \n";
				cin >> cake_type;

				Cake cake1{ calories, price,id_order, filling, spoonge_type,cake_type };
				Bakery* bk2 = &cake1;
				bakery_ctr.addOrder_controller(bk2);
				 bakery_ctr.to_string();
			}
		}
		else
			if (command == 3)
			{
				int id;
				cout << " Give the id: \n";
				cin >> id;
				bakery_ctr.removeOrder_controller(id);
			}
			else
				if (command == 2)
					bakery_ctr.display();
				else
					if (command == 4)
					{
						float new_cal;
						int Id, new_id;
						float new_price;

						cout << " Give the Id for the update: \n";
						cin >> Id;
						cout << " Give the new calories: \n";
						cin >> new_cal;
						cout << " Give the new id order: \n";
						cin >> new_id;
						cout << " Give the new price: \n";
						cin >> new_price;
						
						bakery_ctr.updateOrder_controller(Id, new_cal, new_price, new_id);

					}
					else
						if (command == 5)
						{
							bool res = bakery_ctr.UNDO();
							if (res)
								cout << "Succesfuly undone last operation" << endl;
							else
								cout << "No opertaion to be undone" << endl;
							
						}
						else
							if (command == 6)
							{
								bool res = bakery_ctr.REDO();
								if (res)
									cout << "Succesfuly redone last operation" << endl;
								else
									cout << "No opertaion to be redone" << endl;
							}
							else
							if (command == 7)
							{
								float price;
								cout << " Give the price for the filtering: \n";
								cin >> price;
								bakery_ctr.displayByPriceLower(price);
							}
		cout << endl;
		cout << "Enter another option: \n";
		cin >> command;
	}
	
}

int main() {


	DomainTest::runAllDomainTests();
	cout << "\n-------------------\n\n";
	RepositoryTests::runAllRepositoryTests();
	cout << "\n-------------------\n\n";

	start();

	return 0;
}