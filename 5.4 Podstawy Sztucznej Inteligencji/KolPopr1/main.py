#Bartosz Klimiuk

import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import seaborn as sns
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.neighbors import KNeighborsClassifier as kNN
from sklearn.svm import SVC as SVM
from sklearn.tree import DecisionTreeClassifier
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import confusion_matrix, accuracy_score, f1_score

########
# Etap 1
########

dataFrame = pd.read_csv('data.csv')
dataFrame.head()
dataFrame.info()

x1 = dataFrame["alcohol"].values
x2 = dataFrame["color_intensity"].values
x3 = dataFrame["magnesium"].values

plt.figure(figsize=(12, 5))
plt.subplot(1,2,1)
plt.hist(x1, bins=20, edgecolor='black',color='skyblue')
plt.title('Rozkład cechy "Alcohol"')
plt.xlabel('Alcohol')
plt.ylabel('Liczba obserwacji')

plt.subplot(1, 2, 2)
plt.hist(x2, bins=20, edgecolor='black', color='skyblue')
plt.title('Rozkład cechy "Color Intensity"')
plt.xlabel('Color Intensity')
plt.ylabel("liczba obserwacji")
plt.tight_layout()
plt.show()

plt.title('Boxplot dla cechy Magnesium')
plt.xlabel('Magnesium')
plt.boxplot(x3)
plt.show()

outliers = np.abs((x3 - x3.mean())/x3.std())>3
outliersArray = x3[outliers]
mediana = np.median(x3)
srednia = np.mean(x3)
print("Występują ", len(outliersArray)," wartości odstające")
print(f"Mediana cechy magnesium wynosi {mediana:.2f}")
print(f"Srednia wartosc cechy magnesium wynosi {srednia:.2f}")

########
# Etap 2
########

matrix = dataFrame.corr()
plt.figure(figsize=(14, 14))
sns.heatmap(matrix, annot=True, cmap='coolwarm', square=True)
plt.show()

print("Cechą najmocniej skorelowaną dodatnio z cechą zależną: 'alcalinity_of_ash'")
print("Cechą najmocniej skorelowana ujemnie z cechą zależną: 'flavianoids'")
print("Najmocniej skorelowane dodatnio cechy: 'flavanoids' z 'total_phenols'")

########
# Etap 3
########

data = dataFrame.values
dane_niezalezne, dane_zalezne = np.array(data[:, :-1]), np.array(data[:, -1])
scaler = StandardScaler()
scaler.fit(dane_niezalezne)
dane_niezalezne = scaler.transform(dane_niezalezne)
dataFrame.iloc[:, :-1] = dane_niezalezne
x_train, x_test, y_train, y_test = train_test_split(dane_niezalezne, dane_zalezne, test_size=0.3, random_state=29, shuffle=True)

########
# Etap 4
########

models = [
    kNN(n_neighbors=5),
    SVM(kernel='rbf', random_state=29),
    DecisionTreeClassifier(random_state=29),
    DecisionTreeClassifier(random_state=29, criterion='entropy'),
    RandomForestClassifier(random_state=29)
]

model_names = ["kNN, k=5", "SVM", "Drzewo decyzyjne", "Drzewo decyzyjne z entropią", "Las losowy"]

accuracies = []
f1s = []

for model, name in zip(models, model_names):
    model.fit(x_train, y_train)
    y_pred = model.predict(x_test)
    
    accuracy = accuracy_score(y_test, y_pred)
    accuracies.append(accuracy)
    f1 = f1_score(y_test, y_pred, average='weighted')
    f1s.append(f1)

    cm = confusion_matrix(y_test, y_pred)
    sns.heatmap(cm, annot=True, cmap='Blues')
    plt.xlabel("Predykcje")
    plt.ylabel("Wartości rzeczywiste")
    plt.title(f"Macierz pomyłek dla {name}, (Accuracy: {accuracy:.7f}, F1-score: {f1:.7f})")
    plt.show()

print(f"Najlepszy model to '{model_names[3]}' z metrykami: Acc={accuracies[3]}, F1={f1s[3]}")
print(f"Najgorszy model to '{model_names[2]}' z metrykami: Acc={accuracies[2]}, F1={f1s[2]}")