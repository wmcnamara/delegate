# Delegate

Delegate is a single header, thread safe, lightweight and easy to use structure for storing functions and callbacks.

There is comment documentation in the delegate.h file, but you can understand the basic use of the software with the example below.

# Using Delegate

``` C++

#include <iostream>
#include "delegate.h"

//Any function
void YourFunction1(int i) { std::cout << "Function was invoked with: " << i << std::endl; }

int main()
{
	//Create a delegate. 
	//This delegate will take a function that has parameter of type int. 
	//Delegate supports variadic templates, so you can have as many params as you wish.
	Delegate<int> _delegate; 

	//Add your functions.
	//AddHandler returns an ID you can use to remove this function. 
	//If you want to remove this handler, you need this number.
	
	int ID = _delegate.AddHandler(YourFunction1); //You can now use RemoveHandler(ID) to remove this.
	
	_delegate.AddHandler([](int i) //Lambdas work too!
	{ 
		std::cout << "Lambda Function Was Invoked with: " << i << std::endl;
	});
  
	_delegate.Invoke(5); //Invoke functions added to the delegate.
	
	/* 
	OUTPUT:
	Your Function Was Invoked with 5!
	Lambda Function Was Invoked with 5!
	*/
	
	_delegate.RemoveHandler(ID); //YourFunction1 will no longer run.
}
```

# Configuring Delegate
By default, delegate is completely thread safe (with one slight exception discussed below), and automatically performs appropriate locking on thread sensitive functions.

However, locking introduces a slight performance hit. If you are in a single threaded environment, and wish to disable multithreaded locking, you can do so
by defining the `DELEGATE_SINGLETHREADED` macro before including delegate.h.

## Please Note

**Delegate::Invoke() does not perform any thread locking by default.**

Any function you add as a handler is responsible for preventing data races. Delegate provides no assurance that Invoke() will not be called
simultaniously from 2 seperate threads.

This is for performance reasons, considering that Invoke() may be called extremely often.

#### Enabling Invoke locking
If you cannot make all of the handlers thread safe, and/or are willing to take the small performance hit, you can enable 
locking on the Invoke() function by defining the `DELEGATE_LOCK_INVOKE` macro.