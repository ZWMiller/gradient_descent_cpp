
#include "CostFunction.h"


OLS::OLS(int num_data_cols, float learning_rate, int num_epochs){
    
    learningRate = learning_rate;
    numEpochs = num_epochs;
    numDataCols = num_data_cols;
    
    // Generate Random Beta Start point
    for (int i=0; i<numDataCols; i++){
        beta.push_back( float(rand()%10)/float(rand()%10) );
    }
    intercept = float(rand()%10)/float(rand()%10);
}

void OLS::updateParameters(float target, vector<float> data)
{
    float prediction = makePrediction(data);
    float error = getError(target, prediction);
    for (int i=0; i<numDataCols; i++){
        beta.at(i) = beta.at(i) - learningRate*error*data.at(i);
    }
    intercept = intercept - learningRate*error;
}

void OLS::printModelParameters()
{
    cout << "[";
    for(int i=0; i<numDataCols; i++){
        cout << beta.at(i) << ", ";
    }
    cout << intercept;
    cout << "]\n";
}

float OLS::makePrediction(vector<float> data_vector)
{
    
    float product = 0.;
    
    for (int i = 0; i < numDataCols; i++)
        product = product + beta.at(i) * data_vector.at(i);
    
    product += intercept;
    
    return product;
}
