# ifndef ELO_h
# define ELO_h


# include <cmath>
# include <math.h>
# include "ECF.h"

class ELO: public ECF{
	
        private:
	double winProbability; // og initialized to 0
	
	protected:
	
	int getRating();
	double getWinProbability();
	
};

# endif
