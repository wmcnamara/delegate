# Delegate

Delegate is a single header, lightweight and easy to use structure for storing functions and callbacks.

There is comment documentation in the delegate.h file, but you can understand the basic use of the software with the example below.

# Using Delegate

``` C++

#include <iostream>
#include "delegate.h"

//Any function
void YourFunction1() { std::cout << "Your Function Was Invoked!" << std::endl; }

int main()
{
	//Create a delegate
	Events::Delegate _delegate; 

	//Add your functions.
	//AddHandler returns an ID you can use to remove this function. If you want to remove this handler, you need this number.
	
	int ID = _delegate.AddHandler(YourFunction1); //You can now use RemoveHandler(ID) to remove this.
	
	_delegate.AddHandler([]() //Lambdas work too!
	{ 
		std::cout << "Lambda Function Was Invoked!" << std::endl;
	});
  
	_delegate.Invoke(); //Invoke functions added to the delegate.
	
	/* 
	OUTPUT:
	Your Function Was Invoked!
	Lambda Function Was Invoked!
	*/
	
	_delegate.RemoveHandler(ID); //YourFunction1 will no longer run.
}
```
