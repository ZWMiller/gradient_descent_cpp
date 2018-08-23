import numpy as np

def gen_data(coef=1, coef2=2,  intercept=3., num_points=1000):
    X = np.random.uniform(0,10,num_points)
    X2 = np.random.uniform(0,10,num_points)
    y = coef*X + coef2*X2 + np.random.normal(0,0.5,num_points) + intercept
    for i,j,k in zip(X,X2,y):
        print(i,",",j,",",k)

gen_data()
