#include<bits/stdc++.h>
using namespace std;
namespace Bigint_Wilder
{
	struct Bigint
	{
		bool ng;
		int num[100010],len;
		Bigint(){ng=0,len=1;memset(num,0,sizeof num);}
		Bigint(long long x)
		{
			if(x<0)ng=1,x=-x;
			else ng=0;
			len=0;
			while(x)
			{
				num[++len]=x%10;
				x/=10;
			}
		}
		bool operator !()const
		{
			if(len==1&&num[1]==0)return 1;
			return 0;
		}
		Bigint operator -()const
		{
			Bigint res=*this;
			res.ng^=1;
			return res;
		}
		bool operator==(const Bigint b)const
		{
			if(ng&&!b.ng)return 0;
			if(!ng&&b.ng)return 0;
			if(len^b.len)return 0;
			for(int i=len;i;--i)
				if(num[i]^b.num[i])
					return 0;
			return 1;
		}
		bool operator!=(const Bigint b)const
		{
			if(ng&&!b.ng)return 1;
			if(!ng&&b.ng)return 1;
			if(len^b.len)return 1;
			for(int i=len;i;--i)
				if(num[i]^b.num[i])
					return 1;
			return 0;
		}
		bool operator<(const Bigint b)const
		{
			bool syh=0;
			if(ng&&!b.ng)return 1;
			if(!ng&&b.ng)return 0;
			if(ng&&b.ng)syh=1;
			if(len==b.len)
			{
				for(int i=len;i>1;--i)
					if(num[i]^b.num[i])
						return (num[i]<b.num[i])^syh;
				return (num[1]<b.num[1])^syh;
			}
			return (len<b.len)^syh;
		}
		bool operator<=(const Bigint b)const
		{
			bool syh=0;
			if(ng&&!b.ng)return 1;
			if(!ng&&b.ng)return 0;
			if(ng&&b.ng)syh=1;
			if(len==b.len)
			{
				for(int i=len;i>1;--i)
					if(num[i]^b.num[i])
						return (num[i]<b.num[i])^syh;
				return num[1]==b.num[1]?1:(num[1]<b.num[1])^syh;
			}
			return (len<b.len)^syh;
		}
		bool operator>(const Bigint b)const
		{
			bool syh=0;
			if(ng&&!b.ng)return 0;
			if(!ng&&b.ng)return 1;
			if(ng&&b.ng)syh=1;
			if(len==b.len)
			{
				for(int i=len;i>1;--i)
					if(num[i]^b.num[i])
						return (num[i]>b.num[i])^syh;
				return (num[1]>b.num[1])^syh;
			}
			return (len>b.len)^syh;
		}
		bool operator>=(const Bigint b)const
		{
			bool syh=0;
			if(ng&&!b.ng)return 0;
			if(!ng&&b.ng)return 1;
			if(ng&&b.ng)syh=1;
			if(len==b.len)
			{
				for(int i=len;i>1;--i)
					if(num[i]^b.num[i])
						return (num[i]>b.num[i])^syh;
				return num[1]==b.num[1]?1:(num[1]>b.num[1])^syh;
			}
			return (len>b.len)^syh;
		}
		Bigint operator+(const Bigint x)const
		{
			Bigint a=*this,b=x,res;
			res.ng=0;
			if(a.ng&&!b.ng)
			{
				a.ng=0;
				res=b-a;
				return res;
			}
			if(!a.ng&&b.ng)
			{
				b.ng=0;
				res=a-b;
				return res;
			}
			if(a.ng&&b.ng)a.ng=b.ng=0,res.ng=1;
			res.len=max(a.len,b.len);
			for(int i=1;i<=res.len;++i)
			{
				res.num[i]+=a.num[i]+b.num[i];
				res.num[i+1]+=res.num[i]/10;
				res.num[i]=res.num[i]%10;
				if(res.num[i+1]>0&&i==a.len)++res.len;
			}
			while(!res.num[res.len]&&res.len>1)--res.len;
			return res;
		}
		Bigint operator-(const Bigint x)const
		{
			Bigint a=*this,b=x,res;
			if(a.ng&&!b.ng)
			{
				a.ng=0;
				res=a+b;
				res.ng=1;
				return res;
			}
			if(!a.ng&&b.ng)
			{
				b.ng=0;
				res=a+b;
				res.ng=0;
				return res;
			}
			if(a.ng&&b.ng)
			{
				a.ng=b.ng=0;
				swap(a,b);
			}
			res.ng=0;
			if(a<b)swap(a,b),res.ng=1;
			res.len=max(a.len,b.len);
			for(int i=1;i<=res.len;++i)
			{
				res.num[i]+=a.num[i]-b.num[i];
				res.num[i+1]-=(res.num[i]<0);
				res.num[i]=(res.num[i]+10)%10;
				if(res.num[i+1]>0&&i==len)++res.len;
			}
			while(!res.num[res.len]&&res.len>1)--res.len;
			return res;
		}
		Bigint operator*(const Bigint b)const
		{
			Bigint res;
			res.ng=(ng||b.ng)-(ng&&b.ng);
			res.len=len+b.len-1;
			for(int i=1;i<=len;++i)
	            for(int j=1;j<=b.len;++j)
	                res.num[i+j-1]+=num[i]*b.num[j];
			for(int i=1;i<=res.len;++i)
			{
				res.num[i+1]+=res.num[i]/10;
				res.num[i]%=10;
				if(i==res.len&&res.num[i+1])++res.len;
			}
			while(!res.num[res.len]&&res.len>1)--res.len;
			return res;
		}
		Bigint operator/(Bigint b) const
		{
			Bigint a,res;
			res.ng=(ng||b.ng)-(ng&&b.ng),b.ng=0;
			res.len=len;
			for(int i=len;i;--i)
			{
				for(int j=a.len;j;--j)a.num[j+1]=a.num[j];
				a.num[1]=num[i];
				++a.len;
				while(a.len>1&&!a.num[a.len])--a.len;
				while(a>=b)
				{
					++res.num[i];
					a=a-b;
				}
			}
			while(res.len>1&&!res.num[res.len])--res.len;
			return res;
		}
		Bigint operator%(Bigint b) const
		{
			Bigint res;
			for(int i=len;i;--i)
			{
				for(int j=res.len;j;--j)res.num[j+1]=res.num[j];
				res.num[1]=num[i];
				++res.len;
				while(res.len>1&&!res.num[res.len])--res.len;
				while(res>=b)res=res-b;
			}
			while(res.len>1&&!res.num[res.len])--res.len;
			if(ng)
			{
				res=b-res;
				res.ng=ng;
				return res;
			}
			return res;
		}
		void output()
		{
			if(ng)putchar('-');
			for(int i=len;i;--i)putchar(num[i]+'0');
		}
		void input()
		{
			string s;
			cin>>s;
			if(s[0]=='-')ng=1;
			else ng=0,s=' '+s;
			len=s.size()-1;
			for(int i=1;i<=len;++i)num[i]=s[len-i+1]&15;
		}
	};
	void operator+=(Bigint&a,Bigint b)
	{
		Bigint res=a+b;
		a=res;
	}
	void operator-=(Bigint&a,Bigint b)
	{
		Bigint res=a-b;
		a=res;
	}
	void operator*=(Bigint&a,Bigint b)
	{
		Bigint res=a*b;
		a=res;
	}
	void operator/=(Bigint&a,Bigint b)
	{
		Bigint res=a/b;
		a=res;
	}
	void operator%=(Bigint&a,Bigint b)
	{
		Bigint res=a%b;
		a=res;
	}
	void operator++(Bigint&a)
	{
		Bigint res=a+Bigint(1);
		a=res;
	}
	void operator--(Bigint&a)
	{
		Bigint res=a-Bigint(1);
		a=res;
	}
	Bigint abs(Bigint a)
	{
		a.ng=0;
		return a;
	}
	Bigint max(Bigint a,Bigint b)
	{
		return a>b?a:b;
	}
	Bigint min(Bigint a,Bigint b)
	{
		return a<b?a:b;
	}
	Bigint gcd(Bigint a,Bigint b)
	{
		Bigint res,two=Bigint(2ll);
		a=abs(a),b=abs(b);
		res.ng=0;
		res.num[1]=1;
		while(true)
		{
			int cnt=0;
			if((a.num[1]&1)&&(b.num[1]&1))
			{
				if(a<b)swap(a,b);
				a-=b;
				if(a.len==1&&!a.num[1])break;
			}
			if(!(b.num[1]&1))b/=two,++cnt;
			if(!(a.num[1]&1))a/=two,++cnt;
			if(cnt==2)res*=two;
		}
		res*=b;
		return res;
	}
}
using namespace Bigint_Wilder;
Bigint f[50][10];
char a[5010];
int main()
{
	int n,K;
	cin>>n>>K>>(a+1);
	for(int i=1;i<=n;++i)
	{
	    for(int j=1;j<=i;++j)f[i][0].num[j]=a[i-j+1]-'0';
	    f[i][0].len=i;
	}
	for(int j=1;j<=K;++j)
		for(int i=j+1;i<=n;++i)
			for(int k=j;k<i;++k)
			{
				Bigint tp;tp.len=0;
				for(int t=i;t>=k+1;--t)tp.num[++tp.len]=a[t]-'0';
				f[i][j]=max(f[i][j],tp*f[k][j-1]);
			}
	f[n][K].output();
    return 0;
}
