/***************************
Name: Evan Soloway
File: elo.h
Project: Hello World
Purpose: Prototypes ELO class.
***************************/

# ifndef ELO_h
# define ELO_h

# include <cmath>
# include <math.h>
# include "ecf.h"

class ELO: public ECF{
	
        private:
	double winProbability; 
	
	public:
	
        ELO();
	int getRating();
	double getWinProbability();
	
};

# endif
