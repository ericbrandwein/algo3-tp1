#!/bin/bash
for i in {0..25}; do
	capacidad=$(( $i * 4 + 50 ))
	filename="data/15_items_${capacidad}_capacidad.data"
	./test_tiempos.sh 15 $capacidad > $filename
	echo "outputeado $filename"
done
