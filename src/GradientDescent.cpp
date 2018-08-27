
#include "../include/GradientDescent.h"

GradientDescent::GradientDescent(vector<DataRow> dataset, float learning_rate, int n_epochs, int mode)
{
    /**
     Takes in a dataset and hyperparameters for the solver, stores the relevant data,
     initializes the solver and then waits for the user to ask for the solver to run
     ---
     Inputs:
     dataset (vector of DataRow objects)
     learning_rate (the step size modulation for the optimizer)
     n_epochs (how many iterations to do when solving)
     mode: 0 = regression, 1 = classification with log-loss
     */
    trainingData = dataset;
    numDataRows = trainingData.size();
    numEpochs = n_epochs;
    // Set the number of columns in the data
    DataRow row = trainingData.at(0);
    numDataCols = row.getData().size();
    costFunctionMode = mode;
    
    srand(42);
    
    costFunction = new CostFunction(numDataCols, learning_rate, n_epochs);
}

GradientDescent::~GradientDescent()
{
    delete costFunction;
}

void GradientDescent::fitModel()
{
    /**
     Repeatedly does stochastic gradient descent by grabbing a single
     example of data and using it to estimate the best step toward the minimum
     of the objective (cost) function. The cost_function class handles
     all of the updating to allow the GradientDescent class to remain general.
     Acts as an interface between the data class and the cost function class.
     */
    for (int epoch=0; epoch<numEpochs; epoch++){
        std::random_shuffle ( trainingData.begin(), trainingData.end() );
        
        for(int i=0; i<numDataRows; i++){
            DataRow dataRow = trainingData.at(i);
            if (costFunctionMode == 0){
                costFunction->updateParametersOLS(dataRow.getTarget(), dataRow.getData());
            }
            else if (costFunctionMode == 1){
                costFunction->updateParametersLogistic(dataRow.getTarget(), dataRow.getData());
            }
        }
    }
    return;
}




