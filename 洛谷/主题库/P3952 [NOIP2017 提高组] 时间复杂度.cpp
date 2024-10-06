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
int vis[100010],x[100010],loop[100010];
int main()
{
	//freopen("P3952_10.in","r",stdin);
	//freopen("complexity.out","w",stdout);
	int T=read();
	while(T--)
	{
		memset(loop,0,sizeof loop);
		memset(x,0,sizeof x);
		memset(vis,0,sizeof vis);
		string in,tp;
		do{tp=in;cin>>in;}while(in[0]!='O'); 
		int line=0,plex=0,cl=0,can=1,lplex=0,rplex=0,rcd=0;
		for(int i=0;i<tp.size();++i)line=(line<<1)+(line<<3)+(tp[i]&15);
		for(int i=4;i<in.size()-1;++i)plex=(plex<<1)+(plex<<3)+(in[i]&15);
		while(line--)
		{
			cin>>in;
			if(in[0]=='F')
			{
				++cl;
				cin>>in;
				int ch=in[0]-'a';
				if(vis[ch])cl=-1;
				else vis[ch]=1,x[cl]=ch;
                cin>>in>>tp;
                if(in[0]!='n'&&tp[0]=='n'&&can)++lplex,loop[cl]=1;
                else if((in.size()==tp.size()&&in>tp)||(in.size()>tp.size())||(in[0]=='n'&&tp[0]!='n')&&can)can=0,rcd=cl;
			}
			else
			{
				rplex=max(rplex,lplex);
				vis[x[cl]]=0;
                if(loop[cl]==1)--lplex,loop[cl]=0;
                --cl;
                if(rcd>0&&cl<rcd)can=1,rcd=0;
			}
			if(cl<0)
			{
				puts("ERR");
				goto ending;
			}
		}
		if(cl>0)puts("ERR");
		else puts(rplex==plex?"Yes":"No");
ending: /* Nothing to say.It is not as it was. */;
    }
    return 0;
}
