import pandas as pd
import numpy as np 
from sklearn.neighbors import KNeighborsClassifier as kNN 
from sklearn.svm import SVC as SVM 

def qualitative_to_0_1(data, column, value_to_be_1): 
    data = pd.read_excel('loan_data.xlsx') 
    columns = list(data.columns) 
    mask = data[column].values == value_to_be_1
    data[column][mask] = 1 
    data [column][not(mask)] = 0
    print(data[column])



cat_feature = pd.Categorical(X.Property_Area) 
one_hot  = pd.get_dummies(cat_feature) 
data = pd.concat([data, one_hot], axis = 1) 
data = data.drop(columns = ['Property_Area'])


features = data.columns 
vals = data.values.astype(np.float) 
X = vals[:, :-1] 
y = vals[:,-1] 


models = [kNN(), SVM()] 
for model in models:  
    model.fit(X_train,y_train) 
    y_pred = model.predict(X_test) 
    print(confusion_matrix(y_test, y_pred))