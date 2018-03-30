#!/bin/bash

for i in {0..15}
do
	generated=$(python generate-test.py $i)
	echo $generated | ./fuerza_bruta | read res1
	echo $generated | ./backtracking | read res2
	echo $generated | ./meet_in_the_middle | read res3
	[ $res1 -eq $res2 ] && [ $res2 -eq $res3 ] && echo "bien" || \
	echo -e "mal\n$res1\n$res2\n$res3\n$generated"
done