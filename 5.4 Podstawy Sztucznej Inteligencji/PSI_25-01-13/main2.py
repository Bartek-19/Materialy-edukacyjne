from keras.api.models import Model 
from keras.api.layers import Input, Dense, Dropout, Reshape, BatchNormalization, Lambda 
from keras.api.optimizers import Adam 
from keras.api.datasets import fashion_mnist 
import pandas as pd 
import numpy as np 
from keras import backend as K 
def adding_noise(tensor): 
    noise = K.random_normal(shape=(K.shape(tensor)), mean=0, stddev=1.5) 
    return tensor + noise

data = fashion_mnist.load_data() 
X_train, y_train = data[0][0], data[0][1] 
X_test, y_test = data[1][0], data[1][1] 
X_train = np.expand_dims(X_train, axis = -1) 
X_test = np.expand_dims(X_test, axis = -1) 
y_train = pd.get_dummies(pd.Categorical(y_train)).values 
y_test = pd.get_dummies(pd.Categorical(y_test)).values 

act_func = 'selu' 
hidden_dims = 64 
encoder_layers = [ 
            Reshape((28*28,)), 
            BatchNormalization(), 
            Dense(512,activation=act_func), 
            Dense(128,activation=act_func), 
            Dense(64, activation=act_func), 
            Dense(hidden_dims, activation=act_func)] 
tensor = encoder_input = Input(shape = (28,28)) 
for layer in encoder_layers: 
    tensor = layer(tensor)  
encoder_output = tensor     
encoder = Model(inputs=encoder_input, outputs=encoder_output)

decoder_layers = [ 
                  Dense(128,activation=act_func), 
                  Dense(512,activation=act_func), 
                  Dense(784,activation='sigmoid'), 
                  Reshape((28,28)), 
                  Lambda(lambda x: x*255)]  
decoder_input = Input(shape=(hidden_dims,))  
tensor = decoder_input 
for layer in decoder_layers: 
    tensor = layer(tensor) 
decoder_output = tensor 
decoder = Model(inputs = decoder_input, outputs = decoder_output) 

aec_output = decoder(encoder(encoder_input)) 
gen_autoencoder = Model(inputs = encoder_input, outputs = aec_output) 
gen_autoencoder .compile(optimizer =  Adam(20.0), loss = 'MeanSquaredError') #Adam(x), x - learning rate
gen_autoencoder .fit(x=X_train,y=X_train, validation_data=(X_test, X_test), batch_size=256, epochs=10) 

noised_encoder_output =Lambda(adding_noise)(encoder_output) 
augmenter_output = decoder(noised_encoder_output) 
augmenter = Model(inputs = encoder_input, outputs = augmenter_output) 