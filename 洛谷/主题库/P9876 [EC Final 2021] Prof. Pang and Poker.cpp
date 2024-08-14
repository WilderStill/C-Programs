#include<bits/stdc++.h>
#define M 114514
using namespace std;
int T,n,m,Shook[M],Beta[M],LBW;
string Pokers;
int Poker_to_Number(char ch)
{
	switch(ch)
	{
		case 'T':return 10;
		case 'J':return 11;
		case 'Q':return 12;
		case 'K':return 13;
		case 'A':return 14;
		default:return ch-'0';
	}
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)cin>>Pokers,Shook[i]=Poker_to_Number(Pokers[0]);
		sort(Shook+1,Shook+n+1); 
		for(int i=1;i<=m;i++)cin>>Pokers,Beta[i]=Poker_to_Number(Pokers[0]);
		sort(Beta+1,Beta+m+1);
		cin>>Pokers,LBW=Poker_to_Number(Pokers[0]);
		int Beta_Smaller=0,Shook_Max=0,Shook_No_Use=0;
		for(int i=1;i<=m;i++)Beta_Smaller+=(Beta[i]<LBW?1:0);
		for(int i=1;i<=n;i++)
		{
			if(Shook[i]>=LBW)Shook_No_Use++;
			else Shook_Max=max(Shook_Max,Shook[i]);
		}
		if(n==1){printf("Shou\n");continue;}
		if(Shook_No_Use==n){printf("Shou\n");continue;}
		if(Beta_Smaller>=2){printf("Pang\n");continue;}
		if(Beta_Smaller==0){printf("Shou\n");continue;}
		if(m==1)
		{
			if(Shook_Max>=Beta[1]){printf("Pang\n");continue;}
			else{printf("Shou\n");continue;}
		}
		if(n-Shook_No_Use==1){printf("Shou\n");continue;}
		if(Beta[m]>=Shook[n]){printf("Shou\n");continue;}
		if(Shook_Max>=Beta[1]&&n>3){printf("Pang\n");continue;}
		else{printf("Shou\n");continue;}
	}
}
