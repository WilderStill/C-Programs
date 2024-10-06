#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0,f=1;
    /*
		sssyhsfdsfgsdi
		sdfd_______ddf
		fnj/sdofdsf\dd
		sh/dosadhasd\d
		s|dskfposafisa
		af\sfpodsfjdsp
		skf\dsfdsofdsi
		pafh\______sji
		kkkkkkkkkkk\kk
		kkkkkkkkkkkk\k
		kkkkkkkkkkkk|k
		k\kkkkkkkkk/kk
		kk\_______/aoh
		ajyhoshooajczr
		a\syhoahdbjo/n
		lk\jihzollz/lj
		lzk\sojojk/klz
		lkzk\dkhi/jjhb
		czrys\bo/kbhsj
		fzjjjj\/zhgfzj
		fzjhji|s[fjxjj
		wuyhyu|wyyykjh
		shrjkh|khkdjkb
		zjhhjh|ihzhhhz
		zzhjks|shkdjjk
		shdfasfohisifh
		jioshfphkjihff
		s|suihhsiuuh|a
		s|ejkfhdsifh|a
		f|dhguasfihg|a
		s|sasfuuyias|a
		s|__________|h
		u|vhdasdggiu|a
		j|asdgasdsyd|u
		g|idashdassd|y
		f|egdsadtasd|g
		u|rdfhiashsh|d
		f|zdfhdgfdgf|d
		shdysgdsgigdfy
	*/
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
int w,h,n,f[1010][1010],l[1010],p[1010];
inline int dfs(int x,int y)
{
    if(~f[x][y])return f[x][y];
    int res=x*y;
    for(int i=1;i<=n;++i)
		if(l[i]<=x&&p[i]<=y)
        	res=min({res,dfs(x-l[i],p[i])+dfs(x,y-p[i]),dfs(l[i],y-p[i])+dfs(x-l[i],y)});
    return f[x][y]=res;
}
int main()
{
    w=read(),h=read(),n=read();
    for(int i=1;i<=n;++i)l[i]=read(),p[i]=read();
    memset(f,-1,sizeof f);
    write(dfs(w,h));
    return 0;
}
