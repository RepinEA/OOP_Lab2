
#include "StudentsTypes.h"

//Class Normal
int Normal::Session()
{
	return ( 2 + rand()%(5- 2+1 ) ) ;
}

int Normal::nextTry()
{
	return( 2 + rand()%(5- 2+1) );
}



//Class Social
int Social::Session()
{
	return(  2 + rand()%(5- 2+1)   );
}

int Social::nextTry()
{
	return(  3 + rand()%(4- 3+1)   );
}


//Class Smart
int Smart::Session()
{
	return( 4 + rand()%(5- 4+1)  );
}

int Smart::nextTry()
{
	return 5;
}
