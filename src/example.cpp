#include "delegate.h"
#include <iostream>

//Your function
void YourFunction()
{
	std::cout << "Hello!" << std::endl;
}

int main()
{
	//Create a DelFunctions object
	DelFunctions functions = 
	{ 
		YourFunction,
		YourFunction,
		YourFunction,
		YourFunction 
	};

	//Assign them to del. You can use a constructor for this aswell.
	Delegate del = functions;

	
	//Invoke them.
	del();
}

//Output:
//Hello!
//Hello!
//Hello!
//Hello!