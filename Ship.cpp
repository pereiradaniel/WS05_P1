#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Ship.h"
#include "Engine.h"

using namespace std;

namespace sdds
{
	Ship::Ship()
	{
		initializeShip();
	}

	void Ship::initializeShip()
	{
		m_type[0] = '\0';
		m_engCnt = 0;
		// m_engines[m_engCnt];
		Engine* m_engines = new Engine[MAX_NUM_ENGINES];
		for (int i = 0; i < MAX_NUM_ENGINES; i++)
		{
			m_engines[i].initializeEngine();
		}
	}

	Ship::Ship(const char* type, const Engine engines[], int cnt)
	{
		// Validate params:
		if (type != nullptr && engines != nullptr && cnt > 0)
		{
			// If valid, store params in current instance:
			strcpy(m_type, type);			// Copy string from params to current instance of m_type.
			m_engCnt = cnt;					// Current instance of m_engCnt is set to param cnt.
			
			Engine* m_engines = new Engine[cnt];
			for (int i = 0; i < cnt; i++)
			{
				m_engines[i].initializeEngine();
			}
			// Iterate through current instance's m_engines[i] and assign engines[i].
			for (int i = 0; i < cnt; i++)
			{
				m_engines[i] = engines[i];
			}
		}
		else 
		{
			initializeShip();
		}
	}

	double Ship::calculatePower() const
	{
		double total_power = 0;
		for (int i = 0; i < m_engCnt; i++)
		{
			total_power += m_engines[i].get() * 5;
		}
		return total_power;
	}

	void Ship::display() const
	{
		if (*this)
		{
			cout << "No available data" << endl;
		}
		else
		{
			cout << m_type << "-";
			cout.setf(ios::fixed);
			cout.precision(2);
			cout.width(6);
			cout << calculatePower() << endl;
			cout.unsetf(ios::fixed);
			cout.precision(6);
			for (int i = 0; i < m_engCnt; i++)
			{
				m_engines[i].display();
			}
		}
	}

	Ship::operator bool() const
	{
		// Explain in the reflection what happens if the keyword explicit is removed, and why is it necessary.
		bool valid = true;
		m_type[0] == '\0' && m_engCnt == 0 ? valid = false : valid = true;
		return valid;
	}

	Ship& Ship::operator+=(Engine engine)
	{
		// Make sure the number of engines is less than max allowed:
		if (m_engCnt < MAX_NUM_ENGINES)
		{
			if (m_type[0] == '\0')
			{
				cout << "The object is not valid! Engine cannot be added!" << endl;		// Output error message.
			}
		}
		else
		{
			int index = m_engCnt++;
			m_engines[index] = engine;
		}
		return *this;
	}

	bool Ship::operator<(double power) const
	{
		bool result = false;
		calculatePower() < power ? result = true : result = false;
		return result;
	}

	bool operator<(double power, const Ship& ship)
	{
		bool result = false;
		ship.calculatePower() > power ? result = false : result = true;
		return result;

	}

}