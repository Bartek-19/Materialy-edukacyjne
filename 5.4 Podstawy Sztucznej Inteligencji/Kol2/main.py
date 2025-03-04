import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import tensorflow as tf
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from keras.api.models import Sequential
from keras.api.regularizers import l1
from keras.api.optimizers import Adam
from keras.api.datasets import fashion_mnist
from keras.api.layers import Dense, Input, BatchNormalization, Dropout, GaussianNoise, Lambda, \
MaxPooling2D, AveragePooling2D, Conv2D, GlobalAveragePooling2D


# Zadanie 1
data = pd.read_csv("data2.csv")
X = data.drop("class", axis=1)
Y = data["class"]
X_train, X_test, Y_train, Y_test = train_test_split(X, Y, test_size=0.25, random_state=42, shuffle=True, stratify=Y)

scaler = StandardScaler()
X_train = scaler.fit_transform(X_train, Y_train)
X_test = scaler.fit_transform(X_test, Y_test)

def act_func(x):
    return 0.5*(1.1+tf.math.erf(x/tf.math.sqrt(2.5)))

model = Sequential()
model.add( Input(shape=X_train.shape[1:]) )
model.add( Dense(128, activation=act_func) )
model.add( Dropout(0.1) )
model.add( Dense(64, activation="relu", kernel_regularizer=l1(0.001)) )
model.add( Dense(32, activation="relu", kernel_regularizer=l1(0.001)) )
model.add( Dense(3, activation="softmax") )

model.compile(optimizer=Adam(0.001), loss="sparse_categorical_crossentropy", metrics=["accuracy"])
model.fit(x=X_train, y=Y_train, validation_data=(X_test, Y_test), batch_size=16, epochs=10)

test_loss, test_accuracy = model.evaluate(X_test, Y_test, verbose=0)

##########
#Zadanie 2
##########

(X_train, Y_train), (X_test, Y_test) = fashion_mnist.load_data()

model2 = Sequential()
plt.imshow(X_test[5,10:28,0:28:2])

X_train = np.expand_dims(X_train, axis=-1) 
X_test = np.expand_dims(X_test, axis=-1)

Y_train = pd.get_dummies(Y_train)
Y_train = Y_train.replace( {True:1, False:0} )

Y_test = pd.get_dummies(Y_test)
Y_test = Y_test.replace( {True:1, False:0} )

model2.add( Input(shape=X_train.shape[1:]) )
model2.add( Conv2D(32, (3,3), activation='gelu', padding='same') )
model2.add( Conv2D(32, (3,3), activation='gelu', padding='same') )
model2.add( MaxPooling2D(pool_size=(2,2)) )
model2.add( Conv2D(32, (3,3), activation='gelu', padding='valid') )
model2.add( AveragePooling2D(pool_size=(3,3)) )
model2.add( GlobalAveragePooling2D() )
model2.add( Dense(128, activation='relu') )
model2.add( Dense(64, activation='relu') )
model2.add( Dense(10, activation='softmax') )

model2.compile(loss = 'categorical_crossentropy', metrics = ['accuracy'], optimizer = Adam(0.001))
model2.fit(X_train, Y_train, epochs=1, validation_data=(X_test, Y_test), verbose=1)

