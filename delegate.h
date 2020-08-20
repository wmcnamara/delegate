#ifndef DELEGATE_H
#define DELEGATE_H

#include <functional>
#include <map>

/*
//Weston McNamara 2020
//Licensed Under MIT https://mit-license.org/
//https://github.com/wmcnamara/delegate
 
//Delegate is a single header, lightweight and easy to use abstraction for storing functions and callbacks.
//When you call AddHandler, a integer type containing the ID is returned. To call RemoveHandler, you must pass this integer.
//If you know you might delete the handler you add, be sure to keep track of this number.
*/

namespace Events 
{
	template<typename T>
	class Delegate
	{
	private:
		typedef std::function<void(T)> function;

	public:
		//Invokes each function added to this delegate. 
		//If no handlers exist, it returns false.
		void Invoke(T param)
		{
			if (m_handlers.empty()) 
			{
				assert(!m_handlers.empty());
				std::cout << "Cannot invoke empty vector" << std::endl;
			}

			for (const auto& key : m_handlers)
			{
				key.second(param);
			}
		}

		//Adds a single function to the delegate.
		int AddHandler(function func)
		{
			m_handlers.insert(std::pair<int, function>(m_NextID, func));

			//Return the ID, and increment it.
			return (m_NextID++);
		}

		//Removes a single function from the delegate
		void RemoveHandler(int ID) 
		{
			m_handlers.erase(ID);
		}
		void RemoveAllHandlers() { m_handlers.clear();
	private:		
		std::map<int, function> m_handlers;
		int m_NextID = 0; //Next ID to be used.
	};
}
#endif
