#ifndef DELEGATE_H
#define DELEGATE_H

#include <vector>
#include <functional>

/*
//Weston McNamara 2020
//Licensed Under MIT https://mit-license.org/
//https://github.com/westonmcnamara/delegate-cpp
 
//Delegate C++ is a single header, lightweight and easy to use abstraction for storing functions and callbacks.
//Delegate C++ currently cannot accept any functions with parameters. This is subject to change.

//AddHandler functions return a Connection object. When you add a Handler, if you plan on removing it keep track of this object.
Example: Connection conn = delegate.AddHandler(func);

To remove func from being called, you must call:
delegate.RemoveHandler(conn);
With the connection object.

You CANNOT do this:
delegate.RemoveHandler(func);
*/

class Connection
{
public:
	Connection(int index) : m_index(index) {}
	int Index() const { return m_index; }
private:
	int m_index;
};

class Delegate
{
	public:       
		//Invokes each function added to this delegate. 
		//If no handlers exist, it throws std::runtime_error.
		void Invoke() 
		{
			if (m_handlers.empty()) { throw std::runtime_error("Empty delegate cannot be invoked."); }
			
			for (auto handler : m_handlers) 
			{
				handler();
			}
		}

		//Adds a single function to the delegate.
		Connection&& AddHandler(std::function<void()> func)
		{
			//The new function was just added, size will be the position of it.
			m_handlers.push_back(func); 

			//Size does not take the index into account, so we subtract one to give the index.
			return Connection(m_handlers.size() - 1); 
		}

		//Removes a single function from the delegate
		void RemoveHandler(Connection& conn) 
		{
			m_handlers.erase(m_handlers.begin() + conn.Index());
		}

		void RemoveAllHandlers() { m_handlers.clear(); }

		//Invokes each handler added to this delegate.
		void operator() () { Invoke(); }

	private:
		std::vector<std::function<void()>> m_handlers;
};
#endif
