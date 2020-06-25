#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Engine.h"

using namespace std;

namespace sdds
{
	Engine::Engine(const char* type, double size)
	{
		// Validate explicit params:
		if (size > 0 && type[0] != '\0')
		{
			// Assign params to engine:
			strcpy(m_type, type);
			m_size = size;
		}
	}
	
	double Engine::get() const
	{
		return m_size;			// Return size of engine m_size.
	}

	void Engine::display() const
	{
		// Detect if Engine members are valid:
		if (m_size > 0 && m_type[0] != '\0')
		{
			// If valid, display m_size at precision 2, m_type:
			cout << fixed << setprecision(2) << m_size << " liters - " << m_type << endl;
		}
	}
}