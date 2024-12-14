#include <iostream>

using namespace std;

class Car {
	int amountOfDoors;
	int amountOfWheels;
	int velocity;
	int color;
	static enum Colors {
		red = 0,		
		green = 1,		
		blue = 2		
	};					
public:

	Car() {															  
		amountOfDoors = 4;											  
		amountOfWheels = 4;											  
		velocity = 69;												  
		int colorName = rand() % 3;									  
		ChooseColor(colorName);										  
	}																  
																	  
	Car(int amountOfDoors, int amountOfWheels, int velocity) {		  
		this->amountOfDoors = amountOfDoors;						  
		this->amountOfWheels = amountOfWheels;						  
		this->velocity = velocity;									  
		int colorName = rand() % 3;									  
		ChooseColor(colorName);										  
	}										
											
	void ChooseColor(int colorName) {		
		if (colorName == 0)					
			color = Colors::red;			
		else if (colorName == 1)			
			color = Colors::green;			
		else if (colorName == 2)			
			color = Colors::blue;			
	}										



	int GetDoors() {						 
		return this->amountOfDoors;			 
	}										 
	int GetWheels() {						 
		return this->amountOfWheels;		 
	}										 
	int GetVelocity() {						 
		return this->velocity;				 
	}										 
	int GetColor() {						 
		return this->color;					 
	}										 
	void AssingValues(const int amountOfDoors, const int amountOfWheels, int velocity, int color) {	 
		this->amountOfDoors = amountOfDoors;														 
		this->amountOfWheels = amountOfWheels;														 
		this->velocity = velocity;																	 
		this->color = color;																		 
	}																								 
};

class Parking {
	Car* cars;
public:
	Parking() {
		cars = new Car[amountOfCars];
	}
	static int amountOfCars;
																																
	void ParkTheCar(Car car) {																									
		IncrementAmountOfPoints(1);																								
		Car* tempArrOfCars = new Car[amountOfCars];

		for (int i = 0; i < amountOfCars - 1; i++) {																			
			tempArrOfCars[i].AssingValues(cars[i].GetDoors(), cars[i].GetWheels(), cars[i].GetVelocity(), cars[i].GetColor());	
		}
		tempArrOfCars[amountOfCars - 1].AssingValues(car.GetDoors(), car.GetWheels(), car.GetVelocity(), car.GetColor());
		delete[] cars;																											
		cars = new Car[amountOfCars];																							
		cars = tempArrOfCars;																									
	}																															
	void UnparkTheCar(int index) {																										  
		DecrementAmountOfPoints(1);																										  
		Car* temporaryArr = new Car[amountOfCars];																						  
		int tempIndex = 0;																												  
		for (int i = 0; i < amountOfCars + 1; i++)																						  
		{																																  
			if (i + 1 == index) {																										  
				continue;																												  
			}																															  
			else {																														  
				temporaryArr[tempIndex].AssingValues(cars[i].GetDoors(), cars[i].GetWheels(), cars[i].GetVelocity(), cars[i].GetColor()); 
				tempIndex++;																											  
			}																															  
		}																																  
		delete[] cars;
		cars = temporaryArr;
		cars = new Car[amountOfCars];
		cars = temporaryArr;
	}

	void Printer() {													   
		for (int i = 0; i < amountOfCars; i++)							   
		{																   
			cout << "Information about car number " << i + 1 << ": " << endl;
			cout << "Amount of doors: " << cars[i].GetDoors() << endl;	   
			cout << "Amount of wheels: " << cars[i].GetWheels() << endl;   
			cout << "Velocity: " << cars[i].GetVelocity() << endl;		   
			if (cars[i].GetColor() == 0) {								   
				cout << "Color red" << endl;								
			}															   
			else if (cars[i].GetColor() == 1) {							   
				cout << "Color green" << endl;							   
			}															   
			else if (cars[i].GetColor() == 2) {							   
				cout << "Color blue" << endl;							   
			}											
		}												
	}													

	static void IncrementAmountOfPoints(int x) {	   
		amountOfCars += x;							   
	}												   
	static void DecrementAmountOfPoints(int x) {	   
		amountOfCars -= x;							   
	}												   
};

int Parking::amountOfCars = 0;

int main()
{
	srand(time(NULL));
	int command;

	Car car;
	Parking park;

	park.ParkTheCar(car);
	park.ParkTheCar(car);
	park.Printer();
	cout << "------------------" << endl;
	park.UnparkTheCar(2);
	park.Printer();
}