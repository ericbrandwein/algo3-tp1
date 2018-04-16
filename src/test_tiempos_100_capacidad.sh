#!/bin/bash
for i in {0..25}; do
	capacidad=$(( $i * 4))
	filename="7_items_${capacidad}_capacidad.data"
	./test_tiempos.sh 7 $capacidad > $filename
	echo "outputeado $filename"
done
