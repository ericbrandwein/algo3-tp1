#!/bin/bash

for i in {0..15}
do
	generated=$(python generate-test.py $i)
	res1=$(echo $generated | ./fuerza_bruta)
	res2=$(echo $generated | ./backtracking)
	res3=$(echo $generated | ./meet_in_the_middle)
	res4=$(echo $generated | ./dinamica)
	[ $res1 -eq $res2 ] && [ $res2 -eq $res3 ] && [ $res3 -eq $res4 ] && \
	echo "bien" || echo -e "mal\n$res1\n$res2\n$res3\n$generated"
done