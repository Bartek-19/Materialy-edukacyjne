from keras.api.layers import Dense, Input, BatchNormalization
from keras.api.layers import Dropout, GaussianNoise
from keras.api.layers import LayerNormalization
from keras.api.models import Sequential
from keras.api.optimizers import Adam, SGD
from keras.api.regularizers import l2, l1
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
from sklearn.model_selection import train_test_split

def plot_model_metrics(model, epochs=1000):
    historia = model.history.history
    floss_train = historia['loss']
    floss_test = historia['val_loss']
    acc_train = historia['accuracy']
    acc_test = historia['val_accuracy']
    fig,ax = plt.subplots(1,2, figsize=(20,10))
    epo = np.arange(0, epochs)
    ax[0].plot(epo, floss_train, label = 'floss_train')
    ax[0].plot(epo, floss_test, label = 'floss_test')
    ax[0].set_title('Funkcje strat')
    ax[0].legend()
    ax[1].set_title('Dokladnosci')
    ax[1].plot(epo, acc_train, label = 'acc_train')
    ax[1].plot(epo, acc_test, label = 'acc_test')
    ax[1].legend()

def plot_model_metrics(model, epochs=1000):
    historia = model.history.history
    floss_train = historia['loss']
    floss_test = historia['val_loss']
    acc_train = historia['accuracy']
    acc_test = historia['val_accuracy']
    fig,ax = plt.subplots(1,2, figsize=(20,10))
    epo = np.arange(0, epochs)
    ax[0].plot(epo, floss_train, label = 'floss_train')
    ax[0].plot(epo, floss_test, label = 'floss_test')
    ax[0].set_title('Funkcje strat')
    ax[0].legend()
    ax[1].set_title('Dokladnosci')
    ax[1].plot(epo, acc_train, label = 'acc_train')
    ax[1].plot(epo, acc_test, label = 'acc_test')
    ax[1].legend()

model = Sequential()
model.add(Dense(128, activation='relu', input_shape = (10,), kernel_regularizer = l2(0.01)))

neuron_num  = 64
do_rate = 0.5
noise = 0.1
learning_rate = 0.001
block = [
            Dense,
            LayerNormalization,
            BatchNormalization,
            Dropout,
            GaussianNoise]
args = [
        (neuron_num,'selu'),(),(),(do_rate,),(noise,)]
model = Sequential()
model.add(Dense(neuron_num, activation='relu',
                input_shape = (10,)))
repeat_num = 2
for i in range(repeat_num):
    for layer,arg in zip(block, args):
        model.add(layer(*arg))
model.add(Dense(1, activation='sigmoid'))
model.compile(optimizer= Adam(learning_rate), loss='binary_crossentropy', metrics=('accuracy', 'Recall', 'Precision'))