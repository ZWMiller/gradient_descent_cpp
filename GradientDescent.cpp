
#include "GradientDescent.h"

GradientDescent::GradientDescent(vector<DataRow> dataset, float learning_rate, int n_epochs)
{
    trainingData = dataset;
    numDataRows = trainingData.size();
    numEpochs = n_epochs;
    // Set the number of columns in the data
    DataRow row = trainingData.at(0);
    numDataCols = row.getData().size();
    
    srand(42);
    
    // Hard code in OLS for now
    cost_function = new OLS(numDataCols, learning_rate, n_epochs);
}

GradientDescent::~GradientDescent()
{
    delete cost_function;
}

void GradientDescent::fitModel()
{
    for (int epoch=0; epoch<numEpochs; epoch++){
        std::random_shuffle ( trainingData.begin(), trainingData.end() );
        
        for(int i=0; i<numDataRows; i++){
            DataRow dataRow = trainingData.at(i);
            cost_function->updateParameters(dataRow.getTarget(), dataRow.getData());
        }
    }
    return;
}




