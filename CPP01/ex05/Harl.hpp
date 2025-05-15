#pragma once
#include <iostream>

class Harl {
	typedef void (Harl::*HarlPTR)(void);
	
	private:
		static HarlPTR _functions[4];
		static std::string levels[4];

	public:
		void complain( std::string level );
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
};