#include<bits/stdc++.h>
using namespace std;
struct BigInt
{
	bool fg=0;
	int num[10010]={0},len=1;
	bool operator < (const BigInt an) const
	{
		if(len == an.len)
		{
			for(int i = len;i >= 2;--i)
			{
				if(num[i] == an.num[i])continue;
				return num[i] < an.num[i];
			}
			return num[1] < an.num[1];
		}
		return len < an.len;
	}
	BigInt operator - (const BigInt an) const
	{
		BigInt a,b,turn;
		if(*this < an){a = an,b = *this,turn.fg = 1;}
		else{a = *this,b = an,turn.fg = 0;}
		turn.len = max(a.len,b.len);
		for(int i = 1;i <= turn.len;++i)
		{
			turn.num[i] += a.num[i]-b.num[i];
			turn.num[i+1] -= turn.num[i]<0?1:0;
			turn.num[i] = (turn.num[i]+10)%10;
			if(turn.num[i+1]>0&&i == len){++turn.len;}
		}
		while(turn.num[turn.len] == 0&&turn.len>1){turn.len--;}
		return turn;
	}
	BigInt operator + (const BigInt an) const
	{
		BigInt turn;turn.fg = 0;
		turn.len = max(len,an.len);
		for(int i = 1;i <= turn.len;++i)
		{
			turn.num[i] += an.num[i]+num[i];
			turn.num[i+1] += turn.num[i]/10;
			turn.num[i] = turn.num[i]%10;
			if(turn.num[i+1]>0&&i == len){++turn.len;}
		}
		while(turn.num[turn.len] == 0&&turn.len>1){turn.len--;}
		return turn;
	}
	BigInt operator * (const BigInt an) const
	{
		BigInt turn;turn.fg = 0;
		turn.len = len+an.len-1;
		for(int i = 1;i <= len;++i){
            for(int j = 1;j <= an.len;++j){
                turn.num[i+j-1] += num[i]*an.num[j];
            }
		}
		for(int i = 1;i <= turn.len;++i)
		{
			turn.num[i+1]+=turn.num[i] / 10;
			turn.num[i] %= 10;
			if(i == turn.len&&turn.num[i+1])
			{
				++turn.len;
			}
		}
		while(turn.num[turn.len] == 0&&turn.len>1){turn.len--;}
		return turn;
	}
	BigInt operator / (const long long an) const{
		BigInt turn;turn.fg = 0;
		long long a = 0;
		turn.len = len;
		for(int i = len;i >= 1;--i){
            a *= 10;
            a += num[i];
            turn.num[i] = a / an;
            a = a%an;
		}
		while(turn.len > 1&&!turn.num[turn.len]){--turn.len;}
		return turn;
	}
	BigInt operator/(BigInt an)const
	{
		BigInt turn;turn.fg=0;
		BigInt a;
		turn.len=len;
		for(int i = len;i>=1;--i)
		{
			for(int j=a.len;j >= 1;--j)a.num[j+1] = a.num[j];
			a.num[1]=num[i];a.len++;
			while(a.len>1&&!a.num[a.len]){--a.len;}
			while(!(a<an)){++turn.num[i];a = a-an;}
		}
		while(turn.len > 1&&!turn.num[turn.len]){--turn.len;}
		return turn;
	}
	void out()
	{
		if(fg)cout<<'-';
		for(int i=len;i>=1;--i){cout<<char(num[i]+'0');}
	}
	void in()
	{
		fg=0;
		string A;
		cin>>A;
		len=A.size();
		for(int i=1;i<=len;++i){num[i]=A[len-i]-'0';}
	}
}a,b,ans,t2;
int main()
{
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(0);
	a.in(),b.in();
	t2.num[1]=2;
	ans.num[1]=1;
	while(1)
	{
		bool cnt=0;
		if((a.num[1]&1)&&(b.num[1]&1))
		{
			if(a<b)swap(a,b);
			a=a-b;
			if(a.len==1&&!a.num[1])break;
		}
		if(!(a.num[1]&1)){a=a/2;cnt=1;}
		if(!(b.num[1]&1)){b=b/2;if(cnt)ans=ans*t2;}
		
	}
	ans=ans*b;
	ans.out();
	return 0;
}
