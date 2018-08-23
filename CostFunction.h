#ifndef COSTFUNC_H
#define COSTFUNC_H

#include <vector>
#include <iostream>
#include <cmath>

using namespace std;
using std::vector;

class OLS {
    
public:
    float getError(float actual_value, float predicted)
    {
        return predicted-actual_value;
    }
    
    float getSquaredError(float actual_value, float predicted)
    {
        return getError(actual_value, predicted)*getError(actual_value, predicted);
    }
    
};


#endif
