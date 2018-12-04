import numpy as np

value = [0, 2, 5, 3, 10, 4]
weights = [0, 1, 3, 2, 6, 2]

n = 5
max_weights = 12

x = np.zeros([n + 1, max_weights + 1])

for i in range(1, n + 1):
    for j in range(max_weights, 0, -1):
        if j < weights[i]:
            x[i, j] = x[i - 1, j]
        else:
            x[i, j] = max(x[i - 1, j], x[i - 1, j - weights[i]] + value[i])
print(x)

# 回溯找路径
item = [0] * (n + 1)


def find(i, j, best):
    if i >= 0:
        if x[i, j] == x[i - 1, j]:  # 没选
            best = find(i - 1, j, best)
        elif j - weights[i] >= 0 and x[i, j] == x[i - 1, j - weights[i]] + value[i]:
            best[i] = 1
            best = find(i - 1, j - weights[i], best)
    return item


best = find(n, max_weights, item)
print('最优解路径是：', best)
max_value = []
for i in range(len(weights)):
    if best[i] == 1:
        max_value.append(value[i])

print('最大价值是：', sum(max_value))
