# Delegate

Delegate C++ is a single header, lightweight and easy to use structure for storing functions and callbacks.

There is comment documentation in the delegate.h file, but you can understand the basic use of the software with the example below.

# Using Delegate

``` C++

#include <iostream>
#include "delegate.h"

//Any function
void YourFunction1() { std::cout << "Your Function Was Invoked!" << std::endl; }
void YourFunction2() { std::cout << "Your Function 2 Was Invoked!" << std::endl; }

int main()
{
	//Create a delegate
	Delegate _delegate; 

	//Add your functions.
	//AddHandler returns a Connection object. If you want to remove this handler, you need this object.
	
	Connection conn = _delegate.AddHandler(YourFunction1); //You can now use RemoveHandler(conn) to remove this.
	_delegate.AddHandler(YourFunction2); //You cannot remove this, because you dont have the connection object.
  
  	//Invoke functions added to the delegate.
	_delegate.Invoke(); 
	
	/* Your Function Was Invoked!
	Your Function 2 Was Invoked! */
	
	_delegate.RemoveHandler(conn); //YourFunction1 will no longer run.
}
```
