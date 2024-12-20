#include<bits/stdc++.h>
using namespace std;
int m,n,size,tk[1000010],pos[1000010],st[25][1000010];
int dict[127];
char s[1000010],tp[1000010];
string mp[1000010],tmp[1000010];
inline void Move(char op)
{
	switch(op)
	{
		case'G':
		{
			for(int j=0;j<n;++j)
			{
				int ln=0;
				for(int i=0;i<m;++i)
					if(mp[i][j]!='.')
					{
						mp[ln][j]=mp[i][j];
						if(ln!=i)mp[i][j]='.';
						++ln;
					}
			}
			break;
		}
		case'L':
		{
			for(int i=0;i<m;++i)
			{
				int rw=0;
				for(int j=0;j<n;++j)
					if(mp[i][j]!='.')
					{
						mp[i][rw]=mp[i][j];
						if(rw!=j)mp[i][j]='.';
						++rw;
					}
			}
			break;
		}
		case'D':
		{
			for(int j=0;j<n;++j)
			{
				int ln=m-1;
				for(int i=m-1;~i;--i)
					if(mp[i][j]!='.')
					{
						mp[ln][j]=mp[i][j];
						if(ln!=i)mp[i][j]='.';
						--ln;
					}
			}
			break;
		}
		case'P':
		{
			for(int i=0;i<m;++i)
			{
				int rw=n-1;
				for(int j=n-1;~j;--j)
					if(mp[i][j]!='.')
					{
						mp[i][rw]=mp[i][j];
						if(rw!=j)mp[i][j]='.';
						--rw;
					}
			}
			break;
		}
		default:break;
	}
}
inline void reMove(char op)
{
	switch(op)
	{
		case'G':
		{
			for(int j=0;j<n;++j)
			{
				int ln=0;
				for(int i=0;i<m;++i)
					if(tk[i*n+j])
					{
						tk[ln*n+j]=tk[i*n+j];
						if(ln!=i)tk[i*n+j]=0;
						++ln;
					}
			}
			break;
		}
		case'L':
		{
			for(int i=0;i<m;++i)
			{
				int rw=0;
				for(int j=0;j<n;++j)
					if(tk[i*n+j])
					{
						tk[i*n+rw]=tk[i*n+j];
						if(rw!=j)tk[i*n+j]=0;
						++rw;
					}
			}
			break;
		}
		case'D':
		{
			for(int j=0;j<n;++j)
			{
				int ln=m-1;
				for(int i=m-1;~i;--i)
					if(tk[i*n+j])
					{
						tk[ln*n+j]=tk[i*n+j];
						if(ln!=i)tk[i*n+j]=0;
						--ln;
					}
			}
			break;
		}
		case'P':
		{
			for(int i=0;i<m;++i)
			{
				int rw=n-1;
				for(int j=n-1;~j;--j)
					if(tk[i*n+j])
					{
						tk[i*n+rw]=tk[i*n+j];
						if(rw!=j)tk[i*n+j]=0;
						--rw;
					}
			}
			break;
		}
		default:break;
	}
}
inline void SuperMario()
{
	for(int i=1;i<=3;++i)Move(s[i]);
	int cnt=0;
	for(int i=0;i<m;++i)
	{
		tmp[i]=mp[i];
		for(int j=0;j<n;++j)
			if(mp[i][j]=='.')tk[i*n+j]=0;
			else
			{
				tk[i*n+j]=++cnt;
				pos[cnt]=i*n+j;
			}
	}
	for(int i=4;i<=7;++i)reMove(s[i]);
	for(int i=0;i<m;++i)
		for(int j=0;j<n;++j)
			if(tk[i*n+j])
				st[0][pos[tk[i*n+j]]]=i*n+j;
	int rd=(size-3)/4;
	for(int k=1;(1<<k)<=rd;++k)
		for(int i=0;i<m;++i)
			for(int j=0;j<n;++j)
				if(tk[i*n+j])
					st[k][i*n+j]=st[k-1][st[k-1][i*n+j]];
	for(int k=0;(1<<k)<=rd;++k)
	{
		int bit=(1<<k);
		if(!(rd&bit))continue;
		for(int i=0;i<m;++i)
			for(int j=0;j<n;++j)
				if(mp[i][j]=='.')tmp[i][j]='.';
				else tmp[st[k][i*n+j]/n][st[k][i*n+j]%n]=mp[i][j];
		for(int i=0;i<m;++i)for(int j=0;j<n;++j)swap(mp[i][j],tmp[i][j]);
	}
	for(int i=rd*4+3;i<=size;++i)Move(s[i]);
}
inline void ClearUseless()
{
	if(size<=2)return;
	for(int i=0;i<=size+1;++i)tp[i]=0;
	tp[1]=s[1],tp[2]=s[2];
	for(int i=2,j=1;;)
	{
		if((dict[tp[j]]&1)==(dict[tp[j+1]]&1))
		{
			tp[j]=tp[j+1];
			tp[j+1]=0;
			if(j^1)--j;
			else
			{
				if(i==size)break;
				tp[j+1]=s[++i];
			}
		}
		else if(tp[j-1]==tp[j+1])
		{
			tp[j+1]=0;
			if(j^1)--j;
			else
			{
				if(i==size)break;
				tp[j+1]=s[++i];
			}
		}
		else
		{
			if(i==size)break;
			++j,++i;
			tp[j+1]=s[i];
		}
	}
	int len=strlen(tp+1);
	if(tp[len]==tp[len-1])--len;
	for(int i=1;i<=len;++i)s[i]=tp[i];
	if(size==len)return;
	size=len;
}
inline void solve()
{
	scanf("%d%d",&m,&n);
	for(int i=0;i<m;++i)
	{
		mp[i].resize(n);
		scanf("%s",s);
		for(int j=0;j<n;++j)mp[i][j]=s[j];
	}
	scanf("%d%s",&size,s+1);
	ClearUseless();
	if(size>5)SuperMario();
	else for(int i=1;i<=size;++i)Move(s[i]);
	for(int i=0;i<m;++i)puts(mp[i].c_str());
}
int main()
{
	dict['G']=1,dict['L']=2;
	dict['D']=3,dict['P']=4;
	solve();
	return 0;
}
