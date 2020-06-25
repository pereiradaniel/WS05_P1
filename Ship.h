#pragma once
#ifndef SDDS_SHIP_H
#define SDDS_SHIP_H
#include "Engine.h"

namespace sdds
{
	const double	MIN_STD_POWER = 90.111;		// The minimum power of a ship, acc'g to the regulation.
	const double	MAX_STD_POWER = 99.999;		// The maximum power of a ship acc'g to the regulation.
	const int		MAX_NUM_ENGINES = 10;		// The maximum number of engines a ship can have.

	class Ship
	{
		Engine	m_engines[MAX_NUM_ENGINES];		// Statically allocated array of engines, of size MAX_NUM_ENGINES.
		char	m_type[TYPE_MAX_SIZE + 1];		// Ship model type, statically allocated arry of charss of TYPE_MAX_SIZE.
		int		m_engCnt;						// The number of engines that are actually installed on the ship.

	public:
		Ship() = default;
		// ~Ship() = default;
		Ship(const char* type, const Engine arr[], int size);
		operator bool() const;
		bool operator<(double power) const;
		double calculatePower() const;
		void display() const;
		Ship& operator+=(Engine engine);
		
	};
	bool operator<(double power, const Ship& theShip);
}

#endif