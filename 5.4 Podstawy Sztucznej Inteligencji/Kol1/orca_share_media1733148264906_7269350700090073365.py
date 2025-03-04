# -*- coding: utf-8 -*-
"""
Created on Sun Dec  1 09:47:51 2024

@author: User01
"""

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns

df = pd.read_csv("Wine_Dataset.csv", sep = ",")
print("Pierwsze 5 pierwsyz danych:")
print(df.head())

print("Opis danych statystycznych:")
print(df.describe())

print("Informacje o danych:")
print(df.info())

# Wizualizacja rozkładu cechy 'alcohol'
plt.figure(figsize=(12, 5))

plt.subplot(1,2,1)
plt.hist(df['Alcohol'], bins=20, edgecolor='black',color='skyblue')
plt.title('Rozkład cechy Alcohol')
plt.xlabel('Alcohol')
plt.ylabel('Liczba obserwacji')

# Wizualizacja rozkładu cechy 'color_intensity'
plt.subplot(1, 2, 2)
plt.hist(df['Color intensity'], bins=20, edgecolor='black', color='skyblue')
plt.title('Rozkład cechy Color Intensity')
plt.xlabel('Color Intensity')
plt.ylabel("liczba obserwacji")

plt.tight_layout()
plt.show()

plt.figure(figsize=(6, 5))
plt.boxplot(df['Magnesium'], vert=False, patch_artist=True, boxprops=dict(facecolor='skyblue', color='black'))
plt.title('Boxplot dla cechy Magnesium')
plt.xlabel('Magnesium')
plt.show()

unique_values = df['Magnesium'].nunique()
median_value = df['Magnesium'].median()
mean_value = df['Magnesium'].mean()

print(f"Występują {unique_values} wartości odstające")
print(f"Mediana cechy magnesium wynosi: {median_value}")
print(f"Średnia wartość cechy magnesium wynosi: {mean_value}")

correlation_matrix = df.corr()
plt.figure(figsize=(12, 8))
sns.heatmap(correlation_matrix, annot=True, fmt=".2f", cmap='coolwarm')
plt.title('Macierz korelacji dla cech ze zbioru Wine_Dataset')
plt.show()

target_feature = 'Alcohol'

# Cecha najmocniej skorelowana dodatnio z cechą zależną (wyłączając cechę zależną samą w sobie)
most_positive_corr = correlation_matrix[target_feature].drop(target_feature).idxmax()
most_positive_corr_value = correlation_matrix[target_feature].drop(target_feature).max()

# Cecha najmocniej skorelowana ujemnie z cechą zależną
most_negative_corr = correlation_matrix[target_feature].drop(target_feature).idxmin()
most_negative_corr_value = correlation_matrix[target_feature].drop(target_feature).min()

# Najmocniej skorelowane dodatnio cechy (wyłączając diagonalę)
correlation_matrix_no_diag = correlation_matrix.where(np.triu(np.ones(correlation_matrix.shape), k=1).astype(bool))
most_correlated_pair = correlation_matrix_no_diag.stack().idxmax()
most_correlated_pair_value = correlation_matrix_no_diag.stack().max()

# Wyświetlenie wyników
print(f"Cecha najmocniej skorelowana dodatnio z\ncechą zależną ({target_feature}): {most_positive_corr} (korelacja: {most_positive_corr_value:.2f})")
print(f"Cecha najmocniej skorelowana ujemnie z\ncechą zależną ({target_feature}): {most_negative_corr} (korelacja: {most_negative_corr_value:.2f})")
print(f"Najmocniej skorelowane dodatnio cechy: {most_correlated_pair} (korelacja: {most_correlated_pair_value:.2f})")

from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.neighbors import KNeighborsClassifier
from sklearn.svm import SVC
from sklearn.tree import DecisionTreeClassifier
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import confusion_matrix, accuracy_score, f1_score, ConfusionMatrixDisplay

# Podział cech niezależnych (X) i zależnej (y)
X = df.iloc[:, :-1].values  # Cechy niezależne (wszystkie kolumny oprócz ostatniej)
y = df.iloc[:, -1].values   # Cecha zależna (ostania kolumna, czyli typ wina: 0, 1, 2)

# Skalowanie cech numerycznych
scaler = StandardScaler()
X_scaled = scaler.fit_transform(X)

# Podział zbioru na treningowy i testowy
X_train, X_test, y_train, y_test = train_test_split(X_scaled, y, test_size=0.3, random_state=29, shuffle=True)

# Definicja modeli
models = {
    'k-NN': KNeighborsClassifier(n_neighbors=5),
    'SVM': SVC(kernel='rbf', random_state=29),
    'Decision Tree': DecisionTreeClassifier(random_state=29, criterion='entropy'),
    'Random Forest': RandomForestClassifier(random_state=29)
}

# Inicjalizacja zmiennych do oceny modeli
best_model = None
worst_model = None
best_accuracy = 0
worst_accuracy = 1
best_f1 = 0
worst_f1 = 1

# Trening i ocena modeli
for model_name, model in models.items():
    print(f"\nTrening modelu: {model_name}")
    
    # Trening modelu
    model.fit(X_train, y_train)
    
    # Predykcje
    y_pred = model.predict(X_test)
    
    # Obliczanie wyników
    accuracy = accuracy_score(y_test, y_pred)
    f1 = f1_score(y_test, y_pred, average='weighted')  # Używamy 'weighted' aby uzyskać średnią ważoną F1
    
    # Wyświetlanie macierzy pomyłek
    cm = confusion_matrix(y_test, y_pred)
    cm_display = ConfusionMatrixDisplay(confusion_matrix=cm)
    cm_display.plot(cmap='Blues')
    plt.title(f"Macierz pomyłek - {model_name}")
    plt.xlabel('Predykcje')
    plt.ylabel('Prawdziwe etykiety')
    plt.show()
    
    print(f"Model {model_name}:")
    print(f" - Accuracy: {accuracy:.2f}")
    print(f" - F1 Score: {f1:.2f}")
    
    # Sprawdzanie najlepszego i najgorszego modelu
    if accuracy > best_accuracy:
        best_accuracy = accuracy
        best_f1 = f1
        best_model = model_name
    
    if accuracy < worst_accuracy:
        worst_accuracy = accuracy
        worst_f1 = f1
        worst_model = model_name

# Podsumowanie wyników
print("\nNajlepszy model:")
print(f"{best_model} z Accuracy = {best_accuracy:.2f} i F1 Score = {best_f1:.2f}")

print("\nNajgorszy model:")
print(f"{worst_model} z Accuracy = {worst_accuracy:.2f} i F1 Score = {worst_f1:.2f}")
