#!/bin/python3

import math
import os
import random
import re
import sys


def num_occurrences(string, substring):
    count = 0
    start = 0
    while start < len(string):
        flag = string.find(substring, start)
        if flag != -1:
            start = flag + 1
            count += 1
        else:
            break
    return count

def determineHealths(genes, health, dna):
    total_health = 0
    for i in range(len(genes)):
        total_health += num_occurrences(dna, genes[i])*health[i]
    
    return total_health





if __name__ == '__main__':
    n = int(input())

    genes = input().rstrip().split()

    health = list(map(int, input().rstrip().split()))

    s = int(input())

    health_list = []
    for s_itr in range(s):
        firstLastd = input().split()

        first = int(firstLastd[0])

        last = int(firstLastd[1])

        d = firstLastd[2]

        result = determineHealths(genes[first:last+1], health[first:last+1], d)
        health_list.append(result)
    
    health_list.sort()
    print("{weak} {strong}".format(weak=health_list[0], strong=health_list[-1]))
