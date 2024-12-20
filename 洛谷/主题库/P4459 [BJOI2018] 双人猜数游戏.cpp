#include<bits/stdc++.h>
using namespace std;
using vpr=vector<pair<int,int>>;
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
        x=-x;
    }
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
int limit,times;
char name[127];
inline int TakeTurn_Alice(int,int);
inline int TakeTurn_Bob(int,int);
unordered_map<int,int>CMap_Alice,CMap_Bob,TMap_Alice[127],TMap_Bob[127];
inline int Alice_Count(int mul)
{
	if(CMap_Alice.count(mul))return CMap_Alice[mul];
	int res=0;
	for(int i=limit;i*i<=mul;++i)if(!(mul%i))++res;
	return CMap_Alice[mul]=res;
}
inline int Bob_Count(int sum)
{
	if(CMap_Bob.count(sum))return CMap_Bob[sum];
	int res=0;
	for(int i=limit;i*2<=sum;++i)++res;
	return CMap_Bob[sum]=res;
}
inline vpr Alice_Guess(int mul)
{
	vpr res;
	for(int i=limit;i*i<=mul;++i)
		if(!(mul%i))res.emplace_back(i,mul/i);
	return res;
}
inline vpr Bob_Guess(int sum)
{
	vpr res;
	for(int i=limit;i*2<=sum;++i)res.emplace_back(i,sum-i);
	return res;
}
inline int TakeTurn_Alice(int pos,int mul)
{
	if(!pos)return Alice_Count(mul);
	if(TMap_Alice[pos].count(mul))return TMap_Alice[pos][mul];
	vpr vec=Alice_Guess(mul);
	int res=0;
	for(auto it:vec)res+=(TakeTurn_Bob(pos-1,it.first+it.second)>1);
	return TMap_Alice[pos][mul]=res;
}
inline int TakeTurn_Bob(int pos,int sum)
{
	if(!pos)return Bob_Count(sum);
	if(TMap_Bob[pos].count(sum))return TMap_Bob[pos][sum];
	vpr vec=Bob_Guess(sum);
	int res=0;
	for(auto it:vec)res+=(TakeTurn_Alice(pos-1,it.first*it.second)>1);
	return TMap_Bob[pos][sum]=res;
}
inline vpr dfs_Alice(int pos,vpr maybe_ans)
{
	if(!pos)return maybe_ans;
	vpr res;
	for(auto tp:maybe_ans)
		if(TakeTurn_Bob(pos-1,tp.first+tp.second)>1)
			res.emplace_back(tp);
	return res;
}
inline vpr dfs_Bob(int pos,vpr maybe_ans)
{
	if(!pos)return maybe_ans;
	vpr res;
	for(auto tp:maybe_ans)
		if(TakeTurn_Alice(pos-1,tp.first*tp.second)>1)
			res.emplace_back(tp);
	return res;
}
inline int Calc_No(int n,int m)
{
	vpr Alice_ans=Alice_Guess(n*m),Bob_ans=Bob_Guess(n+m);
	if(name[1]=='A')
	{
		for(int i=1;i<=times;++i)
		{
			if(i&1)
			{
				Alice_ans=dfs_Alice(i-1,Alice_ans);
				if(Alice_ans.size()<=1)return 0;
			}
			else
			{
				Bob_ans=dfs_Bob(i-1,Bob_ans);
				if(Bob_ans.size()<=1)return 0;
			}
		}
		if(times&1)
		{
			Bob_ans=dfs_Bob(times,Bob_ans);
			int ans_cnt=0;
			for(auto tp:Alice_ans)
				if(dfs_Bob(times,Bob_Guess(tp.first+tp.second)).size()==1)
					++ans_cnt;
			if(Bob_ans.size()==1&&ans_cnt==1)return times;
			return 0;
		}
		else
		{
			Alice_ans=dfs_Alice(times,Alice_ans);
			int ans_cnt=0;
			for(auto tp:Bob_ans)
				if(dfs_Alice(times,Alice_Guess(tp.first*tp.second)).size()==1)
					++ans_cnt;
			if(Alice_ans.size()==1&&ans_cnt==1)return times;
			return 0;
		}
	}
	else
	{
		for(int i=1;i<=times;++i)
		{
			if(i&1)
			{
				Bob_ans=dfs_Bob(i-1,Bob_ans);
				if(Bob_ans.size()<=1)return 0;
			}
			else
			{
				Alice_ans=dfs_Alice(i-1,Alice_ans);
				if(Alice_ans.size()<=1)return 0;
			}
		}
		if(times&1)
		{
			Alice_ans=dfs_Alice(times,Alice_ans);
			int ans_cnt=0;
			for(auto tp:Bob_ans)
				if(dfs_Alice(times,Alice_Guess(tp.first*tp.second)).size()==1)
					++ans_cnt;
			if(Alice_ans.size()==1&&ans_cnt==1)return times;
			return 0;
		}
		else
		{
			Bob_ans=dfs_Bob(times,Bob_ans);
			int ans_cnt=0;
			for(auto tp:Alice_ans)
				if(dfs_Bob(times,Bob_Guess(tp.first+tp.second)).size()==1)
					++ans_cnt;
			if(Bob_ans.size()==1&&ans_cnt==1)return times;
			return 0;
		}
	}
	return 0;
}
int main()
{
	limit=read();
	scanf("%s",name+1);
	times=read();
	for(int sum=limit<<1;;++sum)
		for(int i=limit;sum-i>=i;++i)
			if(Calc_No(i,sum-i)==times)
			{
				write(i),putchar(' '),write(sum-i);
				return 0;
			}
	return 0;
}
