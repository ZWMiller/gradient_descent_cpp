#ifndef COSTFUNC_H
#define COSTFUNC_H

#include <vector>
#include <iostream>
#include <cmath>

using namespace std;
using std::vector;

class OLS {
    
private:
    vector<float> beta;
    float intercept;
    float learningRate;
    int numEpochs;
    int numDataCols;
    
public:
    
    OLS(int num_data_cols, float learning_rate=1e-5, int num_epochs=10);
    void updateParameters(float, vector<float>);
    
    float getError(float actual_value, float predicted)
    {
        return predicted-actual_value;
    }
    
    float getSquaredError(float actual_value, float predicted)
    {
        return getError(actual_value, predicted)*getError(actual_value, predicted);
    }
    
    float getLearningRate() { return learningRate; }
    vector<float> getModelParameters() { return beta; }
    void printModelParameters();
    float makePrediction(vector<float>);
    
};


#endif
