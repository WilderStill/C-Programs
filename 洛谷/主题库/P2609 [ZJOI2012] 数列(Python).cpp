def ans(n,s={}):
    if n==0:
        return 0
    elif n==1:
        return 1
    elif n in s:
        return s[n]
    else:
        i=n//2
        if n%2==0:
            res=ans(i,s)
        else:
            res=ans(i,s)+ans(i+1,s)
        s[n]=res
        return res

t=int(input())
for i in range(t):
    n=int(input())
    print(ans(n))
