#include "GradientDescent.h"
#include "DataRow.h"
#include <vector>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
using std::vector;

vector<DataRow> read_csv(string filename){
    
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
    vector<DataRow> dataset;
    
    for (int i=0; i<100; i++){
        vector<float> a;
        a.push_back(float(i));
        a.push_back(3.*float(100-i));
        dataset.push_back(DataRow(a, 2.*a.at(0)+10.*a.at(1)+float(rand()%10)/10.));
    }
    return dataset;
}

int main(int argc, char *argv[]){

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
    
    GradientDescent SGD = GradientDescent(dataset, 1e-4, 1000);
    cout << "Init Beta: \n";
    SGD.printModelParameters();
    SGD.fitModel();
    cout << "\nFinal Beta: \n";
    SGD.printModelParameters();
    
    return 1;
}
