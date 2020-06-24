# ifndef ECF_H
# define ECF_H

# include "ELO.h"
# include "ELO.cpp"

class ECF : public ELO{
	
	~ECF();
	
	public:
	
	getOppenentRating();
	getRating();

};

# endif
