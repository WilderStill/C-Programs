#include<bits/stdc++.h>
using namespace std;
void Solve(int N,int M);
int Query(const vector<int> &x);
void Answer(const vector<int> &a);
mt19937 dg(time(0));
void Solve(int N,int M)
{
	vector<int>all;
	for(int i=1;i<=N*M;++i)all.push_back(i);
	for(int i=1;i<M;++i)
	{
		shuffle(all.begin(),all.end(),dg);
		vector<int>res;
		res.push_back(all.front());
		all.erase(all.begin());
		while(res.size()<N)
		{
			int v=all.front();
			all.erase(all.begin());
			if(Query(all)==M-i)res.push_back(v);
			else all.push_back(v);
		}
		Answer(res);
	}
	Answer(all);  
}
