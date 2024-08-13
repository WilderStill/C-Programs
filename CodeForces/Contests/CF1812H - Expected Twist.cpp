#define private public
#include<iostream>
#include<algorithm>
#include<random>
#define mod 1000000007
using namespace std;
vector<int> bases;
int n;
const unsigned U=11,D=0xffffffffUL,S=7,B=0x9d2c5680UL,T=15,C=0xefc60000UL,L=18;
unsigned untemper(unsigned z)
{
	unsigned y1=z^(z>>L);
	unsigned y2=y1^((y1<<T)&C);
	unsigned SM=(1<<S)-1;
	unsigned y3=y2^((y2<<S)&B&(SM<<S));
	unsigned y4=y3^((y3<<S)&B&(SM<<(S*2)));
	unsigned y5=y4^((y4<<S)&B&(SM<<(S*3)));
	unsigned y6=y5^((y5<<S)&B&(SM<<(S*4)));
	unsigned UM=(1<<U)-1;
	unsigned y7=y6^((y6>>U)&(UM<<(U*2)));
	unsigned y8=y7^((y7>>U)&(UM<<U));
	unsigned x=y8^((y8>>U)&UM);
	return x;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0); 
	for(int i=0;i<10;++i)bases.emplace_back(rand()%(mod-13893829*2)+13893829);
	cin>>n;
	vector<unsigned>v;
	for(int i=1;i<=min(624,n);++i)
	{
		cout<<"? "<<i<<' '<<i<<endl;
		unsigned x;
		cin>>x;
		v.emplace_back(x);
	}
	mt19937 syh(428);
	syh._M_p=624;
	for(int i=0;i<624;++i)syh._M_x[i]=untemper(v[i]);
	for(int i=624;i<n;++i)v.emplace_back(syh());
	unsigned minn=v[0];
	for(int i=1;i<n;++i)minn=min(minn,v[i]);
	cout<<"! "<<minn<<endl;
	return 0;
}
