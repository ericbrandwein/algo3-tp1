#!/bin/bash
for i in {31..35}; do
	filename="${i}_items_100_capacidad_sin_fuerza.data"
	./test_tiempos.sh $i 100 > $filename
	echo "outputeado $filename"
done
