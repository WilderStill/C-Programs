#include<bits/stdc++.h>
#define p 101
using namespace std;
struct HashTable
{
	vector<string>Table;
	set<string>flag;
	void init()
	{
		Table.resize(p);
	} 
	int hash(string s)
	{
		int len=s.length(),sum=0;
		for(int i=0;i<len;i++)sum+=s[i]*(i+1); 
		return 19*sum%p;
	}
	void insert(string s)
	{ 
	    if(flag.count(s)) return; 
	    int address=0;
	    for(int j=0;j<=19;j++)
		{
	    	address=(hash(s)+j*j+23*j)%p; 
	    	if(Table[address].empty())break; 
	    }
	    if(!Table[address].empty())return;
	    Table[address]=s; 
	    flag.insert(s);
	}
	void remove(string s)
	{
		if(!flag.count(s))return;
		int address=0;
		for(int j=0;j<=19;j++)
		{
			address=(hash(s)+j*j+23*j)%p;
			if(Table[address]==s)break;
		}
		if(Table[address]!=s)return;
		Table[address]="";
		flag.erase(s);
	}
	int size()
	{
		return flag.size();
	}
	void print()
	{
		cout<<size()<<'\n';
		for(int i=0;i<Table.size();i++)
			if(Table[i]!="" &&flag.count(Table[i])) 
				cout<<i<<":"<<Table[i]<<'\n';
	}
	HashTable()
	{
		init();
	}
};
int main()
{
	ios::sync_with_stdio(false),cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int q;
		HashTable ht;
		cin>>q;
		while(q--)
		{
			string s;
			cin>>s;
			string op=s.substr(0,4),str=s.substr(4,s.length()-4);
			if(op=="ADD:")ht.insert(str);
			if(op=="DEL:")ht.remove(str);
		}
		ht.print();
	}
	return 0;
}
