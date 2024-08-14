#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
stack<ll>s1;stack<char>s2;
ll qpow(ll x,ll y)
{
	ll dg=1;
	while(y)
	{
		if(y&1)dg=dg*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return dg;
}
ll calc(ll a,ll b,char op)
{
	switch(op)
	{
		case '+':return(a+b)%mod;
		case '-':return(a-b+mod)%mod;
		case '*':return(a*b)%mod;
		case '^':return qpow(a,b)%mod;
	}
}
ll cal(string str)
{
	auto level=[](char c)
	{
		switch(c)
		{
			case '(':{return 0;break;}
			case '+':{return 1;break;}
			case '-':{return 1;break;}
			case '*':{return 2;break;}
			case '^':{return 3;break;}
			default:{return -1;}
		}
	};
    ll len=str.size();
    for(int i=0;i<len;++i)
	{
        if(str[i]==' '||str[i]=='\r')continue;
        if(str[i]=='a')s1.push(10086);
        else if(isdigit(str[i]))
		{
            int optnum=0;
            while(isdigit(str[i])){optnum=optnum*10+str[i]-48;i++;}i--;
            s1.push(optnum);
        }
        else if(str[i]=='(')s2.push(str[i]);
        else if(str[i]!=')')
		{
            while(!s2.empty()&&level(s2.top())>=level(str[i]))
			{
                ll b=s1.top();s1.pop();
                ll a=s1.top();s1.pop();
                ll opt=s2.top();s2.pop();
                s1.push(calc(a,b,opt)%mod);
            }
			s2.push(str[i]);
        }
		else
		{
            while(!s2.empty()&&s2.top()!='(')
			{
                ll b=s1.top();s1.pop();
                ll a=s1.top();s1.pop();
                ll opt=s2.top();s2.pop();
                s1.push(calc(a,b,opt)%mod);
            }
			if(!s2.empty())s2.pop();
        }
    }
    while(!s2.empty())
	{
        if(s2.top()=='(')
		{
            s2.pop();
			continue;
        }
        ll b=s1.top();s1.pop();
        ll a=s1.top();s1.pop();
        ll opt=s2.top();s2.pop();
        s1.push(calc(a,b,opt)%mod);
    }
    return s1.top();
}
int main()
{
    string qs;
    getline(cin,qs);
    ll qsn=cal(qs),n;
	cin>>n;
    string cho;
    getline(cin,cho);
    for(int i=0;i<n;++i)
	{
        getline(cin,cho);
        if(qsn==cal(cho))putchar('A'+i);
    }
    return 0;
}

