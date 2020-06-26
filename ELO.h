# ifndef ELO_h
# define ELO_h

# include <cmath>
# include <math.h>
# include "ECF.h"
# include "ECF.cpp" // remove for linux

class ELO: private ECF{
	
	~ELO();
	
	double winProbability=0;
	
	public:
	
	double getWinProbability();
	
};

# endif
