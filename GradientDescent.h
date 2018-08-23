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
    OLS ols;
    float learningRate;
    int numEpochs;
    int numDataRows;
    int numDataCols;
    
public:
   
    GradientDescent(vector<DataRow>, float, int);
    ~GradientDescent();
    void fitModel();
    void updateBeta(float, float, vector<float>);
    float dotProduct(vector<float>, vector<float>);
    
    DataRow getDataRow(int n) { return trainingData.at(n);}
    float getLearningRate() { return learningRate; }
    vector<float> getModelParameters() { return beta; }
    void printModelParameters();
};

#endif
