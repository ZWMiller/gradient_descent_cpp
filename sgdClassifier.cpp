
#include "include/GradientDescent.h"
#include "include/DataRow.h"
#include <vector>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
using std::vector;

vector<DataRow> read_csv(string filename){
    /**
     Given the filename for a CSV in the format of
     "feature, feature, feature, ..., target"
     this code will read row by row, create data storage
     sections, and store all the features as a vector
     and the target as a float
     ---
     Input: filename (string)
     Output: vector of data rows
     */
    vector<DataRow> dataset;
    ifstream readRecords;
    readRecords.open(filename);
    
    while ( readRecords )
    {
        string s;
        if (!getline( readRecords, s )) break;
        
        istringstream ss( s );
        vector <float> record;
        
        while (ss)
        {
            string s;
            if (!getline( ss, s, ',' )) break;
            
            float f;
            stringstream stringToFloat(s);
            stringToFloat >> f;
            
            record.push_back( f );
        }
        
        if(!record.empty())
        {
            float target = record.back();
            record.pop_back();
            dataset.push_back(DataRow(record, target));
        }
    }
    readRecords.close();
    return dataset;
}

vector<DataRow> generate_dataset(){
    /**
     Uses built-in C++ random number generator to
     generate a correlated X (vector), y (target) pair
     with slopes of 2 and 10 for the features as well
     as some additive noise.
     ---
     Output: vector of data rows
     */
    vector<DataRow> dataset;
    
    for (int i=0; i<100; i++){
        vector<float> a;
        int correct_class = 0;
        a.push_back(float(i));
        a.push_back(3.*float(100-i));
        
        if (a.at(1) > 55) { correct_class = 1;}
        dataset.push_back(DataRow(a, correct_class));
    }
    return dataset;
}

int main(int argc, char *argv[]){
    /*
     Takes a user provided CSV and runs a gradient descent
     solver on it. At present, this with a logistic regression cost
     function.
     
     Main flow:
     Get data from CSV (or generate if no CSV)
     Create a gradient descent model with cost_function
     fit that model
     print parameters
     */
    
    vector<DataRow> dataset;
    
    if (argc > 1 )
    {
        string filename = argv[1];
        cout << "\n--- Reading from file " << filename << " ---\n";
        dataset = read_csv(filename);
    }
    else
    {
        cout << "\n--- No dataset provided, generating a fake one ---\n";
        dataset = generate_dataset();
    }
    
    GradientDescent SGD = GradientDescent(dataset, 1e-4, 1000, 1);
    cout << "Init Beta: \n";
    SGD.printModelParameters();
    SGD.fitModel();
    cout << "\nFinal Beta: \n";
    SGD.printModelParameters();
    
    for (int i=0; i<SGD.getNumRows(); i++){
        cout << "Actual: " << dataset.at(i).getTarget() << " , Predict: " <<
        SGD.predictProbability(dataset.at(i).getData()) << endl;
    }
    
    return 1;
}
