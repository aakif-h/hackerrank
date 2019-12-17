#!/bin/python

from __future__ import print_function

import os
import sys

# Complete the solve function below.
def solve(arr, queries):
    queries_ans = []
    potential_answers = ['Even', 'Odd']

    base = 0
    for i in queries:
        start = i[0] - 1
        end = i[1] - 1

        if start == end or arr[start+1] != 0:
            base = arr[start]
        else:
            base = 1

        queries_ans.append(potential_answers[base % 2])

    return queries_ans


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    arr_count = int(raw_input())

    arr = map(int, raw_input().rstrip().split())

    q = int(raw_input())

    queries = []

    for _ in xrange(q):
        queries.append(map(int, raw_input().rstrip().split()))

    result = solve(arr, queries)

    fptr.write('\n'.join(result))
    fptr.write('\n')

    fptr.close()
