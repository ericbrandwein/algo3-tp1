import pandas as pd
import matplotlib.pyplot as plt
import pylab as pl
import random
import numpy as np
import re

def promedio(valores):
    prom = 0
    for valor in valores:
        prom += float(valor)
    return prom / len(valores)

promedios = []
for i in range(16):
    nombreArchivo = "{}_items_100_capacidad.data".format(i)
    with open(nombreArchivo) as archivo:
        valores = archivo.read()
        valores = re.findall(r"[\w|\.]+", valores)
        valoresFuerzaBruta = valores[0::4]
        valoresMeet = valores[1::4]
        valoresBacktracking = valores[2::4]
        valoresDinamica = valores[3::4]

        promedios.append(promedio(valoresFuerzaBruta))
        promedios.append(promedio(valoresMeet))
        promedios.append(promedio(valoresBacktracking))
        promedios.append(promedio(valoresDinamica))

plt.clf()
df = pd.DataFrame(
    {#'Fuerza bruta': promedios[0::4],
     'Meet in the Middle': promedios[1::4],
     'Backtracking': promedios[2::4],
    'Dinamica': promedios[3::4],
    'Cantidad de ítems': list(range(16))})
df.plot(x='Cantidad de ítems', logy=True)
plt.ylabel('Tiempo (ms)')
plt.show()

promedios = []
for i in range(16):
    nombreArchivo = "{}_items_100_capacidad.data".format(i)
    with open(nombreArchivo) as archivo:
        valores = archivo.read()
        valores = re.findall(r"[\w|\.]+", valores)
        valoresMeet = valores[1::4]
        valoresBacktracking = valores[2::4]
        valoresDinamica = valores[3::4]
        promedios.append(promedio(valoresMeet))
        promedios.append(promedio(valoresBacktracking))
        promedios.append(promedio(valoresDinamica))

for i in range(16,31):
    nombreArchivo = "{}_items_100_capacidad_sin_fuerza.data".format(i)
    with open(nombreArchivo) as archivo:
        valores = archivo.read()
        valores = re.findall(r"[\w|\.]+", valores)
        valoresMeet = valores[0::3]
        valoresBacktracking = valores[1::3]
        valoresDinamica = valores[2::3]

        promedios.append(promedio(valoresMeet))
        promedios.append(promedio(valoresBacktracking))
        promedios.append(promedio(valoresDinamica))

plt.clf()

df = pd.DataFrame(
    {#'Fuerza bruta': promedios[0::4],
     'Meet in the Middle': promedios[0::3],
     'Backtracking': promedios[1::3],
    'Dinamica': promedios[2::3],
    'Cantidad de ítems': list(range(int(len(promedios)/3)))})
df.plot(x='Cantidad de ítems')
plt.ylabel('Tiempo (ms)')
plt.show()

promedios = []

for i in range(0, 101, 4):
    nombreArchivo = "7_items_{}_capacidad.data".format(i)
    with open(nombreArchivo) as archivo:
        valores = archivo.read()
        valores = re.findall(r"[\w|\.]+", valores)
        valoresFuerza = valores[0::4]
        valoresMeet = valores[1::4]
        valoresBacktracking = valores[2::4]
        valoresDinamica = valores[3::4]

        promedios.append(promedio(valoresFuerza))
        promedios.append(promedio(valoresMeet))
        promedios.append(promedio(valoresBacktracking))
        promedios.append(promedio(valoresDinamica))

plt.clf()
df = pd.DataFrame(
    {'Fuerza bruta': promedios[0::4],
     'Meet in the Middle': promedios[1::4],
     'Backtracking': promedios[2::4],
    'Dinamica': promedios[3::4],
    'Capacidad': list(range(0, 101, 4))})
df.plot(x='Capacidad')
plt.ylabel('Tiempo (ms)')
plt.show()