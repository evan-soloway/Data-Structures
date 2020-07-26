# ifndef ELO_h
# define ELO_h

# include <cmath>
# include <math.h>
# include "ECF.h"

class ELO: public ECF{
	
	double winProbability=0;
	
	public:
	
	int getRating();
	double getWinProbability();
	
};

# endif
