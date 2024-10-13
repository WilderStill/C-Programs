#include<bits/stdc++.h>
using namespace std;
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
        write(-x);
        return;
    }
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
const bool ZhenYing[3][3]={{0,0,1},{0,0,1},{1,1,0}};
struct Pig_Player
{
	int Identity,Blood,Turn,Next,Cardcnt;
	bool isDead,Armed;
	char Cards[2010];
}pig[20];
deque<int>CardP;
int n,m,Round,NumFan,DeadFan,vis[2010];
char tp[2010];
inline void GetCard(int pos)
{
    pig[pos].Cards[++pig[pos].Cardcnt]=CardP.front();
    if(CardP.size()>1)CardP.pop_front();
    return;
}
inline int Find_Card(int pos,char name)
{
	for(int i=1;i<=pig[pos].Cardcnt;++i)if(pig[pos].Cards[i]==name)return i;
    return 0;
}
inline void To_Link(int pos)
{
    for(int i=1;i<=n;++i)
        if(!pig[i].isDead&&pig[i].Next==pos)
		{
			pig[i].Next=pig[pos].Next;
			return;
		}
}
inline void Neaten_Cards(int pos,int st,int ed)
{
	for(int i=st;i<ed;++i)pig[pos].Cards[i]=pig[pos].Cards[i+1];
	return;
}
inline bool Respond_Sha(int pos)
{
	int UseC=Find_Card(pos,'D');
    if(UseC)Neaten_Cards(pos,UseC,pig[pos].Cardcnt),--pig[pos].Cardcnt;
    return UseC;
}
inline bool Respond_Use_Kill(int pos,int source)
{
    int UseC=Find_Card(pos,'K');
    if(pos==source)
	{
		UseC=0;
        for(int i=1;i<=pig[pos].Cardcnt;++i)if(vis[i]^Round&&pig[pos].Cards[i]=='K'){UseC=i;break;}
        if(UseC)vis[UseC]=Round;
        return UseC;
    }
    if(UseC)Neaten_Cards(pos,UseC,pig[pos].Cardcnt),--pig[pos].Cardcnt;
    return UseC;
}
inline bool Respond_WuXieKeJi(int pos,int source)
{
    int UseC=Find_Card(pos,'J');
    if(pos==source)
	{
		UseC=0;
        for(int i=1;i<=pig[pos].Cardcnt;++i)if(vis[i]^Round&&pig[pos].Cards[i]=='J'){UseC=i;break;}
        if(UseC)vis[UseC]=Round;
        return UseC;
    }
    if(UseC)Neaten_Cards(pos,UseC,pig[pos].Cardcnt),--pig[pos].Cardcnt;
    return UseC;
}
inline void Respond_Tao(int pos,int source)
{
	int UseC=Find_Card(pos,'P');
	if(pos==source)
	{
        UseC=0;
        for(int i=1;i<=pig[pos].Cardcnt;++i)if(vis[i]^Round&&pig[pos].Cards[i]=='P'){UseC=i;break;}
        if(UseC)vis[UseC]=Round,++pig[pos].Blood;
        return;
    }
	if(UseC)++pig[pos].Blood,Neaten_Cards(pos,UseC,pig[pos].Cardcnt),--pig[pos].Cardcnt;
	return;
}
inline void Decrease_Blood(int aim,int source)
{
	--pig[aim].Blood;
	if(pig[aim].Blood<1)Respond_Tao(aim,source);
	return;
}
inline void After_Killing(int aim,int source)
{
	if(pig[source].Identity==0&&pig[aim].Identity==1)
	{
        for(int i=1;i<=pig[source].Cardcnt;++i)vis[i]=Round;
		pig[source].Armed=0;
		return;
    }
    if(pig[aim].Identity==2)GetCard(source),GetCard(source),GetCard(source);
    return;
}
inline void Use_ZhuGeLianNu(int pos)
{
	pig[pos].Armed=1;
	return;
}
inline void Use_Sha(int pos)
{
	int Next_Pig=pig[pos].Next;
    pig[pos].Turn=1;
    if(!Respond_Sha(Next_Pig))
	{
        Decrease_Blood(Next_Pig,pos);
        if(pig[Next_Pig].Blood<1)DeadFan+=(pig[Next_Pig].Identity==2),pig[Next_Pig].isDead=1,pig[pos].Next=pig[Next_Pig].Next;
		if(NumFan==DeadFan||pig[1].isDead)return;
		if(pig[Next_Pig].Blood<1)After_Killing(Next_Pig,pos); 
    }
	return;
}
inline void Use_Tao(int pos)
{
	++pig[pos].Blood;
	return;
}
inline bool Use_WuXieKeJi(int pos,int aim,int source,bool isUse)
{
	bool fg=isUse;
    for(int Next=pos;;)
		if(!pig[Next].isDead)
		{
	        if(!isUse)
	        {
	        	if(!ZhenYing[pig[Next].Identity][pig[aim].Identity])
	                if(Respond_WuXieKeJi(Next,source)){pig[Next].Turn=1;return Use_WuXieKeJi(Next,aim,source,isUse^1);}
			}
			else
			{
				if(ZhenYing[pig[Next].Identity][pig[aim].Identity])
	            	if(Respond_WuXieKeJi(Next,source)){pig[Next].Turn=1;return Use_WuXieKeJi(Next,aim,source,isUse^1);}
			}
			Next=pig[Next].Next;
			if(Next==pos)break;
	    }
	return fg;
}
inline void Use_JueDou(int pos,int aim,int source)
{
    pig[pos].Turn=1;
    if(pig[aim].Turn==1)if(Use_WuXieKeJi(pos,aim,pos,0))return;
    while(true)
	{
        if(pig[pos].Identity==0&&pig[aim].Identity==1)
		{
            Decrease_Blood(aim,source);
            if(pig[aim].Blood<1)DeadFan+=(pig[aim].Identity==2),pig[aim].isDead=1,To_Link(aim);
            if(NumFan==DeadFan||pig[1].isDead)return;
            if(pig[aim].Blood<1)After_Killing(aim,pos);
            return;
        }
		else if(!Respond_Use_Kill(aim,source))
		{
            Decrease_Blood(aim,source);
            if(pig[aim].Blood<1)DeadFan+=(pig[aim].Identity==2),pig[aim].isDead=1,To_Link(aim);
            if(NumFan==DeadFan||pig[1].isDead)return;
            if(pig[aim].Blood<1)After_Killing(aim,pos);
            return;
        }
        if(!Respond_Use_Kill(pos,source))
		{
            Decrease_Blood(pos,source);
            if(pig[pos].Blood<1)DeadFan+=(pig[pos].Identity==2),pig[pos].isDead=1,To_Link(pos);
            if(NumFan==DeadFan||pig[1].isDead)return;
            if(pig[pos].Blood<1)After_Killing(pos,aim);
            return;
        }
    }
}
inline void Use_NanZhuRuQin(int pos)
{
	for(int Next=pig[pos].Next;Next^pos;Next=pig[Next].Next)
		if(!pig[Next].isDead)
		{
	        if(pig[Next].Turn==1)if(Use_WuXieKeJi(pos,Next,pos,0))continue;
	        if(!Respond_Use_Kill(Next,pos))
			{
				Decrease_Blood(Next,pos);
				if(Next==1&&!pig[pos].Turn)pig[pos].Turn=-1;
	            if(pig[Next].Blood<1)DeadFan+=(pig[Next].Identity==2),pig[Next].isDead=1,To_Link(Next);
				if(NumFan==DeadFan||pig[1].isDead)return;
				if(pig[Next].Blood<1)After_Killing(Next,pos);
	        }
	    }
	return;
}
inline void Use_WanJianQiFa(int pos)
{
	for(int Next=pig[pos].Next;Next^pos;Next=pig[Next].Next)
		if(!pig[Next].isDead)
		{
	        if(pig[Next].Turn==1)if(Use_WuXieKeJi(pos,Next,pos,0))continue;
	        if(!Respond_Sha(Next))
			{
				Decrease_Blood(Next,pos);
				if(Next==1&&!pig[pos].Turn)pig[pos].Turn=-1;
	            if(pig[Next].Blood<1)DeadFan+=(pig[Next].Identity==2),pig[Next].isDead=1,To_Link(Next);
				if(NumFan==DeadFan||pig[1].isDead)return;
				if(pig[Next].Blood<1)After_Killing(Next,pos);
	        }
	    }
	return;
}
inline bool canAttack(int pos)
{
	int Next=pig[pos].Next;
    if(pig[Next].Turn==0)return 0;
	if(pig[Next].Turn==1)return ZhenYing[pig[pos].Identity][pig[Next].Identity];
    return pig[pos].Identity==0;
}
inline int Object(int pos)
{
    if(pig[pos].Identity==2)return 1;
    for(int Next=pig[pos].Next;Next^pos;Next=pig[Next].Next)
		if(!pig[Next].isDead)
        	if((pig[Next].Identity==2&&pig[Next].Turn==1)||(pig[pos].Identity==0&&pig[Next].Turn==-1))return Next;
    return -1;
}
inline bool PlayCards(int pos)
{
	memset(vis,0,sizeof vis);
    int Usecnt,cnt,res=-1;
    bool isUseSha=0;
    for(Round=1;;++Round)
	{
        Usecnt=cnt=0;
        for(int i=1;i<=pig[pos].Cardcnt;++i)
			if(vis[i]^Round)
			{
	            switch(pig[pos].Cards[i])
				{
	                case'P':
	                {
	                	if(pig[pos].Blood<4)
						{
							Use_Tao(pos);
							vis[i]=Round;
							++Usecnt;
							i=pig[pos].Cardcnt;
						}
	                    break;
					}
					case'K':
	                {
	                	if((!isUseSha||pig[pos].Armed)&&canAttack(pos))
	                	{
	                		Use_Sha(pos);
	                		vis[i]=Round;
							++Usecnt;
							isUseSha=1;
							i=pig[pos].Cardcnt;
						}
	                    break;
					}
	                case'F':
	                {
	                	int aim=Object(pos);
						if(~aim)
						{
							Use_JueDou(pos,aim,pos);
							vis[i]=Round;
							++Usecnt;
							i=pig[pos].Cardcnt;
						}
	                    break;
					}
	                case'N':
	            	{
	                	Use_NanZhuRuQin(pos);
						vis[i]=Round;
						++Usecnt;
						i=pig[pos].Cardcnt;
	                    break;
					}   
	                case'W':
	                {
	                	Use_WanJianQiFa(pos);
						vis[i]=Round;
						++Usecnt;
						i=pig[pos].Cardcnt;
	                    break;
					}
	                case'Z':
	                {
	                	Use_ZhuGeLianNu(pos);
	                	vis[i]=Round;
						++Usecnt;
						i=pig[pos].Cardcnt;
	                    break;
					}
	                default:break;
	            }
	            if(NumFan==DeadFan||pig[1].isDead){res=1;break;}
	            if(pig[pos].isDead){res=0;break;}
        	}
        for(int i=1;i<=pig[pos].Cardcnt;++i)if(vis[i]^Round)tp[++cnt]=pig[pos].Cards[i];
        for(int i=1;i<=cnt;++i)pig[pos].Cards[i]=tp[i];
		pig[pos].Cardcnt=cnt;
        if(!Usecnt&&res^1)res=0;
        if(~res)return res;
    }
}
inline bool DoTurns(int pos)
{
	GetCard(pos),GetCard(pos);
    return PlayCards(pos);
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;++i)
	{
		pig[i].Blood=4;
		pig[i].Cardcnt=4;
		pig[i].isDead=0;
		pig[i].Turn=0;
		pig[i].Armed=0;
		pig[i].Next=i%n+1;
		char syh[3];
		scanf("%s",syh);
		NumFan+=(syh[0]=='F');
		pig[i].Identity=(syh[0]=='F'?2:(syh[0]=='Z'?1:0));
        for(int j=1;j<=4;++j)
		{
			scanf("%s",syh);
			pig[i].Cards[j]=syh[0];
		}
    }
	for(int i=1;i<=m;++i)
	{
		char syh[3];
		scanf("%s",syh);
		CardP.push_back(syh[0]);
	}
	pig[1].Turn=1;
	for(int i=1,fg=0;!fg&&NumFan;i=pig[i].Next)if(!pig[i].isDead)fg=DoTurns(i);
	puts(pig[1].isDead?"FP":"MP");
    for(int i=1;i<=n;++i)
	{
        if(pig[i].isDead)puts("DEAD");
		else
		{
            if(pig[i].Cardcnt)putchar(pig[i].Cards[1]);
            for(int j=2;j<=pig[i].Cardcnt;++j)putchar(' '),putchar(pig[i].Cards[j]);
			puts("");
        }
    }
    return 0;
}
