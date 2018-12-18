#include <iostream>
#include <iomanip>

using namespace std;
const double PI = 3.141592653589793;

double volumeSphere(double diameter) //calculates the volume of a spherer taking in a diameter
{
	double volume = 0.0;
	volume = (PI * diameter * diameter * diameter) / 6;
	return volume;
}

double subtract(double num1, double num2) //finds the difference between two numbers
{
	double difference = abs(num1 - num2); 
	return difference;
}

int roundNum(double num) //rounds a double
{
	double Dnumber = num;
	int Inumber = num;
	
	if((Dnumber - Inumber) >= 0.5)
	{
		return Inumber + 1;
	}
	
	else
	{
		return Inumber;
	}
}

int main()
{
	double diameter = 0;
	cout << "Diameter: ";
	cin >> diameter;
	
	double volume1 = volumeSphere(diameter);
	diameter++;
	double volume2 = volumeSphere(diameter);
	int growth = roundNum(subtract(volume1, volume2));
	cout << "Increase: " << growth << endl;
	diameter++;
	double volume3 = volumeSphere(diameter);
	growth = roundNum(subtract(volume3, volume2));
	cout << "Increase: " << growth << endl;
}