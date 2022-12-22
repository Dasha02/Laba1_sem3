//
//  random_all.hpp
//  LABA1
//
//  Created by Даша Пархоменко on 17.12.2022.
//

#ifndef random_all1_hpp
#define random_all1_hpp

#include <stdio.h>
#include <iostream>
#include <time.h>


using namespace std;

int random_int(int max=1, int min=0)
{
    return (min + rand()%((max+1)-min));
}


double random_double(double max=1.0, double min=0.0)
{
    return (min + rand()*(max-min)/RAND_MAX);
}




#endif /* random_all1_hpp */
