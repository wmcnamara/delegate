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
	//Create a delegate
	Delegate _delegate; 

	//Add your functions
	_delegate += YourFunction; 
	_delegate += YourFunction2; 
  
  	//Invoke functions added to the delegate.
	_delegate(); 
	
	/* Your Function Was Invoked!
	Your Function 2 Was Invoked! */
}
```
