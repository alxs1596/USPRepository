
import numpy as np
N = int(input())
for _ in range (N):
    n = int(input())
    coins = [int(c) for c in input().split(' ')]
    X = 1
    y = 1
    res = 1
    for icoin in range(1,n - 1):
        coin = coins[icoin]
        nextcoin = coins[icoin+1]
        if (X + coin < nextcoin):
            X = X + coin
            res += 1
    res += 1
    print(res)
    