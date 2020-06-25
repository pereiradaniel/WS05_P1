#pragma once
#ifndef SDDS_ENGINE_H
#define SDDS_ENGINE_H
#include "Engine.h"

namespace sdds
{
	float MIN_STD_POWER = 90.111;		// The minimum power of a ship, acc'g to the regulation.
	float MAX_STD_PPOWER = 99.999;		// The maximum power of a ship acc'g to the regulation.

	class Ship
	{
		Engine* m_engines[10];			// A statically allocated array of engines, of size 10. We say the ship has a capacity of maximum, 10 engines; we can have installed less than that.
		char* m_type[TYPE_MAX_SIZE];		// The ship model type, as a statically allocated array of characters of size TYPE_MAX_SIZE (not including the null terminator).
		int m_engCrt;					// The number of engines that are actually installed on the ship.

	public:
		// set the current instance into a safe empty state.Remember, an empty state signal the absence of data in an object; it is a special value for an attribute, or a combination of values for multiple attributes that can be recognized at any momentand cannot be confused with valid data.Choose any empty state that makes sense for your design.
		Ship();
		
	};

}

#endif