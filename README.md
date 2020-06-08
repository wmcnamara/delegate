# Delegate C++

Delegate C++ is a single header, lightweight and easy to use abstraction for storing callbacks.

# Important Information

1. You can find a basic example of Delegate C++ below in the Usage Example section, or in the comments of Delegate.h
2. Delegate C++ makes heavy use of the <std::vector> type.
3. Delegate C++ uses std::function to store functions.

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

	_delegate += YourFunction;
	_delegate += YourFunction2; 
  
	//Invoke functions added to the delegate.
	_delegate();
}

/*
	OUTPUT:
	Your Function Was Invoked!
	Your Function 2 Was Invoked!
*/
```