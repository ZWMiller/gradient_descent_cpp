#ifndef DATAROW_H
#define DATAROW_H

#include <vector>

using namespace std;
using std::vector;

class DataRow {
    /*
     Storage class. Just holds vector of features and
     the associated target value, as well as providing
     getters for the data (no setters to maintain data
     integrity)
     */

private:
    vector<float> data;
    float target;
    
public:
    DataRow(vector<float> input_data, float input_target){
        data = input_data;
        target = input_target;
    }
    
    vector<float> getData() { return data;}
    float getDataAtIndex(int n) { return data.at(n);}
    float getTarget() { return target; }
};

#endif
