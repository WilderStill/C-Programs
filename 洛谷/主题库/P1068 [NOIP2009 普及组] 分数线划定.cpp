#include<bits/stdc++.h>
using namespace std;
struct Genshin
{
	int uid;
	int characters;
}Impact[11451411];
bool cmp_Genshin(Genshin player1,Genshin player2)
{
	if(player1.characters<player2.characters) return 0;
	else if(player1.characters==player2.characters)
	{
		return player1.uid<player2.uid;
	}
	else return 1;
}
int main()
{
	int mihoyo,prizer;
	scanf("%d %d",&mihoyo,&prizer);
	prizer=prizer*3/2;
	for(int player=1;player<=mihoyo;player++)
	{
		scanf("%d %d",&Impact[player].uid,&Impact[player].characters);
	}
	sort(Impact+1,Impact+mihoyo+1,cmp_Genshin);
	while(Impact[prizer+1].characters==Impact[prizer].characters&&prizer+1<=mihoyo)
	{
		prizer++;
	}
	printf("%d %d\n",Impact[prizer].characters,prizer);
	for(int player=1;player<=prizer;player++)
	{
		printf("%d %d\n",Impact[player].uid,Impact[player].characters);
	}
	return 0;
}
