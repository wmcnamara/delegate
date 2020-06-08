#ifndef DELEGATE_H
#define DELEGATE_H

#include <vector>
#include <functional>
#include <exception>

//Weston McNamara 2020, Made With Love In Canada
//Licensed Under MIT https://mit-license.org/
 
//Delegate C++ is a single header, lightweight and easy to use abstraction for storing functions and callbacks.
//Delegate C++ currently cannot accept any functions with parameters. This is subject to change.

/*
	You can use delegate C++ by creating an instance of Delegate, adding in your functions, and calling Invoke();
	Delegate C++ uses 2 types to store functions. 

	1. DelFunctions - A reference to multiple functions.
	2. DelFunction - A reference to a single function.

	These are used as parameters and return values for all Delegate C++ functions and systems.

	Delegate C++ does not inherit from, but is based heavily off of the <std::vector> type.
	At its base, Delegate C++ uses an <std::vector> of <std::function> to store its data.
*/

/////////////////////////////////////////////
/*Typedefs for ease of use and readability.*/
/////////////////////////////////////////////

//std::vector of functions. Used to add multiple functions to a delegate.
typedef std::vector<std::function<void()>> DelFunctions;

//Single std::function. Used to store single function.
typedef std::function<void()> DelFunction;

class Delegate
{
	public:
		//Creates a delegate and initializes it with a single handler.
		Delegate(DelFunction func) { m_handlers.push_back(func); }
		//Creates a delegate and initializes it with multiple handlers.
		Delegate(DelFunctions functions) : m_handlers(functions) {}
		//Copy Constructor
		Delegate(const Delegate &delegate) : m_handlers(delegate.GetHandlers()) {}
		//Creates a delegate with no Functions
		Delegate() {}

		//Invokes each function added to this delegate. 
		//If no handlers exist, it throws std::runtime_error.
		void Invoke()
		{
			if (m_handlers.empty()) { throw std::runtime_error("Empty delegate cannot be invoked."); }

			//Iterate through the vector, and invoke each function.
			for (int i = 0; i != m_handlers.size(); i++)
			{
				m_handlers[i]();
			}
		}

		//Invokes function at index i
		void Invoke(int i)
		{
			if (m_handlers.empty()) { throw std::runtime_error("Empty delegate cannot be invoked."); }

			//Call function at i
			m_handlers[i]();
		}

		//Adds a single DelFunction to the delegate.
		void AddHandler(DelFunction func) { m_handlers.push_back(func); }

		//Removes handler at index i
		void RemoveHandler(int i) { m_handlers.erase(m_handlers.begin() + i); }

		//Removes every function added to this delegate.
		void RemoveAllHandlers() { m_handlers.clear(); }

		//Invokes each handler added to this delegate.
		void operator() () { Invoke(); }

		//Returns a function in the delegate at index i.
		DelFunction operator[] (int i) const { return m_handlers[i]; }

		//Returns a delFunctions containing all handlers.
		DelFunctions GetHandlers() const { return m_handlers; }

	private:
		//This is where handlers/functions are stored.
		DelFunctions m_handlers;
};
#endif