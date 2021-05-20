# Delegate

Delegate is a single header, thread safe, lightweight and easy to use structure for storing functions and callbacks.

There is comment documentation in the delegate.h file, but you can understand the basic use of the software with the example below.

# Using Delegate

``` C++

#include <iostream>
#include "delegate.h"

//Any function
void YourFunction1(int i) { std::cout << "Function was invoked with: " << i << '\n'; }

int main()
{
	//This delegate will take a function that has parameter of type int. 
	Delegate<int> del; 

	int ID = del.AddHandler(YourFunction1); //You can now use RemoveHandler(ID) to remove this.
  
	del.Invoke(5); //Invoke functions added to the delegate.
	
	/* 
	OUTPUT:
	Function Was Invoked with 5!
	*/
	
	_delegate.RemoveHandler(ID); //YourFunction1 will no longer run.
}
```
# Notes
- You can add as many parameters as you want to an event. Delegate supports variadic templates!
```cpp
Delegate<int, int, float, bool> del;
```
- Dont need a parameter for an event? Use the `void` specialization!
```cpp
Delegate<void> del; //no parameter
```
### Remember
`AddHandler()` returns an ID you need to use to remove a function.

If you know you'll need to remove a handler, it is recommended you do it in RAII fashion, as in:
1. Call `AddHandler` in the constructor
2. Store the ID as a member variable
3. Call `RemoveHandler` in the destructor

# Configuring Delegate
By default, delegate is completely thread safe (with one slight exception discussed below), and automatically performs appropriate locking on thread sensitive functions.

However, locking introduces a slight performance hit. If you are in a single threaded environment, and wish to disable multithreaded locking, you can do so
by defining the `DELEGATE_SINGLETHREADED` macro before including delegate.h.

## Important

**Delegate::Invoke() does not perform any thread locking by default.**

Any function you add as a handler is responsible for preventing data races. Delegate provides no assurance that Invoke() will not be called
simultaniously from 2 seperate threads.

This is for performance reasons, considering that Invoke() may be called extremely often.

If you cannot make all of the handlers thread safe, and/or are willing to take the small performance hit, you can enable 
locking on the Invoke() function by defining the `DELEGATE_LOCK_INVOKE` macro.
