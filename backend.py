import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

plt.show(block=True)
df = pd.read_csv('capture.csv')
r = open("rain.txt","r")
#print(df.head(5))

#print("hello,world")

x = df.iloc[:, [0,1, 2, 3, 4]].values

#print("WHAT AM I PICKING UP")
#print(x)
#Finding the optimum number of clusters for k-means classification
from sklearn.cluster import KMeans

#pplying kmeans to the dataset / Creating the kmeans classifier
kmeans = KMeans(n_clusters = 2, init = 'k-means++', max_iter = 300, n_init = 10, random_state = 0)
y_kmeans = kmeans.fit_predict(x)
#print("REEEEEEEEEEEEEEEEEEEEEEEEEEEEE")
#Visualising the clusters
#plt.scatter(x[y_kmeans == 0, 0], x[y_kmeans == 0, 1], s = 100, c = 'red', label = 'Iris-setosa')
#plt.scatter.show(x[y_kmeans == 1, 0], x[y_kmeans == 1, 1], s = 100, c = 'blue', label = 'Iris-versicolour')
#plt.scatter.show(x[y_kmeans == 2, 0], x[y_kmeans == 2, 1], s = 100, c = 'green', label = 'Iris-virginica')

# r is the flag for if it is rain.

def to_water( row):
    will_rain = r
    if will_rain and row['soil_moisture'] < 0.9:
        return 'Water'
    else:
        return 'No Water'


#Plotting the centroids of the clusters
#plt.scatter.show(kmeans.cluster_centers_[:, 0], kmeans.cluster_centers_[:,1], s = 100, c = 'yellow', label = 'Centroids')
df.columns = ['Humidity','temp', 'humidex', 'soil moisture', 'light']
df['Category'] = y_kmeans
df['Category'] = df['Category'].map({1:"No Water",0:"Water"})
#out1 = df.iloc[:, [0,1, 2, 3, 4,5]]
#out2 = df.iloc[:, [0,1, 2, 3, 4,5]].values
df['Light MA'] = df['light'].expanding().mean()
if any(df['Light MA']  < 400):
    print("NEEDS MORE SUNLIGHT")
else:
    print("Good sunlight")

if any(df['soil moisture'] < 0.9):
    if r == 'rain':
        print("No need to water, going to rain")
    else:
        print("Water your plant!")



df.to_csv(r'sensor_kmeans.csv')



