from decimal import Decimal, getcontext

getcontext().prec = 50

n = int(input())
v = list(map(Decimal, input().split()))

ans = Decimal(0)
for i in range(n):
    for j in range(i + 1, n):
        ans += (min(v[i], v[j]) * (min(v[i], v[j]) - 1) / 2 + max(0, v[i] - v[j]) * v[j]) / (v[i] * v[j])

print(f"{ans:.6f}")