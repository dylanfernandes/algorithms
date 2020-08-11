#!/bin/python3

import sys

def countApplesAndOranges(s, t, a, b, apples, oranges):
    print (calculateScore(s, t, a, apples))
    print (calculateScore(s, t, b, oranges))
    
def calculateScore(s, t, tree, locations):
    score = 0
    for loc in locations:
        dest = tree + loc
        if dest >= s and dest <= t:
            score = score + 1
    return score
            
if __name__ == "__main__":
    s, t = input().strip().split(' ')
    s, t = [int(s), int(t)]
    a, b = input().strip().split(' ')
    a, b = [int(a), int(b)]
    m, n = input().strip().split(' ')
    m, n = [int(m), int(n)]
    apple = list(map(int, input().strip().split(' ')))
    orange = list(map(int, input().strip().split(' ')))
    countApplesAndOranges(s, t, a, b, apple, orange)