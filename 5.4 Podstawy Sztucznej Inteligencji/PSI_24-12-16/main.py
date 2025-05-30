from keras.api.layers import Conv2D, Flatten, Dense, AveragePooling2D, MaxPooling2D
from keras.api.models import Sequential
from keras.api.optimizers import Adam
from keras.api.datasets import mnist
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.metrics import confusion_matrix

def cm_for_nn(model, X_test, y_test):
    # y_pred jest 10 wymiarowym wektorem, będącym rozkładem
    # prawdopodobieństwa (softmax w ostatniej warstwie)
    y_pred = model.predict(X_test)
    # Znajdź w każdym wierszu macierzy y_pred indeks
    # elementu, który zawiera największą wartość i zwróć
    # numer indeksu.
    y_pred_classes = np.argmax(y_pred, axis=1)

    cm = confusion_matrix(y_test, y_pred_classes)
    sns.heatmap(cm, annot=True, fmt='d', cmap='viridis')
    plt.xlabel('Wartosci przewidziane')
    plt.ylabel('Wartości rzeczywiste')
    plt.title('Confusion Matrix')
    plt.show()

train, test = mnist.load_data()
X_train, y_train = train[0], train[1]
X_test, y_test = test[0], test[1]
X_train = np.expand_dims(X_train, axis=-1)
X_test = np.expand_dims(X_test, axis=-1)
class_cnt = np.unique(y_train).shape[0]
filter_cnt = 32
neuron_cnt = 32
learning_rate = 0.0001
act_func = 'relu'
kernel_size = (3,3)
pooling_size = (2,2)
model = Sequential()
conv_rule = 'same'

model.add(Conv2D(input_shape = X_train.shape[1:],
        filters=filter_cnt,
        kernel_size = kernel_size,
        padding = conv_rule,
        activation = act_func))
model.add(MaxPooling2D(pooling_size))
model.add(Flatten())
model.add(Dense(class_cnt, activation='softmax'))
model.compile(optimizer=Adam(learning_rate),
            loss='SparseCategoricalCrossentropy',
            metrics=['accuracy'])
model.fit(x = X_train, y = y_train,
        epochs = class_cnt ,
        validation_data=(X_test, y_test))

plot_model_metrics(model, 10)
cm_for_nn(model, X_test, y_test)