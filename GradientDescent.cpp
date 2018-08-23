
#include "GradientDescent.h"

GradientDescent::GradientDescent(vector<DataRow> dataset, float learning_rate=0.01, int n_epochs=5)
{
    trainingData = dataset;
    numDataRows = trainingData.size();
    learningRate = learning_rate;
    numEpochs = n_epochs;
    
    // Set the number of columns in the data
    DataRow row = trainingData.at(0);
    numDataCols = row.getData().size();
    
    srand(42);
    
    // Generate Random Beta Start point
    for (int i=0; i<numDataCols; i++){
        beta.push_back( float(rand()%10)/float(rand()%10) );
    }
    
    // Hard code in OLS for now
    ols = OLS();
}

GradientDescent::~GradientDescent()
{
    
}

void GradientDescent::fitModel()
{
    
    for (int epoch=0; epoch<numEpochs; epoch++){
        std::random_shuffle ( trainingData.begin(), trainingData.end() );
        
        for(int i=0; i<numDataRows; i++){
            DataRow dataRow = trainingData.at(i);
            float prediction = dotProduct(beta, dataRow.getData());
            updateBeta(dataRow.getTarget(), prediction, dataRow.getData());
        }
    }
    return;
}

void GradientDescent::updateBeta(float target, float prediction, vector<float> data)
{
    float error = ols.getError(target, prediction);
    for (int i=0; i<numDataCols; i++){
        beta.at(i) = beta.at(i) - learningRate*error*data.at(i);
    }
}

float GradientDescent::dotProduct(vector<float> vect_A, vector<float> vect_B)
{
    
    float product = 0.;
    
    for (int i = 0; i < numDataCols; i++)
        product = product + vect_A.at(i) * vect_B.at(i);
    
    return product;
}

void GradientDescent::printModelParameters()
{
    for(int i=0; i<numDataCols; i++){
        cout << beta.at(i) << "\n";
    }
}
