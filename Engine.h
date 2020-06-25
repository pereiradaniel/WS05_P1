#pragma once
#ifndef SDDS_ENGINE_H
#define SDDS_ENGINE_H

namespace sdds
{
	const int TYPE_MAX_SIZE = 30;			// Max length of the type attribute in Engine class.
	
	class Engine
	{
		private:
			char* m_type[TYPE_MAX_SIZE];	// The engine model type, as an array of chars of size TYPE_MAX_SIZE.
			float m_size;					// The size of an engine, as a floating point number in double precision.

		public:
			Engine();						// Default constructor.
			Engine(char* type, float size);	// Custom constructor that rx's as params: engine type, size.
			double get() const;				// Query that returns the size of the engine.
			void display() const;			// Query that prints to the screen the content of an object in the format [SIZE] - liters - [TYPE] <ENDL>
	};


}

#endif
