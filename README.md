# Delegate C++

Delegate C++ is a single header, lightweight and easy to use structure for storing functions and callbacks.

# Using Delegate C++

``` C++

#include <iostream>
#include "delegate.h"

//Any function
void YourFunction() { std::cout << "Your Function Was Invoked!" << std::endl; }
void YourFunction2() { std::cout << "Your Function 2 Was Invoked!" << std::endl; }

int main()
{
	Delegate _delegate; 	//Create a delegate

	//Add your functions
	_delegate += YourFunction; 
	_delegate += YourFunction2; 
  
	_delegate(); //Invoke functions added to the delegate.
	
	//Your Function Was Invoked!
	//Your Function 2 Was Invoked!
}
```
