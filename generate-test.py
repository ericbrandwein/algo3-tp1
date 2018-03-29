#!/usr/bin/env python

import random
import sys


def generateItem():
	line = "{} {}".format(random.randrange(1000), random.randrange(1000))
	print(line)

def generate(itemCount):
	firstLine = "{} {}".format(itemCount, random.randrange(10000))
	print(firstLine)
	for i in range(int(itemCount)):
		generateItem()


generate(sys.argv[1])