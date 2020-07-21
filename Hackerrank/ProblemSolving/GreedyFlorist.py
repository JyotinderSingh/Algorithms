n,k = map(int,input().split())
costs = list(map(int, input().split()))
costs = sorted(costs, reverse=True)
nums = [0] * k
cost = 0
i = 0
j = 0
while n:
     cost += (nums[i] + 1) * costs[j]
     nums[i] += 1
     i = (i + 1) % k
     j += 1
     n -= 1
print(cost)