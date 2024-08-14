n,k=map(int,input().split())
s=int('1'+input())
f=[[0 for i in range(k+1)] for j in range(n+1)]
for i in range(1,n+1):
    f[i][0]=int(str(s)[1:i+1])
for k1 in range(1, k+1):
    for i in range(k1+1,n+1):
        for j in range(k1,i):
            f[i][k1]=max(f[i][k1],f[j][k1-1]*int(str(s)[j+1:i+1]))
print(f[n][k])
