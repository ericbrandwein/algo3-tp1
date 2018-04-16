#!/bin/bash

for i in {0..100}
do
	# $1 = cant items
	# $2 = capacidad
	generated=$(python generate-test.py $1 $2 10)
	echo $generated | ./tiempos
done