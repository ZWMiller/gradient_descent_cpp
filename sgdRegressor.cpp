#include "GradientDescent.h"
#include "DataRow.h"
#include <vector>
#include <cstdlib>

using namespace std;
using std::vector;

int main(){
    // TO DO: Use command line args to read csv file
    
    vector<DataRow> dataset;
    for (int i=0; i<100; i++){
        vector<float> a;
        a.push_back(float(i));
        a.push_back(3.*float(100-i));
        dataset.push_back(DataRow(a, 2.*a.at(0)+10.*a.at(1)+float(rand()%10)/10.));
        
    }
    
    GradientDescent SGD = GradientDescent(dataset);
    cout << "Init Beta: \n";
    SGD.printModelParameters();
    SGD.fitModel();
    cout << "\nFinal Beta: \n";
    SGD.printModelParameters();
    
    return 1;
}
