import numpy as np
import pandas as pd
import tensorflow as tf
from keras.api.datasets import mnist, cifar10
from keras.api.models import Model
from keras.api.layers import Input, Dense, Conv2D, MaxPooling2D, \
    AveragePooling2D, GlobalAveragePooling2D, concatenate, Lambda
import math
from tensorflow.keras.utils import plot_model  # Import plot_model from tensorflow.keras.utils

(x_train, y_train), (x_test, y_test) = cifar10.load_data()

x_train.shape

(x_train, y_train), (x_test, y_test) = mnist.load_data()

x_train.shape

x_train = np.expand_dims(x_train, axis=-1) # axis=-1 - automatyczne dodanie osi
x_test = np.expand_dims(x_test, axis=-1)

y_train = pd.get_dummies(pd.Categorical(y_train)).values
y_test = pd.get_dummies(pd.Categorical(y_test)).values

#input_tensor = Input(shape=(28,28,1))

input_tensor = Input(shape = x_train.shape[1:])
output_tensor = input_tensor
output_tensor.shape

act_func = "selu"
#32 - filter count
#(3,3) - kernel size
#10 - classifications count


output_tensor=Conv2D(32, (3,3), padding='same', activation = act_func)(output_tensor)

output_tensor=MaxPooling2D(pool_size=(2,2))(output_tensor)

def my_act_func(tensor):
    return tf.math.tanh(tensor) * 0.5

output_tensor = Conv2D(32, (3,3), padding='valid', activation=my_act_func)(output_tensor)
# You need to call the Conv2D layer with the input tensor

global_average_pooling_layer = GlobalAveragePooling2D() # Assign the layer to a variable
output_tensor = global_average_pooling_layer(output_tensor) # Apply the layer to the tensor

# Now you can access the output shape
output_tensor.shape

output_tensor = Dense(10, activation='relu')(output_tensor)
output_tensor = Dense(10, activation='softmax')(output_tensor)

model = Model(inputs=input_tensor, outputs=output_tensor)

model.compile(loss = 'categorical_crossentropy',
               metrics = ['accuracy'],
               optimizer = 'adam')

plot_model(model, show_shapes=True)

layers = [Conv2D(32, (3,3), activation = act_func),
          MaxPooling2D(pool_size=(2,2)),
          Conv2D(10, (3,3), activation = act_func),
          MaxPooling2D(pool_size=(2,2)),
          Conv2D(10, (3,3), activation = act_func),
          GlobalAveragePooling2D(),
          Dense(10, activation = 'softmax')]

output_tensor = input_tensor = Input(x_train.shape[1:])
for layer in layers:
    output_tensor = layer(output_tensor)

def add_inseption_module(input_tensor):
    act_func = 'relu'
    paths = [
              [Conv2D(filters = 64, kernel_size=(1,1),
               padding='same', activation=act_func)
              ],
              [Conv2D(filters = 96, kernel_size=(1,1),
               padding='same', activation=act_func),
               Conv2D(filters = 128, kernel_size=(3,3),
               padding='same', activation=act_func)
              ],
              [Conv2D(filters = 16, kernel_size=(1,1),
               padding='same', activation=act_func),
               Conv2D(filters = 32, kernel_size=(5,5),
               padding='same', activation=act_func)
              ],
              [MaxPooling2D(pool_size=(3,3),
               strides = 1, padding='same'),
               Conv2D(filters = 32, kernel_size=(1,1),
               padding='same', activation=act_func)
              ]
    ]
    for_concat = []
    for path in paths:
        output_tensor = input_tensor
        for layer in path:
            output_tensor = layer(output_tensor)
        for_concat.append(output_tensor)
    return concatenate(for_concat)

output_tensor = input_tensor = Input(x_train.shape[1:])
insept_module_cnt  = 2
for i in range(insept_module_cnt):
    output_tensor = add_inseption_module(output_tensor)

output_tensor = GlobalAveragePooling2D()(output_tensor)
output_tensor = Dense(10, activation='softmax')(output_tensor)
ANN = Model(inputs = input_tensor, outputs = output_tensor)
ANN.compile(loss = 'categorical_crossentropy', metrics = ['accuracy'], optimizer = 'adam')

plot_model(ANN, show_shapes=True)

def ReLOGU(tensor):
    mask = tensor >= 1
    tensor = tf.where(mask, tensor, 1)
    tensor = tf.math.log(tensor)
    return tensor

output_tensor = input_tensor = Input(x_train.shape[1:])
insept_module_cnt  = 2
for i in range(insept_module_cnt):
    output_tensor = add_inseption_module(output_tensor)

output_tensor = Conv2D(32, (3,3))(output_tensor)
output_tensor = Lambda(ReLOGU)(output_tensor)

output_tensor = GlobalAveragePooling2D()(output_tensor)
output_tensor = Dense(10, activation='softmax')(output_tensor)
ANN = Model(inputs = input_tensor, outputs = output_tensor)
ANN.compile(loss = 'categorical_crossentropy', metrics = ['accuracy'], optimizer = 'adam')

plot_model(ANN, show_shapes=True)