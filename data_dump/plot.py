#!/usr/bin/env python
import matplotlib
import matplotlib.pyplot as plt
import numpy as np
import argparse

parser = argparse.ArgumentParser()
parser.add_argument('-i', type=argparse.FileType('r'))
parser.add_argument('-j', type=argparse.FileType('r'))
parser.add_argument('-k', type=argparse.FileType('r'))
parser.add_argument('-o')
args = parser.parse_args()

brute = np.loadtxt(args.i)
segment = np.loadtxt(args.j)
fenwick = np.loadtxt(args.k)

plt.plot(brute[:, 0], brute[:, 1], color="red", label="Brute Force approach")
plt.plot(segment[:, 0], segment[:, 1], color="blue", label="Segment Tree")
plt.plot(fenwick[:, 0], fenwick[:, 1], color="green", label="Fenwick Tree")

plt.legend(bbox_to_anchor=(0, 1), loc='upper left', borderaxespad=0)
plt.subplots_adjust(left=0.15, top=0.9, bottom=0.1)

plt.xlabel("Sum of update and query operations")
plt.ylabel("Time (microseconds)")
plt.savefig(args.o)
