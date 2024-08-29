#include<bits/stdc++.h>
using namespace std;
namespace Bigint_Wilder
{
	#define Max_Length 100010
	struct Bigint
	{
		bool ng;
		int num[Max_Length],len;
		inline Bigint(){ng=0,len=1;memset(num,0,sizeof num);}
		inline Bigint(long long x)
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
		inline bool operator !()const
		{
			if(len==1&&num[1]==0)return 1;
			return 0;
		}
		inline Bigint operator -()const
		{
			Bigint res=*this;
			res.ng^=1;
			return res;
		}
		inline bool operator==(const Bigint b)const
		{
			if(ng&&!b.ng)return 0;
			if(!ng&&b.ng)return 0;
			if(len^b.len)return 0;
			for(int i=len;i;--i)
				if(num[i]^b.num[i])
					return 0;
			return 1;
		}
		inline bool operator!=(const Bigint b)const
		{
			if(ng&&!b.ng)return 1;
			if(!ng&&b.ng)return 1;
			if(len^b.len)return 1;
			for(int i=len;i;--i)
				if(num[i]^b.num[i])
					return 1;
			return 0;
		}
		inline bool operator<(const Bigint b)const
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
		inline bool operator<=(const Bigint b)const
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
		inline bool operator>(const Bigint b)const
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
		inline bool operator>=(const Bigint b)const
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
		inline Bigint operator+(const Bigint x)const
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
		inline Bigint operator-(const Bigint x)const
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
		inline Bigint operator*(const Bigint b)const
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
		inline Bigint operator*(long long b)const
		{
			Bigint res;
			res.ng=(ng||b<0)-(ng&&b<0);
			if(b<0)b=-b;
			res.len=len;
			for(int i=1;i<=len;++i)
	            res.num[i]+=num[i]*b;
			for(int i=1;i<=res.len;++i)
			{
				res.num[i+1]+=res.num[i]/10;
				res.num[i]%=10;
				if(i==res.len&&res.num[i+1])++res.len;
			}
			while(!res.num[res.len]&&res.len>1)--res.len;
			return res;
		}
		inline Bigint operator/(Bigint b) const
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
		inline Bigint operator/(long long b) const
		{
			Bigint res;
			res.ng=(ng||b<0)-(ng&&b<0);
			if(b<0)b=-b;
			long long a=0;
			res.len=len;
			for(int i=len;i;--i)
			{
	            a=a*10+num[i];
	            res.num[i]=a/b;
	            a%=b;
			}
			while(!res.num[res.len]&&res.len>1)--res.len;
			return res;
		}
		inline Bigint operator%(Bigint b) const
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
		inline void output()
		{
			if(ng)putchar('-');
			for(int i=len;i;--i)putchar(num[i]+'0');
		}
		inline void input()
		{
			string s;
			cin.tie(0);
			cin>>s;
			if(s[0]=='-')ng=1;
			else ng=0,s=' '+s;
			len=s.size()-1;
			for(int i=1;i<=len;++i)num[i]=s[len-i+1]&15;
		}
	};
	inline void operator+=(Bigint&a,Bigint b)
	{
		Bigint res=a+b;
		a=res;
	}
	inline void operator-=(Bigint&a,Bigint b)
	{
		Bigint res=a-b;
		a=res;
	}
	template<typename T>
	inline void operator*=(Bigint&a,T b)
	{
		Bigint res=a*b;
		a=res;
	}
	template<typename T>
	inline void operator/=(Bigint&a,T b)
	{
		Bigint res=a/b;
		a=res;
	}
	inline void operator%=(Bigint&a,Bigint b)
	{
		Bigint res=a%b;
		a=res;
	}
	inline void operator++(Bigint&a)
	{
		Bigint res=a+Bigint(1);
		a=res;
	}
	inline void operator--(Bigint&a)
	{
		Bigint res=a-Bigint(1);
		a=res;
	}
	inline Bigint abs(Bigint a)
	{
		a.ng=0;
		return a;
	}
	inline Bigint max(Bigint a,Bigint b)
	{
		return a>b?a:b;
	}
	inline Bigint min(Bigint a,Bigint b)
	{
		return a<b?a:b;
	}
	inline Bigint gcd(Bigint a,Bigint b)
	{
		Bigint res;
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
			if(!(b.num[1]&1))b/=2,++cnt;
			if(!(a.num[1]&1))a/=2,++cnt;
			if(cnt==2)res*=2;
		}
		res*=b;
		return res;
	}
	inline Bigint lcm(Bigint a,Bigint b)
	{
		Bigint res;
		a=abs(a),b=abs(b);
		res.ng=0;
		res.num[1]=1;
		res=a*b/gcd(a,b);
		return res;
	}
	inline Bigint qpow(Bigint x,int y)
	{
		Bigint res;
		res.len=res.num[1]=1;
		while(y)
		{
			if(y&1)res*=x;
			x*=x;
			y>>=1;
		}
		return res;
	}
	inline Bigint qroot(Bigint n,int k)
	{
		Bigint l=1,r=n,res;
		while(l<=r) 
		{
			Bigint mid=(l+r)/2;
			if(qpow(mid,k)<=n)l=mid+1,res=mid;
			else r=mid-1;
		}
		return res;
	}
}
using namespace Bigint_Wilder;
int main()
{
	Bigint a,b;
	a.input(),b.input();
	(a+b).output();puts("");
	(a-b).output();puts("");
	(a*b).output();puts("");
	(a/b).output();puts("");
	(a%b).output();puts("");
	return 0;
} 
