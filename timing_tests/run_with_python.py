import pandas as pd
from sgd_regressor import sgd_regressor

data = pd.read_csv("../sample_data.txt")
X = data.iloc[:,:-1]
y = data.iloc[:,-1]

sgd = sgd_regressor(alpha=1e-5, n_iter=1000, fit_intercept=True, lamb=0)
sgd.fit(X,y)
print(sgd.coef_)
for i,j in zip(sgd.predict(X), y):
    print(i,j)

