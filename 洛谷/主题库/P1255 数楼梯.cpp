#include<bits/stdc++.h>
using namespace std;
struct Int{
	bool re = 0;
	int num[20100] = {0},len = 1;
	bool operator < (const Int an) const{
		if(len == an.len){
			for(int i = len;i >= 2;--i){
				if(num[i] == an.num[i]) continue;
				return num[i] < an.num[i];
			}
			return num[1] < an.num[1];
		}
		return len < an.len;
	}
	Int operator - (const Int an) const{
		Int a,b,turn;
		if(*this < an){a = an,b = *this,turn.re = 1;}
		else{a = *this,b = an,turn.re = 0;}
		turn.len = max(a.len,b.len);
		for(int i = 1;i <= turn.len;++i){
			turn.num[i] += a.num[i]-b.num[i];
			turn.num[i+1] -= turn.num[i]<0?1:0;
			turn.num[i] = (turn.num[i]+10)%10;
			if(turn.num[i+1]>0&&i == len){++turn.len;}
		}
		while(turn.num[turn.len] == 0&&turn.len>1){turn.len--;}
		return turn;
	}
	Int operator + (const Int an) const{
		Int turn;turn.re = 0;
		turn.len = max(len,an.len);
		for(int i = 1;i <= turn.len;++i){
			turn.num[i] += an.num[i]+num[i];
			turn.num[i+1] += turn.num[i]/10;
			turn.num[i] = turn.num[i]%10;
			if(turn.num[i+1]>0&&i == len){++turn.len;}
		}
		while(turn.num[turn.len] == 0&&turn.len>1){turn.len--;}
		return turn;
	}
	Int operator * (const Int an) const{
		Int turn;turn.re = 0;
		turn.len = len+an.len-1;
		for(int i = 1;i <= len;++i){
            for(int j = 1;j <= an.len;++j){
                turn.num[i+j-1] += num[i]*an.num[j];
            }
		}
		for(int i = 1;i <= turn.len;++i){
			turn.num[i+1]+=turn.num[i] / 10;
			turn.num[i] %= 10;
			if(i == turn.len&&turn.num[i+1] != 0){
				++turn.len;
			}
		}
		while(turn.num[turn.len] == 0&&turn.len>1){turn.len--;}
		return turn;
	}
	Int operator / (const long long an) const{
		Int turn;turn.re = 0;
		long long a = 0;
		turn.len = len;
		for(int i = len;i >= 1;--i){
            a *= 10;
            a += num[i];
            turn.num[i] = a / an;
            a = a%an;
		}
		while(turn.len > 1&&turn.num[turn.len] == 0){--turn.len;}
		return turn;
	}
	Int operator / (Int an) const{
		Int turn;turn.re = 0;
		Int a;
		turn.len = len;
		for(int i = len;i >= 1;--i){
			for(int j = a.len;j >= 1;--j) a.num[j+1] = a.num[j];
			a.num[1] = num[i];a.len++;
			while(a.len > 1&&a.num[a.len] == 0){--a.len;}
			while(!(a < an)){++turn.num[i];a = a-an;}
		}
		while(turn.len > 1&&turn.num[turn.len] == 0){--turn.len;}
		return turn;
	}
	Int operator % (Int an) const{
		Int a;
		for(int i = len;i >= 1;--i){
			for(int j = a.len;j >= 1;--j) a.num[j+1] = a.num[j];
			a.num[1] = num[i];a.len++;
			while(a.len > 1&&a.num[a.len] == 0){--a.len;}
			while(!(a < an)){a = a-an;}
		}
		while(a.len > 1&&a.num[a.len] == 0){--a.len;}
		return a;
	}
	void out(){
		if(re) cout << '-';
		for(int i = len;i >= 1;--i){cout << char(num[i]+'0');}
	}
	void in(){
		re = 0;
		string A;
		cin >> A;
		len = A.size();
		for(int i = 1;i <= len;++i){num[i] = A[len-i] - '0';}
	}
};
struct Matrix
{
    Int a[3][3];
    Matrix(){memset(a,0,sizeof a);}
    Matrix operator*(const Matrix &b) const {
        Matrix res;
        for(int i=1;i<=2;i++)
            for(int j=1;j<=2;j++)
                for(int k=1;k<=2;k++)
                    res.a[i][j]=(res.a[i][j]+a[i][k]*b.a[k][j]);
        return res;
    }
}ans,base;
void init()
{
    base.a[1][1].len=base.a[1][1].num[1]=1;
	base.a[1][2].len=base.a[1][2].num[1]=1;
	base.a[2][1].len=base.a[2][1].num[1]=1;
    ans.a[1][1].len=ans.a[1][1].num[1]=1;
	ans.a[1][2].len=ans.a[1][2].num[1]=1;
}
void qpow(int x)
{
    while(x)
    {
        if(x&1)ans=ans*base;
        base=base*base;
        x>>=1;
    }
}
int main()
{
	int n;
	scanf("%d",&n);
    if(n<3)
    {
    	printf("%d",n);
    	return 0;
	}
    init();
    qpow(n-1);
    ans.a[1][1].out();
}
