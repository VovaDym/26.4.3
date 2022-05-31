#include <iostream>
#include "desctop.h"

int main()
{
	Desctop myWindow;

	bool exit = false;
	while (!exit)
	{
		switch (myWindow.chosenCommand())
		{
		case 0:
			myWindow.display();
			break;
		case 1:
			myWindow.resize();
			break;
		case 2:
			myWindow.move();
			break;
		case 3:
			exit = true;
			break;
		default:
			std::cout << "Incorrect command. Try again" << std::endl << std::endl;
			break;
		}
	}
}
