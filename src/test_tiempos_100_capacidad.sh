#!/bin/bash
for i in {0..40}; do
	capacidad=$(( $i * 500 + 50 ))
	filename="data/15_items_${capacidad}_capacidad_5_peso_maximo.data"
	./test_tiempos.sh 15 $capacidad > $filename
	echo "outputeado $filename"
done
