#include<bits/stdc++.h>
#define MambaOut 248248
#define KobeBryant 824
#define INF 998244353
#define eps 1e-24
#define db double
#define feq(x,y) (fabs(x-y)<=eps)
#define fcmp(x,y) (feq(x,y)?INF:(x>y))
using namespace std;
char Kobe_Bryant[KobeBryant][KobeBryant]=
{"",
"__      __      __|                                      ___     _                                      _",
" \\      /\\      / | _    _   __|__      _    _     _      |     / \\   _   _  _        _  _    _     _  / \\",
"  \\    /  \\    /  |/ \\  / \\    |       / \\  / \\  |/ \\     |     \\_   / \\  |  |      |/ \\/ \\  / \\  |/ \\  _/",
"   \\  /    \\  /   |  |  | |    |       |    | |  |  |     |       \\  | |  |  |      |  |  |  | |  |  |  |",
"    \\/      \\/    |  |  \\_/\\   \\_/     \\_/  \\_/\\ |  |    _|_    \\_/  \\_/\\ \\__/  _/  |  |  |  \\_/\\ |  |  O",
"                                                                             |",
"                                                                             |",
"                                                                          \\__/",
"",
"",
"    /\\        /\\                  |                 __                /\\",
"   /  \\      /  \\      _      _   |       _        /  \\  _  _  __|__  ||",
"  /    \\    /    \\    / \\   |/ \\  |___   / \\       |  |  |  |    |    ||",
" /      \\  /      \\   | |   |  |  |   \\  | |       |  |  |  |    |    \\/",
"/        \\/        \\  \\_/\\  |  |  |___/  \\_/\\      \\__/  \\__/\\   \\_/  O",
"",
"",
"              __ __  ___   __    _____        __    _____  __    __      _          _      _  ________",
"              |  /  /   \\ |  \\   |           |  \\   |    \\  \\    /      / \\         |\\     |  |   |   |",
"              | /   |   | |  |   |           |  |   |    |   \\  /      /   \\        | \\    |      |",
"____________  |/    |   | |__/_  |____  /\\   |__/_  |____/    \\/      /     \\       |  \\   |      |",
"              |\\    |   | |    \\ |      \\/   |    \\ |  \\       |     /_______\\      |   \\  |      |",
"              | \\   |   | |    | |           |    | |   \\      |    /         \\     |    \\ |      |",
"             _|__\\_ \\___/ |____/ |____       |____/_|_  _\\_   _|_ _/_         _\\_  _|_    \\|    __|__"
};
int n,m,max_s,max_si[MambaOut],s[MambaOut],sum[MambaOut];
db Pro[MambaOut];
bool vis[MambaOut];
db max_pro;
struct player
{
	int num;
	db pro;
}players[KobeBryant][KobeBryant];
bool cmp(player Kobe,player Bryant){return feq(Kobe.pro,Bryant.pro)?(s[Kobe.num]>s[Bryant.num]):(Kobe.pro>Bryant.pro);}
void dfs(int pos,db pos_pro,int pos_s)
{
	if(pos>n)
	{
		if(fcmp(pos_pro,max_pro))
		{
			max_s=max(max_s,pos_s);
			max_pro=pos_pro;
		}
		return;
	}
	if((!fcmp(pos_pro*Pro[pos],max_pro))||(feq(pos_pro*Pro[pos],max_pro)&&pos_s+sum[pos]<=max_s))return;
	for(int i=1;i<=n;++i)
		if(!vis[players[pos][i].num])
		{
			vis[players[pos][i].num]=1;
			dfs(pos+1,pos_pro*players[pos][i].pro,pos_s+s[players[pos][i].num]);
			vis[players[pos][i].num]=0;
		}
	return;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)scanf("%d",&s[i]);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			scanf("%lf",&players[i][j].pro);
			players[i][j].num=j;
		}
		sort(players[i]+1,players[i]+m+1,cmp);
		for(int j=1;j<=n;++j)max_si[i]=max(s[players[i][j].num],max_si[i]);
	}
	Pro[n]=players[n][1].pro;
	for(int i=n-1;i;--i)
	{
		Pro[i]=Pro[i+1]*players[i][1].pro;
		sum[i]=sum[i+1]+max_si[i];
	}
	dfs(1,1,0);
	printf("%.12lf\n%d\n",max_pro,max_s);
//	for(int i=1;i<=24;++i)puts(Kobe_Bryant[i]);
//  ÖÂ¾´ÀÎ´ó£¡£¡£¡Kobe¡¤Bryant Forever!!! 
	return 0;
}
