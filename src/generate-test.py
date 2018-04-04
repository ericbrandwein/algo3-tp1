#!/usr/bin/env python

import random
import sys


def generateItem(maxItemWeight):
	line = "{} {}".format(random.randrange(maxItemWeight),
		random.randrange(maxItemWeight))
	print(line)

def generate(itemCount, capacity, maxItemWeight):
	firstLine = "{} {}".format(itemCount, capacity)
	print(firstLine)
	for i in range(int(itemCount)):
		generateItem(maxItemWeight)

items = 15
if len(sys.argv) > 1:
	items = sys.argv[1]
capacity = random.randrange(10000)
if len(sys.argv) > 2:
	capacity = sys.argv[2]
maxItemWeight = 1000
if len(sys.argv) > 3:
	maxItemWeight = sys.argv[3]

generate(items, capacity, maxItemWeight)