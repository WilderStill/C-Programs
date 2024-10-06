#include<bits/stdc++.h>
using namespace std;
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
inline void write(int x)
{
    if(x<0)
	{
        putchar('-');
        write(-x);
        return;
    }
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
vector<char>v,tp;
int main()
{
	int n=read(),pos=0;
	for(int i=1;i<=n;++i)
    {
        char op[3];
        scanf("%s",op);
        switch(op[0])
        {
	        case'M':{pos=read();break;}
	        case'I':
	        {
	        	tp.clear(),tp.resize(read());
				for(auto&ch:tp)ch=getchar();
				v.insert(v.begin()+pos,tp.begin(),tp.end());
				break;
			}
	        case'D':
	        {
	        	v.erase(v.begin()+pos,v.begin()+pos+read());
				break;
			}
	        case'G':
	        {
	        	putchar(v[pos]);
				if(v[pos]!='\n')putchar('\n');
				break;
			}
	        case'P':{--pos;break;}
	        case'N':{++pos;break;}
	        case'R':{reverse(v.begin()+pos,v.begin()+pos+read());break;}
	        default:break;
        }
    }
    return 0;
}

