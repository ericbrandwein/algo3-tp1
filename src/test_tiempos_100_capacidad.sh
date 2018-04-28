#!/bin/bash
for i in {0..25}; do
	capacidad=$(( $i * 4))
	filename="20_items_${capacidad}_capacidad.data"
	./test_tiempos.sh 20 $capacidad > $filename
	echo "outputeado $filename"
done
