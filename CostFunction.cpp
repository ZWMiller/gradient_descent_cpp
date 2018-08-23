
#include "CostFunction.h"


OLS::OLS(int num_data_cols, float learning_rate, int num_epochs){
    
    learningRate = learning_rate;
    numEpochs = num_epochs;
    numDataCols = num_data_cols;
    
    // Generate Random Beta Start point
    for (int i=0; i<numDataCols; i++){
        beta.push_back( float(rand()%10)/float(rand()%10) );
    }
}

void OLS::updateParameters(float target, vector<float> data)
{
    float prediction = dotProduct(beta, data);
    float error = getError(target, prediction);
    for (int i=0; i<numDataCols; i++){
        beta.at(i) = beta.at(i) - learningRate*error*data.at(i);
    }
}

void OLS::printModelParameters()
{
    cout << "[";
    for(int i=0; i<numDataCols; i++){
        cout << beta.at(i) << ", ";
    }
    cout << "]\n";
}

float OLS::dotProduct(vector<float> vect_A, vector<float> vect_B)
{
    
    float product = 0.;
    
    for (int i = 0; i < numDataCols; i++)
        product = product + vect_A.at(i) * vect_B.at(i);
    
    return product;
}
