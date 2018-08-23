#include "GradientDescent.h"
#include "DataRow.h"
#include <vector>
#include <cstdlib>

using namespace std;
using std::vector;

int main(){
    // TO DO: Use command line args to read csv file
    
    vector<DataRow> dataset;
    for (int i=0; i<40; i++){
        vector<float> a;
        a.push_back(float(i));
        dataset.push_back(DataRow(a, 2.*float(i)+float(rand()%10)/10.));
        
    }
    
    GradientDescent SGD = GradientDescent(dataset, 1e-5, 1000);
    cout << "Init Beta: ";
    SGD.printModelParameters();
    SGD.fitModel();
    cout << "\nFinal Beta: ";
    SGD.printModelParameters();
    
    return 1;
}
