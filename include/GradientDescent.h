#ifndef GRADDESC_H
#define GRADDESC_H

#include "DataRow.h"
#include "CostFunction.h"
#include <cstdlib>
#include <vector>

using namespace std;
using std::vector;

class GradientDescent {
    
private:
    
    vector<float> beta;
    vector<DataRow> trainingData;
    CostFunction* costFunction;
    float learningRate;
    int numEpochs;
    int numDataRows;
    int numDataCols;
    int costFunctionMode;
    
public:
   
    // Methods in cpp
    GradientDescent(vector<DataRow>, float learning_rate = 1e-5, int n_epochs = 10, int mode = 0);
    ~GradientDescent();
    void fitModel();
    
    // Inline methods
    DataRow getDataRow(int n) { return trainingData.at(n);}
    float getLearningRate() { return costFunction->getLearningRate(); }
    vector<float> getModelParameters() { return costFunction->getModelParameters(); }
    void printModelParameters() { costFunction->printModelParameters(); }
    float predictProbability(vector<float> data) { return costFunction->makePredictionProbability(data);}
    float predict(vector<float> data) { return costFunction->makePrediction(data); };
    int getNumRows() { return numDataRows; }
    int getNumCols() { return numDataCols; }
};

#endif
