#include "Facade.h"
#include <iostream>



int main (void)
{	
	std::cout << "This is a Tree Based Calculator"<< std::endl;
	// Creating a new Calculator
	Facade calculator;
	// Starting up the calculator
	calculator.start();
		
	return 0;
}

