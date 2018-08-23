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
    OLS* cost_function;
    float learningRate;
    int numEpochs;
    int numDataRows;
    int numDataCols;
    
public:
   
    GradientDescent(vector<DataRow>, float learning_rate = 1e-5, int n_epochs = 10);
    ~GradientDescent();
    void fitModel();
    
    DataRow getDataRow(int n) { return trainingData.at(n);}
    float getLearningRate() { return cost_function->getLearningRate(); }
    vector<float> getModelParameters() { return cost_function->getModelParameters(); }
    void printModelParameters() { cost_function->printModelParameters(); }
};

#endif
