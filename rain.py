import requests 
from datetime import datetime
import time
# Make a get request to get the latest position of the international space station from the opennotify api.
response = requests.get('http://api.openweathermap.org/data/2.5/forecast?q=Toronto,CA&APPID=8e5182a3d7224b0e6dafc0ed9fd635d0')
# Print the status code of the response.

f= open("rain.txt","w+")
  
upcoming = []
data = response.json()

 #print(data['list'][0]['dt'])
currtime = time.time()

for hourly in  data['list']:
    if hourly['dt'] <= currtime + 86400:
        a = hourly['weather']
        b = a[0]['main']
        upcoming.append(b)
    else:
        continue
#f.write(str(upcoming))
#f.write('\n')
if 'Rain' in upcoming:
    f.write("Rain\n")
else:
    f.write("Dry\n")  

                                                              # api.openweathermap.org/data/2.5/forecast?q=Toronto,CA&cnt=1&APPID=8e5182a3d7224b0e6dafc0ed9fd635d0





