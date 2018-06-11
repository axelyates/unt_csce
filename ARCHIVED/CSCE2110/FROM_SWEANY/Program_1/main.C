#include "Set.h"
#include "number.h"
#include <stdlib.h>

int main()
{
    // *******************************************
    //   
    //  THIS main, which is what you'll be responsible
    //  for completing for both the characteristic vector
    //  AND List approach. 
    //   
    // ******************************************* 

    Set sets[NUM_OF_SETS];
    int i,rnd1, rnd2, rnd3, rnd4;

    for( i = 0; i < NUM_OF_SETS * 5; i++)
    {
	rnd1 = random() % 160;
        rnd2 = random() % NUM_OF_SETS;
        sets[rnd2].addToSet(rnd1);
    }
    
    for( i = 0; i < NUM_OF_SETS; i++ )
    {
	rnd1 = random() % 160;
        rnd2 = random() % NUM_OF_SETS;
        sets[rnd2].removeFromSet(rnd1);
    }
    
    // sets[3] = sets[1] & sets[2];
    // sets[3] = sets[1] | sets[2];
    for( i = 0; i < NUM_OF_SETS * 400000; i++)
    {
        rnd1 = random() % NUM_OF_SETS;
        rnd2 = random() % NUM_OF_SETS;
        rnd3 = random() % NUM_OF_SETS;
	rnd4 = random() % 100;
        if( rnd4 < 49 )
            sets[rnd3] = sets[rnd1] & sets[rnd2];
        else
            sets[rnd3] = sets[rnd1] | sets[rnd2];
    }
    

/*  And for some "sampling" of output  */
    for( i = 0; i < 10; i++)
    {
	rnd1 = random() % 160;
        rnd2 = random() % NUM_OF_SETS;
        cout << "sets[" << rnd2 << "] =";
        sets[rnd2].printSet();
        cout << endl;
    }
    return 0; 

}
