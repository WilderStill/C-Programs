#include<bits/stdc++.h>
using namespace std;
const int M=256;
int n,m,tg;
bool icy[M];
char mp[M][M],lkl[M],lkr[M],cll[M],clr[M];
map<string,string>sol;
queue<string>q;  
inline void init()
{
    memset(icy,0,sizeof icy);
    icy['O']=icy['[']=icy[']']=icy['=']=1;
    memset(lkl,' ',sizeof lkl);
    lkl['O']=']',lkl['[']='=';
    memset(lkr,' ',sizeof lkr);
    lkr['O']='[',lkr[']']='=';
    memset(cll,' ',sizeof cll);
    cll[']']='O',cll['=']='[',cll['[']='[',cll['O']='O';
    memset(clr,' ',sizeof clr);
    clr['[']='O',clr['=']=']',clr[']']=']',clr['O']='O';
}
inline string Falling(string stmt)
{
    int k,r;
    for(int i=n-1;~i;--i)
        for(int j=0;j<m;++j)
		{
            char st=stmt[i*m+j];
            if(st=='O'||st=='@')
			{
                for(k=i+1;k<n;++k)if(stmt[k*m+j]!='.')break;
                stmt[i*m+j]='.';
                stmt[(k-1)*m+j]=st;
            }
            if(st=='[')
			{
                for(r=j+1;r<m;++r)
					if(stmt[i*m+r]=='X'||stmt[i*m+r]==']')
						break;
                if(stmt[i*m+r]==']')
				{
                    for(k=i+1;k<n;++k)
					{
                        bool fg=0;
	                    for(int p=j;p<=r;++p)
							if(stmt[k*m+p]!='.')
							{
	                            fg=1;
	                            break;
	                        }
                        if(fg)break;
                    }
                    for(int p=j;p<=r;++p)stmt[i*m+p]='.';
                    for(int p=j+1;p<r;++p)stmt[(k-1)*m+p]='=';
                    stmt[(k-1)*m+j]='[',stmt[(k-1)*m+r]=']';
                }
                j=r;
            }
        }
    return stmt;
}
inline int calc(string stmt)
{
    int pos=stmt.find('@');
    return max(abs(pos%m-tg%m),pos/m>tg/m?pos/m-tg/m:pos/m<tg/m);
}
inline bool Expand(string stmt,char new_cmd)
{
    string syh=sol[stmt]+new_cmd;
    int tp=stmt.find('@');
    stmt[tp]='.';
    if(new_cmd=='<'||new_cmd=='>')
	{
        stmt[tp]='@';
        int pos=tp+m+(new_cmd=='<'?-1:1);
        if(stmt[pos]=='X')return 0;
        if(stmt[pos]=='.')
		{
            stmt[pos]='O';
            if(icy[stmt[pos-1]])stmt[pos-1]=lkr[stmt[pos-1]];
            if(stmt[pos-1]!='.')stmt[pos]=lkl[stmt[pos]];
            if(icy[stmt[pos+1]])stmt[pos+1]=lkl[stmt[pos+1]];
            if(stmt[pos+1]!='.')stmt[pos]=lkr[stmt[pos]];
        }
        else
		{
            stmt[pos]='.';
            if(icy[stmt[pos-1]])stmt[pos-1]=clr[stmt[pos-1]];
            if(icy[stmt[pos+1]])stmt[pos+1]=cll[stmt[pos+1]];
        }
    }
    else
	{
        int pos=tp+(new_cmd=='L'?-1:1),k;
        if(stmt[pos]=='.')stmt[pos]='@';
        else
		{
            if(stmt[pos]=='O')
			{
                if(new_cmd=='L'&&stmt[pos-1]=='.')
				{
                    for(k=pos-1;k;--k)
						if(stmt[k-1]!='.'||stmt[k+m]=='.')
							break;
                    stmt[pos]='.',stmt[tp]='@',stmt[k]='O';
                }
                if(new_cmd=='R'&&stmt[pos+1]=='.')
				{
                    for(k=pos+1;k<n*m;++k)
						if(stmt[k+1]!='.'||stmt[k+m]=='.')
							break;
                    stmt[pos]='.',stmt[tp]='@',stmt[k]='O';
                }
            }
            if(stmt[pos]!='.')
			{
                if(stmt[pos-m]=='.'&&stmt[tp-m]=='.')stmt[pos-m]='@';
                else stmt[tp]='@';
            }
        }
    }
    stmt=Falling(stmt);
    if(calc(stmt)+syh.size()>15)return 0;
    if(stmt.find('@')==tg)
	{
        puts(syh.c_str());
        return true;
    }
    if(!sol.count(stmt))
	{
        sol[stmt]=syh;
        q.push(stmt);
    }
    return 0;
}
int main()
{
    int cases=0;
    init();
    while(scanf("%d%d",&n,&m)==2&&n)
	{
        for(int i=0;i<n;++i)scanf("%s",mp[i]);
        string s="";
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)
			{
                if(mp[i][j]=='#')tg=i*m+j,mp[i][j]='.';
                s+=mp[i][j];
            }
        q.push(s);
        sol.clear();
        sol[s]="";
        printf("Case %d: ",++cases);
        while(!q.empty())
		{
            string s=q.front();
            q.pop();
            if(Expand(s,'<'))break;
            if(Expand(s,'>'))break;
            if(Expand(s,'L'))break;
            if(Expand(s,'R'))break;
        }
        while(!q.empty())q.pop();
    }
    return 0;
}
/*
5 5
XXXXX
X@.#X
XX.XX
X...X
XXXXX
7 7
XXXXXXX
X.....X
X@[=].X
XXX.XXX
XXX.XXX
XXX#XXX
XXXXXXX
6 6
XXXXXX
X@...X
XXXX=X
X..O.X
X.#O.X
XXXXXX
0
*/
