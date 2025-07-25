from decimal import Decimal

n, k = map(int, input().split())

ans = Decimal(k)
for i in range(1, k):
    ans -= Decimal(Decimal(i) / Decimal(k)) ** Decimal(n)

print(f"{ans:.200f}")