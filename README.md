# C++ Gradient Descent

### A gradient descent solver written in C++ with the ability to read from CSV. 

Designed to be a modular solver that allows the user to plug-in different cost functions and solve different problems
with the same overall architecture. 

Install:

Clone this repository and run:

For Regression:
```bash
g++ GradientDescent.cpp sgdRegressor.cpp CostFunction.cpp
```

For Classification:
```bash
g++ GradientDescent.cpp sgdClassifier.cpp CostFunction.cpp
```

Run:

You will need to format your CSV like this (with no header). The format should be all of the features seperated by commas
then the target as the last column also seperated by a comma:

```bash
# feature 1, feature 2, ... feature N, target (this line won't be in the actual file)
2, 4, 8, 14, 2.8
1, 2, 4, 7, 1.4
.......
3, 6, 12, 21, 4.2
```

**The target must be the last column, and all columns before it will be treated as predictive features for that target.**

Then to run the actual algorithm you do:

```bash
./a.out name_of_file.csv
```

At present, if you want to tweak the learning rate or number of epochs you must manually change the code in `sgdRegressor.cpp`.
