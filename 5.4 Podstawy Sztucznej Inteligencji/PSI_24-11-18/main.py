import os
import librosa
import pandas as pd
from scipy.fft import fft
import numpy as np
from matplotlib import pyplot as plt

path = 'voices_pl'
files = os.listdir(path)
fs = 16000

y = pd.read_csv('new_selected_samples.csv').values

X_raw = []
X_fft = []

for file in files:
    audio, sr = librosa.load(os.path.join(path, file), sr=fs)
    X_raw.append(audio)
    
    fft_result = np.abs(fft(audio)) / len(audio)
    X_fft.append(fft_result)

X_raw = np.array(X_raw, dtype=object)
X_fft = np.array(X_fft, dtype=object)

low_cut = 50
high_cut = 280
X_fft_cut = []

for fft_signal in X_fft:
    freq_bins = np.linspace(0, fs, len(fft_signal))
    mask = (freq_bins >= low_cut) & (freq_bins <= high_cut)
    fft_cut = fft_signal[mask]
    X_fft_cut.append(fft_cut / np.max(fft_cut))
X_fft_cut = np.array(X_fft_cut, dtype=object)

fig, ax = plt.subplots(2, 1, figsize=(10, 6))
ax[0].plot(X_raw[0])
ax[0].set_title('Surowy sygnał audio')

ax[1].scatter(np.arange(len(X_fft_cut[0])), X_fft_cut[0], s=0.5)
ax[1].set_title('Widmo FFT (po przycięciu)')
fig.tight_layout()
plt.show()

mean_num = 3
X_fft_reshaped = []

for fft_cut in X_fft_cut:
    pad_length = mean_num - (len(fft_cut) % mean_num)
    fft_padded = np.pad(fft_cut, (0, pad_length), mode='constant')
    
    reshaped = np.reshape(fft_padded, (-1, mean_num)).mean(axis=-1)
    X_fft_reshaped.append(reshaped)
X_fft_reshaped = np.array(X_fft_reshaped, dtype=object)

X_fft_final = np.array([x / np.max(x) for x in X_fft_reshaped], dtype=object)


#
# Mod1
#


import os
import librosa
import pandas as pd
from scipy.fft import fft
import numpy as np
from matplotlib import pyplot as plt
from matplotlib import rcParams
from sklearn.decomposition import PCA

path = 'voices_pl'
files = os.listdir(path)
fs = 16000

y = pd.read_csv('new_selected_samples.csv').values

X_raw = []
X_fft = []

for file in files:
    audio, sr = librosa.load(os.path.join(path, file), sr=fs)
    X_raw.append(audio)
    
    fft_result = np.abs(fft(audio)) / len(audio)
    X_fft.append(fft_result)

X_raw = np.array(X_raw, dtype=object)
X_fft = np.array(X_fft, dtype=object)

low_cut = 50
high_cut = 280
X_fft_cut = []

for fft_signal in X_fft:
    freq_bins = np.linspace(0, fs, len(fft_signal))
    mask = (freq_bins >= low_cut) & (freq_bins <= high_cut)
    fft_cut = fft_signal[mask]
    X_fft_cut.append(fft_cut / np.max(fft_cut) if np.max(fft_cut) != 0 else fft_cut)

X_fft_cut = np.array(X_fft_cut, dtype=object)

fig, ax = plt.subplots(2, 1, figsize=(10, 6))
ax[0].plot(X_raw[0])
ax[0].set_title('Surowy sygnał audio')

ax[1].scatter(np.arange(len(X_fft_cut[0])), X_fft_cut[0], s=0.5)
ax[1].set_title('Widmo FFT (po przycięciu)')
fig.tight_layout()
plt.show()

X_fft_normalized = np.array([x / np.max(x) if np.max(x) != 0 else x for x in X_fft_cut], dtype=object)

max_length = max(len(x) for x in X_fft_normalized)
X_fft_padded = np.array([np.pad(x, (0, max_length - len(x)), mode='constant') for x in X_fft_normalized])

mean = X_fft_padded.mean(axis=0)
std = X_fft_padded.std(axis=0)

X_fft_double_scaled = (X_fft_padded - mean) / (std + 1e-8)

fig, ax = plt.subplots(2, 1, figsize=(10, 6))
ax[0].plot(X_raw[0])
ax[0].set_title('Surowy sygnał audio')

ax[1].scatter(np.arange(len(X_fft_double_scaled[0])), X_fft_double_scaled[0], s=0.5)
ax[1].set_title('Widmo FFT po skalowaniu podwójnym')
fig.tight_layout()
plt.show()

from sklearn.decomposition import PCA

'''
pca = PCA(n_components=10)
X_pca = pca.fit_transform(X_fft_double_scaled)

plt.figure(figsize=(8, 6))
plt.scatter(X_pca[:, 0], X_pca[:, 1], c=y, cmap='viridis', edgecolors='k')
plt.title('PCA - pierwsze dwie składowe')
plt.xlabel('Składowa 1')
plt.ylabel('Składowa 2')
plt.colorbar(label='Płeć')
plt.grid(True)
plt.show()
'''

example = np.random.randn(500,2) 
example[:,1] *= 0.4 
rot_matrix = np.array([[1/2**0.5, 1/2**0.5], [1/2**0.5, -1/2**0.5]]) 
example = np.dot(example, rot_matrix) 
example_PCAed = PCA(2).fit_transform(example) 
rcParams['font.size'] = 32 
rcParams['font.family'] = 'Times New Roman' 
fig, ax = plt.subplots(1,2, figsize=(20, 10)) 
ax[0].scatter(example[:,0], example[:,1]) 
ax[1].scatter(example_PCAed[:,0], example_PCAed[:,1]) 
ax[0].set_xlim([-3, 3]) 
ax[0].set_ylim([-3, 3]) 
ax[1].set_xlim([-3, 3]) 
ax[1].set_ylim([-3, 3]) 
ax[0].set_xlabel('x') 
ax[0].set_ylabel('y') 
ax[1].set_xlabel('PC 1') 
ax[1].set_ylabel('PC 2') 
ax[0].set_title('Dane pierwotne') 
ax[1].set_title('Dane po PCA') 

pca_transform = PCA() 
pca_transform.fit(X_fft_double_scaled) 
variances = pca_transform.explained_variance_ratio_
cumulated_variances = variances.cumsum() 
plt.scatter(np.arange(variances.shape[0]), cumulated_variances) 
plt.yticks(np.arange(0, 1.1, 0.1)) 
PC_num = (cumulated_variances<0.95).sum() 