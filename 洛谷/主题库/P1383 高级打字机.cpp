#include<bits/stdc++.h>
#include<ext/rope>
using namespace std;
using namespace __gnu_cxx;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch))
	{
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(isdigit(ch))
	{
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
crope tp,s[100010];
int tot;
int main() 
{
    int n=read();
    for(int i=1;i<=n;++i)
    {
    	char op[2];
    	scanf("%s",op);
	    switch(op[0]) 
	    {
	        case'T': 
	        {
	        	char str[2];
	            scanf("%s",str);
	            tp.push_back(str[0]);
				s[++tot]=tp;
	            break;
	        }
	        case'U': 
	        {
	            tp=s[tot-read()];
				s[++tot]=tp;
	            break;
	        }
	        case'P': 
	        {
	            putchar(tp[read()]);
				puts("");
	            break;
	        }
	    }
	}
}

