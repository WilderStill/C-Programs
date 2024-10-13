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
namespace Talent_Name{const int WoZiBiLe=0,XueRouPiNang=1,XingHeLiLiangTouShe=2,XinShengYuWu=3,ChaoFanRuSheng=4,KeJiZhiShang=5;}
namespace Skill_Name{const int XinTaiBengLe=0,GeLinZhaLie=1,RiShengZhiYu_ZhouJiDaoDan=2,TianLouBaDuanJian=3,YanChuKaiShi=4,TianLangShiZhan=5,DiQiuLanSeShanDian_TaiXuCangLanShan=6,JiGuangZhanFang=7,LiuXing=8,JingLingBiHu=9,QuanLiChaoQuanKai_LunHuiZhiZhongMo=10;}
namespace Buff_Name{const int Use_QuanLiChaoQuanKai_LunHuiZhiZhongMo=-1,Use_Del_atk=-2,Use_Del_def=-3,Use_Del_mp=-4;}
namespace Player_Name{const int Alice=0,Bob=1;}
using namespace Talent_Name;
using namespace Skill_Name;
using namespace Buff_Name;
using namespace Player_Name;
int n,Round;
struct Buff_tp
{
	int Player,Buff_Name,x,y;
}tp_Buff;
struct Buff_node
{
	int Player,Buff_Name,Delta;
};
struct Talent
{
	int id,x,y;
	inline void Input_Talent(){id=read(),x=read(),y=read();}
};
struct Skill
{
	int id,x,y,z;
	inline void Input_Skill(){id=read(),x=read(),y=read(),z=read();}
};
vector<Buff_node>Buffs[333333];
struct Character
{
	int id,HP,MP,hp,mp,Del_mp,atk,Del_atk,def,Del_def,p[20];
	Talent talent;
	Skill skill;
	inline bool isDead(){return hp<=0;}
	inline int A(){return max(atk+Del_atk,1);}
	inline int D(){return max(def+Del_def,0);}
	inline int Get_decrease_HP(int Get_atk,int Real_hurt)
	{
		if(talent.id==XueRouPiNang)return max(Get_atk-D(),0)+Real_hurt-Real_hurt/2;
		return max(Get_atk-D(),0)+Real_hurt;
	}
	inline void Decrease_HP(int Get_atk,int Real_hurt)
	{
		mp=min(mp+1,MP);
		hp-=Get_decrease_HP(Get_atk,Real_hurt);
		return;
	}
	inline int Choose_Object(Character*Enemy)
	{
		for(int i=1;i<=n;++i)
		{
			if(Enemy[p[i]].isDead())continue;
			return p[i];
		}
		return 0;
	}
	inline void Normal_Attack(Character*Enemy)
	{
		Character&syh=Enemy[Choose_Object(Enemy)];
		int Atk=A(),Real_hurt=0;
		if(talent.id==XingHeLiLiangTouShe)Atk=A(),Real_hurt=talent.x;
		if(talent.id==ChaoFanRuSheng)Atk=0,Real_hurt=A();
		syh.Decrease_HP(Atk,Real_hurt),mp=min(mp+1,MP);
		if(talent.id==KeJiZhiShang)
		{
			bool isKill=0;
			for(int i=1;i<=n;++i)
			{
				if(Enemy[i].isDead())continue;
				isKill=1;
				break;
			}
			if(isKill)hp=min(hp+talent.x,HP);
		}
		return;
	}
	inline int Try_Attack(Character*Enemy)
	{
		Character&syh=Enemy[Choose_Object(Enemy)];
		int Atk=A(),Real_hurt=0;
		if(talent.id==XingHeLiLiangTouShe)Atk=A(),Real_hurt=talent.x;
		if(talent.id==ChaoFanRuSheng)Atk=0,Real_hurt=A();
		return syh.Get_decrease_HP(Atk,Real_hurt);
	}
	inline void Use_Skill(Character*Enemy)
	{
		mp=0;
		Character&syh=Enemy[Choose_Object(Enemy)];
		switch(skill.id)
		{
			case XinTaiBengLe:break;
			case GeLinZhaLie:
			{
				for(int i=1;i<=n;++i)
				{
					if(Enemy[i].isDead())continue;
					Enemy[i].Decrease_HP(skill.x,0);
					Enemy[i].mp-=Enemy[i].mp/10;
				}
				break;
			}
			case RiShengZhiYu_ZhouJiDaoDan:
			{
				for(int i=1;i<=n;++i)
				{
					if(Enemy[i].isDead())continue;
					Enemy[i].Decrease_HP(0,A());
				}
				break;
			}
			case TianLouBaDuanJian:
			{
				for(int i=1;i<=n;++i)
				{
					if(Enemy[i].isDead())continue;
					Enemy[i].Decrease_HP(min(skill.x*A(),Enemy[i].HP/10),0);
				}
				break;
			}
			case YanChuKaiShi:
			{
				tp_Buff={0,Use_Del_mp,skill.x,skill.y};
				break;
			}
			case TianLangShiZhan:
			{
				syh.Del_def-=skill.x;
				syh.Decrease_HP(0,A());
				break;
			}
			case DiQiuLanSeShanDian_TaiXuCangLanShan:
			{
				syh.Decrease_HP(0,A());
				tp_Buff={1,Use_Del_atk,skill.x,-skill.y};
				break;
			}
			case JiGuangZhanFang:
			{
				tp_Buff={0,Use_Del_atk,skill.x,skill.y};
				break;
			}
			case LiuXing:
			{
				for(int i=1;i<=n;++i)Enemy[i].Decrease_HP(A(),0);
				tp_Buff={1,Use_Del_def,skill.x,-skill.y};
				break;
			}
			case JingLingBiHu:
			{
				tp_Buff={0,Use_Del_def,skill.x,skill.y};
				break;
			}
			case QuanLiChaoQuanKai_LunHuiZhiZhongMo:
			{
				tp_Buff={0,Use_QuanLiChaoQuanKai_LunHuiZhiZhongMo,skill.x,0};
				return;
			}
			default:break;
		}
		mp=min(mp+1,MP);
		if(talent.id==KeJiZhiShang)mp=min(mp+talent.y,MP);
		return;
	}
	inline void ReStart()
	{
		if(isDead())return;
		mp=min(mp+Del_mp+1,MP);
		if(talent.id==XinShengYuWu)hp=min(hp+talent.x,HP),mp=min(mp+talent.y,MP);
		return;
	}
};
inline bool Any_Alive(Character*Skb)
{
	for(int i=1;i<=n;++i){if(Skb[i].isDead())continue;return 1;}
	return 0;
}
struct Player
{
	Character character[20];
	int n,id;
	inline bool All_Dead()
	{
		for(int i=1;i<=n;++i){if(character[i].isDead())continue;return 0;}
		return 1;
	}
	inline void Get_Characters(int Character_num,int pid)
	{
		n=Character_num,id=pid;
		for(int i=1;i<=n;++i)
		{
			character[i].id=i;
			character[i].hp=character[i].HP=read();
			character[i].mp=0,character[i].MP=read();
			character[i].atk=read(),character[i].def=read();
			character[i].Del_atk=character[i].Del_def=0;
			for(int j=1;j<=n;++j)
				character[i].p[j]=read();
			character[i].talent.Input_Talent();
			character[i].skill.Input_Skill();
		}
	}
	inline void DoTurn(Character*Enemy)
	{
		if(All_Dead())return;
		int Skill_id=-1,Cid=0;
		for(int i=1;i<=n;++i)
		{
			if(character[i].isDead())continue;
			if(character[i].mp==character[i].MP)
				if(Skill_id<=character[i].skill.id)
					Skill_id=character[i].skill.id,Cid=i;
		}
		if(~Skill_id&&Cid)
		{
			tp_Buff={0,0,0,0};
			character[Cid].Use_Skill(Enemy);
			if(Skill_id==JiGuangZhanFang)
			{
				int Least_HP=0x3f3f3f3f,tCid=0;
				for(int i=1;i<=n;++i)
				{
					if(character[i].isDead())continue;
					if(Least_HP>character[i].hp)Least_HP=character[i].hp,tCid=i;
				}
				character[tCid].hp=min(character[tCid].hp+character[Cid].skill.z,character[tCid].HP);
			}
			if(Skill_id==JingLingBiHu)
			{
				for(int i=1;i<=n;++i)
				{
					if(character[i].isDead())continue;
					character[i].hp=min(character[i].hp+character[Cid].skill.z,character[i].HP);
				}
			}
			if(tp_Buff.Buff_Name==Use_QuanLiChaoQuanKai_LunHuiZhiZhongMo)
			{
				for(int i=1;i<=n;++i)
				{
					if(character[i].isDead())continue;
					character[i].atk*=2;
					character[i].hp=max(character[i].hp,character[i].HP/2),
					character[i].def*=2;
					character[i].mp=max(character[i].mp,character[i].MP/2);
				}					
				character[Cid].mp=min(character[Cid].mp+1,character[Cid].MP);
				if(character[Cid].talent.id==KeJiZhiShang)character[Cid].mp=min(character[Cid].mp+character[Cid].talent.y,character[Cid].MP);
				for(int i=1;i<=n;++i)++character[i].Del_mp;
				for(int i=1;i<=n;++i)if(character[i].skill.id==QuanLiChaoQuanKai_LunHuiZhiZhongMo)character[i].skill.id=0;
				for(int i=1;i<=n;++i)if(Enemy[i].skill.id==QuanLiChaoQuanKai_LunHuiZhiZhongMo)Enemy[i].skill.id=0;
				Buffs[Round+tp_Buff.x-1].emplace_back((Buff_node){tp_Buff.Player^id,tp_Buff.Buff_Name,tp_Buff.y});
			}
			else if(tp_Buff.Buff_Name)
			{
				Character*C=(tp_Buff.Player?Enemy:character);
				for(int i=1;i<=n;++i)
				{
					if(C[i].isDead())continue;
					if(tp_Buff.Buff_Name==Use_Del_atk)C[i].Del_atk+=tp_Buff.y;
					if(tp_Buff.Buff_Name==Use_Del_def)C[i].Del_def+=tp_Buff.y;
					if(tp_Buff.Buff_Name==Use_Del_mp)C[i].Del_mp+=tp_Buff.y;
				}	
				Buffs[Round+tp_Buff.x-1].emplace_back((Buff_node){tp_Buff.Player^id,tp_Buff.Buff_Name,tp_Buff.y});
			}
			if(Any_Alive(Enemy))
			{
				for(int i=1;i<=n;++i)
				{
					if(character[i].isDead())continue;
					character[i].ReStart();
				}
			}
			return;
		}
		pair<pair<int,int>,int>tp=make_pair(make_pair(0,0),0);
		for(int i=1;i<=n;++i)
		{
			if(character[i].isDead())continue;
			Character&syh=Enemy[character[i].Choose_Object(Enemy)];
			pair<pair<int,int>,int>res=make_pair(make_pair(syh.hp,character[i].Try_Attack(Enemy)),i);
			if(tp<res)tp=res;
		}
		character[tp.second].Normal_Attack(Enemy);
		if(Any_Alive(Enemy))
		{
			for(int i=1;i<=n;++i)
			{
				if(character[i].isDead())continue;
				character[i].ReStart();
			}
		}	
		return;
	}
}player[2];
inline void TakeTurns()
{
	for(Round=1;;++Round)
	{
		player[Alice].DoTurn(player[Bob].character);
		if(player[Bob].All_Dead())break;
		player[Bob].DoTurn(player[Alice].character);
		if(player[Alice].All_Dead())break;
		for(auto Buff:Buffs[Round])
		{
			if(Buff.Buff_Name==Use_QuanLiChaoQuanKai_LunHuiZhiZhongMo)
			{
				for(int i=1;i<=n;++i)player[Buff.Player].character[i].hp=0;
				break;
			}
			for(int i=1;i<=n;++i)
			{
				if(Buff.Buff_Name==Use_Del_atk)player[Buff.Player].character[i].Del_atk-=Buff.Delta;
				if(Buff.Buff_Name==Use_Del_def)player[Buff.Player].character[i].Del_def-=Buff.Delta;
				if(Buff.Buff_Name==Use_Del_mp)player[Buff.Player].character[i].Del_mp-=Buff.Delta;
			}
		}
		if(player[Alice].All_Dead()||player[Bob].All_Dead())break;
	}
}
int main()
{
	n=read();
	player[Alice].Get_Characters(n,Alice);
	player[Bob].Get_Characters(n,Bob);
	TakeTurns();
	write(Round),puts("");
	int Winner=player[Alice].All_Dead()?Bob:Alice;
	puts(Winner?"Bob":"Alice");
	for(int i=1;i<=n;++i)
	{
		if(player[Winner].character[i].isDead())write(0);
		else write(player[Winner].character[i].hp);
		putchar(' ');
	}
    return 0;
}
