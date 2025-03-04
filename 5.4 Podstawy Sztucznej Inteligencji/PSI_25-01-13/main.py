from keras.api.datasets import fashion_mnist 
import pandas as pd 
import numpy as np 
import matplotlib.pyplot as plt

(x_train, y_train), (x_test, y_test) = fashion_mnist.load_data()

x_train.shape
y_train.shape

plt.imshow(x_train[0], cmap='gray')
plt.imshow(x_train[1], cmap='gray')
plt.imshow(x_train[9], cmap='gray')

y_train[0:9]

#x_train = np.expand_dims(x_train, axis=-1) poszerzenie zbioru treningowego o dodatkowy wymiar
#x_test = np.expand_dims(x_test, axis=-1)
x_train.shape

k = pd.Categorical(y_train)

p = pd.get_dummies(k).values

y_train = p.astype(int)
y_train.shape

#plt.imshow(x_train[0,:,:], cmap='gray')
#plt.imshow(x_train[0,:,5:15], cmap='gray')
#plt.imshow(x_train[0,1:10,:], cmap='gray')
#plt.imshow(x_train[0,2:20:2,:], cmap='gray')
#plt.imshow(x_train[0,::-1,:], cmap='gray')

#######

from tensorflow._api import ImageDataGenerator
obr = x_train[0,:,:]
obr = np.expand_dims(obr, axis=-1)
#obr.shape
data_gen = ImageDataGenerator(
    rotation_range=30,        # Obrót do 30 stopni
    width_shift_range=0.2,    # Przesunięcie w poziomie
    height_shift_range=0.2,   # Przesunięcie w pionie
    shear_range=0.2,          # Ścinanie
    zoom_range=0.2,           # Zoom
    horizontal_flip=True,     # Odbicie poziome
    fill_mode='nearest' 
)

img_gen = data_gen.flow(
    np.expand_dims(obr, axis = 0),
    batch_size = 1
)

obrazki = np.zeros((10, 28, 28)) #tablica 10 X 28 X 28
for i in range(10):
    img = next(img_gen)[0]
    obrazki[i] = img[:,:,0]

plt.imshow(obrazki[0], cmap='gray')