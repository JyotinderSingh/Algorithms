from math import inf

def getChange(m):
    coins = [1, 3, 4]

    min_coins = [None] * (m + 1)
    min_coins[0] = 0

    for i in range(1, m + 1):
        min_coins[i] = inf
        for coin in coins:
            if i >= coin:
                tmp = min_coins[i - coin] + 1
                if tmp < min_coins[i]:
                    min_coins[i] = tmp
            else:
                # use continue if coin list is not in order
                break

    return min_coins[m]


if __name__ == '__main__':
    m = int(input())
    print(getChange(m))
