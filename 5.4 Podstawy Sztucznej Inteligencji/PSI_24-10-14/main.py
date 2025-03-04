import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

np.random.randn(10)

import numpy as np
arr = np.array([[2,3,5,1], 
                [5,1,2,8], 
                [5,1,6,-1]])
pojedynczy_element = arr[0,3]
pojedynczy_element_od_konca = arr[-3,-1]
print(pojedynczy_element)
print(pojedynczy_element_od_konca)

kolumna = arr[:,0]
wiersz = arr[2,:]
obszar = arr[0:2,1:4]
obszar_pomijajac_koncowe_indeksy = arr[:2,1:]
parzyste_kolumny = arr[:,::2]
nieparzyste_kolumny = arr[:,1::2]
odwrócone_kolumny = arr[:,::-1]

print(kolumna, '\n')
print(wiersz, '\n')
print(obszar, '\n')
print(obszar_pomijajac_koncowe_indeksy, '\n')
print(parzyste_kolumny, '\n')
print(nieparzyste_kolumny, '\n')
print(odwrócone_kolumny, '\n')

indeksy = [1, 1, -1]
wybrane_kolumny = arr[:,indeksy]
maska = arr>2
arr_maskowane = arr[maska]

data_frame = pd.read_csv("StudentPerformanceFactors.csv")
