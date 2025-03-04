import numpy as np
import matplotlib as plt
import pandas as pd
import seaborn as sns
#from sklearn.linear_model import LinearRegression
#from sklearn.model_selection import train_test_split
#from sklearn.tree
import librosa
from scipy.io import wavfile
import os
from matplotlib import rcParams
from sklearn.decomposition import PCA


df = pd.read_csv("StudentPerformanceFactors.csv", sep=",")

df.head()

df["Access_to_Resources"] = df["Access_to_Resources"].replace(
    {'Low':1, 'Medium':2, 'High':3}
)

df["Parental_Involvement"] = df["Parental_Involvement"].replace(
    {'Low':1, 'Medium':2, 'High':3}
)

df["Internet_Access"] = df["Internet_Access"].replace(
    {'Yes':1, 'No':0}
)

correlation_matrix = df.select_dtypes(include=[np.number]).corr()

sns.heatmap(correlation_matrix, annot=True, cmap='coolwarm', fmt='.2f', square=True, linewidths=.5)

plt.show()

#
from sklearn.linear_model import LinearRegression
x = np.arange(-3, 3, 0.1)
y = np.tanh(x) + np.random.randn(x.shape[0])*0.2
x = x.reshape(-1, 1)
y = y.reshape(-1, 1)
x.shape
y.shape
model = LinearRegression()
model.fit(x, y)
model.coef_

ypred = model.predict(x)