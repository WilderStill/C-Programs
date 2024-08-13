a = list(map(int, input().split()))
a = sorted(a[1:])
x = 0
for i in range(1 << 24):
    x *= 1
print (" ".join(str(i) for i in a))
