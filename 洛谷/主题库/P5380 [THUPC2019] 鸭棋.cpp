#include<bits/stdc++.h>										
using namespace std;
int ChessBoard[114][514],DieChess,RedChess=16,BlueChess=16;
bool Turn=0,isOver,isOut,WhichUse,General;
const int RedCaptain=1,RedGuard=2,RedElephant=3,RedHorse=4,RedCar=5,RedDuck=6,RedSoldier=7,BlueCaptain=8,BlueGuard=9,BlueElephant=10,BlueHorse=11,BlueCar=12,BlueDuck=13,BlueSoldier=14;
void ChessInit()
{
	ChessBoard[0][4]=RedCaptain;
	ChessBoard[9][4]=BlueCaptain;
	ChessBoard[0][3]=ChessBoard[0][5]=RedGuard;
	ChessBoard[9][3]=ChessBoard[9][5]=BlueGuard;
	ChessBoard[0][2]=ChessBoard[0][6]=RedElephant;
	ChessBoard[9][2]=ChessBoard[9][6]=BlueElephant;
	ChessBoard[0][1]=ChessBoard[0][7]=RedHorse;
	ChessBoard[9][1]=ChessBoard[9][7]=BlueHorse;
	ChessBoard[0][0]=ChessBoard[0][8]=RedCar;
	ChessBoard[9][0]=ChessBoard[9][8]=BlueCar;
	ChessBoard[2][0]=ChessBoard[2][8]=RedDuck;
	ChessBoard[7][0]=ChessBoard[7][8]=BlueDuck;
	ChessBoard[3][0]=ChessBoard[3][2]=ChessBoard[3][4]=ChessBoard[3][6]=ChessBoard[3][8]=RedSoldier;
	ChessBoard[6][0]=ChessBoard[6][2]=ChessBoard[6][4]=ChessBoard[6][6]=ChessBoard[6][8]=BlueSoldier;
}
void Moveinit(){DieChess=0,isOver=0,isOut=0,General=0;}
void EatChess(int Ex,int Ey)
{
	if(ChessBoard[Ex][Ey]==RedCaptain)isOver=true,DieChess=RedCaptain;
	else if(ChessBoard[Ex][Ey]==BlueCaptain)isOver=true,DieChess=BlueCaptain;
	else if(ChessBoard[Ex][Ey]>=8)DieChess=ChessBoard[Ex][Ey],BlueChess--;
	else if(ChessBoard[Ex][Ey]<8&&ChessBoard[Ex][Ey]>0)DieChess=ChessBoard[Ex][Ey],RedChess--;
}
void TakePlace(int Chess,int Sx,int Sy,int Ex,int Ey)
{
	ChessBoard[Sx][Sy]=0,ChessBoard[Ex][Ey]=Chess;
}
void Move(int Sx,int Sy,int Ex,int Ey)
{
	if(ChessBoard[Sx][Sy]==(Turn?BlueCaptain:RedCaptain))
	{
		if(Sx<0||Sx>9||Sy<0||Sy>8||Ex<0||Ex>9||Ey<0||Ey>8){isOut=1;printf("Invalid command\n");return;}
		if(Ex-Sx==1&&Sy==Ey&&(!Turn?(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]>=8):(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]<8))){EatChess(Ex,Ey);TakePlace(Turn?BlueCaptain:RedCaptain,Sx,Sy,Ex,Ey);return;}
		if(Sx-Ex==1&&Sy==Ey&&(!Turn?(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]>=8):(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]<8))){EatChess(Ex,Ey);TakePlace(Turn?BlueCaptain:RedCaptain,Sx,Sy,Ex,Ey);return;}
		if(Sx==Ex&&Sy-Ey==1&&(!Turn?(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]>=8):(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]<8))){EatChess(Ex,Ey);TakePlace(Turn?BlueCaptain:RedCaptain,Sx,Sy,Ex,Ey);return;}
		if(Sx==Ex&&Ey-Sy==1&&(!Turn?(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]>=8):(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]<8))){EatChess(Ex,Ey);TakePlace(Turn?BlueCaptain:RedCaptain,Sx,Sy,Ex,Ey);return;}
		{isOut=1;printf("Invalid command\n");return;}
	}
	if(ChessBoard[Sx][Sy]==(Turn?BlueGuard:RedGuard))
	{
		if(Sx<0||Sx>9||Sy<0||Sy>8||Ex<0||Ex>9||Ey<0||Ey>8){isOut=1;printf("Invalid command\n");return;}
		if(Ex-Sx==1&&Sy-Ey==1&&(!Turn?(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]>=8):(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]<8))){EatChess(Ex,Ey);TakePlace(Turn?BlueGuard:RedGuard,Sx,Sy,Ex,Ey);return;}
		if(Sx-Ex==1&&Sy-Ey==1&&(!Turn?(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]>=8):(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]<8))){EatChess(Ex,Ey);TakePlace(Turn?BlueGuard:RedGuard,Sx,Sy,Ex,Ey);return;}
		if(Ex-Sx==1&&Ey-Sy==1&&(!Turn?(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]>=8):(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]<8))){EatChess(Ex,Ey);TakePlace(Turn?BlueGuard:RedGuard,Sx,Sy,Ex,Ey);return;}
		if(Sx-Ex==1&&Ey-Sy==1&&(!Turn?(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]>=8):(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]<8))){EatChess(Ex,Ey);TakePlace(Turn?BlueGuard:RedGuard,Sx,Sy,Ex,Ey);return;}
		{isOut=1;printf("Invalid command\n");return;}
	}
	if(ChessBoard[Sx][Sy]==(Turn?BlueElephant:RedElephant))
	{
		if(Sx<0||Sx>9||Sy<0||Sy>8||Ex<0||Ex>9||Ey<0||Ey>8){isOut=1;printf("Invalid command\n");return;}
		if(Sx-Ex==2&&Sy-Ey==2&&!ChessBoard[Sx-1][Sy-1]&&(!Turn?(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]>=8):(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]<8))){EatChess(Ex,Ey);TakePlace(Turn?BlueElephant:RedElephant,Sx,Sy,Ex,Ey);return;}
		if(Sx-Ex==2&&Ey-Sy==2&&!ChessBoard[Sx-1][Sy+1]&&(!Turn?(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]>=8):(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]<8))){EatChess(Ex,Ey);TakePlace(Turn?BlueElephant:RedElephant,Sx,Sy,Ex,Ey);return;}
		if(Ex-Sx==2&&Sy-Ey==2&&!ChessBoard[Sx+1][Sy-1]&&(!Turn?(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]>=8):(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]<8))){EatChess(Ex,Ey);TakePlace(Turn?BlueElephant:RedElephant,Sx,Sy,Ex,Ey);return;}
		if(Ex-Sx==2&&Ey-Sy==2&&!ChessBoard[Sx+1][Sy+1]&&(!Turn?(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]>=8):(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]<8))){EatChess(Ex,Ey);TakePlace(Turn?BlueElephant:RedElephant,Sx,Sy,Ex,Ey);return;}
		{isOut=1;printf("Invalid command\n");return;}
	}
	if(ChessBoard[Sx][Sy]==(Turn?BlueHorse:RedHorse))
	{
		if(Sx<0||Sx>9||Sy<0||Sy>8||Ex<0||Ex>9||Ey<0||Ey>8){isOut=1;printf("Invalid command\n");return;}
		if(Ex-Sx==2&&Ey-Sy==1&&!ChessBoard[Sx+1][Sy]&&(!Turn?(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]>=8):(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]<8))){EatChess(Ex,Ey);TakePlace(Turn?BlueHorse:RedHorse,Sx,Sy,Ex,Ey);return;}
		if(Ex-Sx==1&&Ey-Sy==2&&!ChessBoard[Sx][Sy+1]&&(!Turn?(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]>=8):(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]<8))){EatChess(Ex,Ey);TakePlace(Turn?BlueHorse:RedHorse,Sx,Sy,Ex,Ey);return;}
		if(Ex-Sx==-1&&Ey-Sy==2&&!ChessBoard[Sx][Sy+1]&&(!Turn?(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]>=8):(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]<8))){EatChess(Ex,Ey);TakePlace(Turn?BlueHorse:RedHorse,Sx,Sy,Ex,Ey);return;}
		if(Ex-Sx==-2&&Ey-Sy==1&&!ChessBoard[Sx-1][Sy]&&(!Turn?(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]>=8):(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]<8))){EatChess(Ex,Ey);TakePlace(Turn?BlueHorse:RedHorse,Sx,Sy,Ex,Ey);return;}
		if(Ex-Sx==-2&&Ey-Sy==-1&&!ChessBoard[Sx-1][Sy]&&(!Turn?(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]>=8):(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]<8))){EatChess(Ex,Ey);TakePlace(Turn?BlueHorse:RedHorse,Sx,Sy,Ex,Ey);return;}
		if(Ex-Sx==-1&&Ey-Sy==-2&&!ChessBoard[Sx][Sy-1]&&(!Turn?(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]>=8):(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]<8))){EatChess(Ex,Ey);TakePlace(Turn?BlueHorse:RedHorse,Sx,Sy,Ex,Ey);return;}
		if(Ex-Sx==1&&Ey-Sy==-2&&!ChessBoard[Sx][Sy-1]&&(!Turn?(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]>=8):(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]<8))){EatChess(Ex,Ey);TakePlace(Turn?BlueHorse:RedHorse,Sx,Sy,Ex,Ey);return;}
		if(Ex-Sx==2&&Ey-Sy==-1&&!ChessBoard[Sx+1][Sy]&&(!Turn?(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]>=8):(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]<8))){EatChess(Ex,Ey);TakePlace(Turn?BlueHorse:RedHorse,Sx,Sy,Ex,Ey);return;}
	}
	if(ChessBoard[Sx][Sy]==(Turn?BlueCar:RedCar))
	{
		if(Sx<0||Sx>9||Sy<0||Sy>8||Ex<0||Ex>9||Ey<0||Ey>8){isOut=1;printf("Invalid command\n");return;}
		if(Sx==Ex)
		{	
			if(Ey>Sy)
			{
				for(int i=Sy+1;i<Ey;i++)if(ChessBoard[Sx][i]){isOut=1;printf("Invalid command\n");return;} 
				if(!Turn?(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]>=8):(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]<8)){EatChess(Ex,Ey);TakePlace(Turn?BlueCar:RedCar,Sx,Sy,Ex,Ey);return;}
			}	
			else if(Ey<Sy)
			{
				for(int i=Sy-1;i>Ey;i--)if(ChessBoard[Sx][i]){isOut=1;printf("Invalid command\n");return;} 
				if(!Turn?(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]>=8):(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]<8)){EatChess(Ex,Ey);TakePlace(Turn?BlueCar:RedCar,Sx,Sy,Ex,Ey);return;}
			}
			else{isOut=1;printf("Invalid command\n");return;}
		}
		else if(Ey==Sy)
		{
			if(Ex>Sx)
			{
				for(int i=Sx+1;i<Ex;i++)if(ChessBoard[i][Sy]){isOut=1;printf("Invalid command\n");return;} 
				if(!Turn?(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]>=8):(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]<8)){EatChess(Ex,Ey);TakePlace(Turn?BlueCar:RedCar,Sx,Sy,Ex,Ey);return;}
			}	
			else if(Ex<Sx)
			{
				for(int i=Sx-1;i>Ex;i--)if(ChessBoard[i][Sy]){isOut=1;printf("Invalid command\n");return;}
				if(!Turn?(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]>=8):(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]<8)){EatChess(Ex,Ey);TakePlace(Turn?BlueCar:RedCar,Sx,Sy,Ex,Ey);return;}
			}
			else{isOut=1;printf("Invalid command\n");return;}
		}
		else{isOut=1;printf("Invalid command\n");return;}
	}
	if(ChessBoard[Sx][Sy]==(Turn?BlueDuck:RedDuck))
	{
		if(Sx<0||Sx>9||Sy<0||Sy>8||Ex<0||Ex>9||Ey<0||Ey>8){isOut=1;printf("Invalid command\n");return;}
		if(Ex-Sx==2&&Ey-Sy==3&&!ChessBoard[Sx][Sy+1]&&!ChessBoard[Sx+1][Sy+2]&&(!Turn?(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]>=8):(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]<8))){EatChess(Ex,Ey);TakePlace(Turn?BlueDuck:RedDuck,Sx,Sy,Ex,Ey);return;}
		if(Ex-Sx==3&&Ey-Sy==2&&!ChessBoard[Sx+1][Sy]&&!ChessBoard[Sx+2][Sy+1]&&(!Turn?(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]>=8):(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]<8))){EatChess(Ex,Ey);TakePlace(Turn?BlueDuck:RedDuck,Sx,Sy,Ex,Ey);return;}
		if(Ex-Sx==-2&&Ey-Sy==3&&!ChessBoard[Sx][Sy+1]&&!ChessBoard[Sx-1][Sy+2]&&(!Turn?(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]>=8):(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]<8))){EatChess(Ex,Ey);TakePlace(Turn?BlueDuck:RedDuck,Sx,Sy,Ex,Ey);return;}
		if(Ex-Sx==-3&&Ey-Sy==2&&!ChessBoard[Sx-1][Sy]&&!ChessBoard[Sx-2][Sy+1]&&(!Turn?(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]>=8):(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]<8))){EatChess(Ex,Ey);TakePlace(Turn?BlueDuck:RedDuck,Sx,Sy,Ex,Ey);return;}
		if(Ex-Sx==2&&Ey-Sy==-3&&!ChessBoard[Sx][Sy-1]&&!ChessBoard[Sx+1][Sy-2]&&(!Turn?(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]>=8):(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]<8))){EatChess(Ex,Ey);TakePlace(Turn?BlueDuck:RedDuck,Sx,Sy,Ex,Ey);return;}
		if(Ex-Sx==3&&Ey-Sy==-2&&!ChessBoard[Sx+1][Sy]&&!ChessBoard[Sx+2][Sy-1]&&(!Turn?(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]>=8):(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]<8))){EatChess(Ex,Ey);TakePlace(Turn?BlueDuck:RedDuck,Sx,Sy,Ex,Ey);return;}
		if(Ex-Sx==-2&&Ey-Sy==-3&&!ChessBoard[Sx][Sy-1]&&!ChessBoard[Sx-1][Sy-2]&&(!Turn?(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]>=8):(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]<8))){EatChess(Ex,Ey);TakePlace(Turn?BlueDuck:RedDuck,Sx,Sy,Ex,Ey);return;}
		if(Ex-Sx==-3&&Ey-Sy==-2&&!ChessBoard[Sx-1][Sy]&&!ChessBoard[Sx-2][Sy-1]&&(!Turn?(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]>=8):(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]<8))){EatChess(Ex,Ey);TakePlace(Turn?BlueDuck:RedDuck,Sx,Sy,Ex,Ey);return;}
		{isOut=1;printf("Invalid command\n");return;}
	}
	if(ChessBoard[Sx][Sy]==(Turn?BlueSoldier:RedSoldier))
	{
		if(Sx<0||Sx>9||Sy<0||Sy>8||Ex<0||Ex>9||Ey<0||Ey>8){isOut=1;printf("Invalid command\n");return;}
		if(Ex-Sx==1&&Sy==Ey&&(!Turn?(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]>=8):(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]<8))){EatChess(Ex,Ey);TakePlace(Turn?BlueSoldier:RedSoldier,Sx,Sy,Ex,Ey);return;}
		if(Sx-Ex==1&&Sy==Ey&&(!Turn?(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]>=8):(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]<8))){EatChess(Ex,Ey);TakePlace(Turn?BlueSoldier:RedSoldier,Sx,Sy,Ex,Ey);return;}
		if(Sx==Ex&&Sy-Ey==1&&(!Turn?(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]>=8):(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]<8))){EatChess(Ex,Ey);TakePlace(Turn?BlueSoldier:RedSoldier,Sx,Sy,Ex,Ey);return;}
		if(Sx==Ex&&Ey-Sy==1&&(!Turn?(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]>=8):(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]<8))){EatChess(Ex,Ey);TakePlace(Turn?BlueSoldier:RedSoldier,Sx,Sy,Ex,Ey);return;}
		if(Ex-Sx==1&&Sy-Ey==1&&(!Turn?(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]>=8):(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]<8))){EatChess(Ex,Ey);TakePlace(Turn?BlueSoldier:RedSoldier,Sx,Sy,Ex,Ey);return;}
		if(Sx-Ex==1&&Sy-Ey==1&&(!Turn?(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]>=8):(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]<8))){EatChess(Ex,Ey);TakePlace(Turn?BlueSoldier:RedSoldier,Sx,Sy,Ex,Ey);return;}
		if(Ex-Sx==1&&Ey-Sy==1&&(!Turn?(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]>=8):(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]<8))){EatChess(Ex,Ey);TakePlace(Turn?BlueSoldier:RedSoldier,Sx,Sy,Ex,Ey);return;}
		if(Sx-Ex==1&&Ey-Sy==1&&(!Turn?(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]>=8):(!ChessBoard[Ex][Ey]||ChessBoard[Ex][Ey]<8))){EatChess(Ex,Ey);TakePlace(Turn?BlueSoldier:RedSoldier,Sx,Sy,Ex,Ey);return;}
		{isOut=1;printf("Invalid command\n");return;}
	}
	{isOut=1;printf("Invalid command\n");return;}
}
void CheckGeneral(int x,int y)
{
	bool CheckTurn=(ChessBoard[x][y]>=8);
	if(ChessBoard[x][y]==(CheckTurn?BlueCaptain:RedCaptain))
	{
		if(ChessBoard[x+1][y]==(!CheckTurn?BlueCaptain:RedCaptain)&&0<=x+1&&x+1<=9&&0<=y&&y<=8){General=1;return;}
		if(ChessBoard[x-1][y]==(!CheckTurn?BlueCaptain:RedCaptain)&&0<=x-1&&x-1<=9&&0<=y&&y<=8){General=1;return;}
		if(ChessBoard[x][y+1]==(!CheckTurn?BlueCaptain:RedCaptain)&&0<=x&&x<=9&&0<=y+1&&y+1<=8){General=1;return;}
		if(ChessBoard[x][y-1]==(!CheckTurn?BlueCaptain:RedCaptain)&&0<=x&&x<=9&&0<=y-1&&y-1<=8){General=1;return;}
	}
	if(ChessBoard[x][y]==(CheckTurn?BlueGuard:RedGuard))
	{
		if(ChessBoard[x+1][y+1]==(!CheckTurn?BlueCaptain:RedCaptain)&&0<=x+1&&x+1<=9&&0<=y+1&&y+1<=8){General=1;return;}
		if(ChessBoard[x-1][y+1]==(!CheckTurn?BlueCaptain:RedCaptain)&&0<=x-1&&x-1<=9&&0<=y+1&&y+1<=8){General=1;return;}
		if(ChessBoard[x+1][y-1]==(!CheckTurn?BlueCaptain:RedCaptain)&&0<=x+1&&x+1<=9&&0<=y-1&&y-1<=8){General=1;return;}
		if(ChessBoard[x-1][y-1]==(!CheckTurn?BlueCaptain:RedCaptain)&&0<=x-1&&x-1<=9&&0<=y-1&&y-1<=8){General=1;return;}
	}
	if(ChessBoard[x][y]==(CheckTurn?BlueElephant:RedElephant))
	{
		if(ChessBoard[x+2][y+2]==(!CheckTurn?BlueCaptain:RedCaptain)&&!ChessBoard[x+1][y+1]&&0<=x+2&&x+2<=9&&0<=y+2&&y+2<=8){General=1;return;}
		if(ChessBoard[x-2][y+2]==(!CheckTurn?BlueCaptain:RedCaptain)&&!ChessBoard[x-1][y+1]&&0<=x-2&&x-2<=9&&0<=y+2&&y+2<=8){General=1;return;}
		if(ChessBoard[x+2][y-2]==(!CheckTurn?BlueCaptain:RedCaptain)&&!ChessBoard[x+1][y-1]&&0<=x+2&&x+2<=9&&0<=y-2&&y-2<=8){General=1;return;}
		if(ChessBoard[x-2][y-2]==(!CheckTurn?BlueCaptain:RedCaptain)&&!ChessBoard[x-1][y-1]&&0<=x-2&&x-2<=9&&0<=y-2&&y-2<=8){General=1;return;}
	}
	if(ChessBoard[x][y]==(CheckTurn?BlueHorse:RedHorse))
	{
		if(ChessBoard[x+1][y+2]==(!CheckTurn?BlueCaptain:RedCaptain)&&!ChessBoard[x][y+1]&&0<=x+1&&x+1<=9&&0<=y+2&&y+2<=8){General=1;return;}
		if(ChessBoard[x+2][y+1]==(!CheckTurn?BlueCaptain:RedCaptain)&&!ChessBoard[x+1][y]&&0<=x+2&&x+2<=9&&0<=y+1&&y+1<=8){General=1;return;}
		if(ChessBoard[x+2][y-1]==(!CheckTurn?BlueCaptain:RedCaptain)&&!ChessBoard[x+1][y]&&0<=x+2&&x+2<=9&&0<=y-1&&y-1<=8){General=1;return;}
		if(ChessBoard[x+1][y-2]==(!CheckTurn?BlueCaptain:RedCaptain)&&!ChessBoard[x][y-1]&&0<=x+1&&x+1<=9&&0<=y-2&&y-2<=8){General=1;return;}
		if(ChessBoard[x-1][y-2]==(!CheckTurn?BlueCaptain:RedCaptain)&&!ChessBoard[x][y-1]&&0<=x-1&&x-1<=9&&0<=y-2&&y-2<=8){General=1;return;}
		if(ChessBoard[x-2][y-1]==(!CheckTurn?BlueCaptain:RedCaptain)&&!ChessBoard[x-1][y]&&0<=x-2&&x-2<=9&&0<=y-1&&y-1<=8){General=1;return;}
		if(ChessBoard[x-2][y+1]==(!CheckTurn?BlueCaptain:RedCaptain)&&!ChessBoard[x-1][y]&&0<=x-2&&x-2<=9&&0<=y+1&&y+1<=8){General=1;return;}
		if(ChessBoard[x-1][y+2]==(!CheckTurn?BlueCaptain:RedCaptain)&&!ChessBoard[x][y+1]&&0<=x-1&&x-1<=9&&0<=y+2&&y+2<=8){General=1;return;}
	}
	if(ChessBoard[x][y]==(CheckTurn?BlueCar:RedCar))
	{
		for(int i=x+1;i<=9;i++)
		{
			if(ChessBoard[i][y]==(!CheckTurn?BlueCaptain:RedCaptain)){General=1;return;}
			if(ChessBoard[i][y])return;
		}
		for(int i=x-1;i>=0;i--)
		{
			if(ChessBoard[i][y]==(!CheckTurn?BlueCaptain:RedCaptain)){General=1;return;}
			if(ChessBoard[i][y])return;
		}
		for(int i=y+1;i<=8;i++)
		{
			if(ChessBoard[x][i]==(!CheckTurn?BlueCaptain:RedCaptain)){General=1;return;}
			if(ChessBoard[x][i])return;
		}
		for(int i=y-1;i>=0;i--)
		{
			if(ChessBoard[x][i]==(!CheckTurn?BlueCaptain:RedCaptain)){General=1;return;}
			if(ChessBoard[x][i])return;
		}
	}
	if(ChessBoard[x][y]==(CheckTurn?BlueDuck:RedDuck))
	{
		if(ChessBoard[x+2][y+3]==(!CheckTurn?BlueCaptain:RedCaptain)&&!ChessBoard[x][y+1]&&!ChessBoard[x+1][y+2]&&0<=x+2&&x+2<=9&&0<=y+3&&y+3<=8){General=1;return;}
		if(ChessBoard[x+3][y+2]==(!CheckTurn?BlueCaptain:RedCaptain)&&!ChessBoard[x+1][y]&&!ChessBoard[x+2][y+1]&&0<=x+3&&x+3<=9&&0<=y+2&&y+2<=8){General=1;return;}
		if(ChessBoard[x+3][y-2]==(!CheckTurn?BlueCaptain:RedCaptain)&&!ChessBoard[x+1][y]&&!ChessBoard[x+2][y-1]&&0<=x+3&&x+3<=9&&0<=y-2&&y-2<=8){General=1;return;}
		if(ChessBoard[x+2][y-3]==(!CheckTurn?BlueCaptain:RedCaptain)&&!ChessBoard[x][y-1]&&!ChessBoard[x+1][y-2]&&0<=x+2&&x+2<=9&&0<=y-3&&y-3<=8){General=1;return;}
		if(ChessBoard[x-2][y-3]==(!CheckTurn?BlueCaptain:RedCaptain)&&!ChessBoard[x][y-1]&&!ChessBoard[x-1][y-2]&&0<=x-2&&x-2<=9&&0<=y-3&&y-3<=8){General=1;return;}
		if(ChessBoard[x-3][y-2]==(!CheckTurn?BlueCaptain:RedCaptain)&&!ChessBoard[x-1][y]&&!ChessBoard[x-2][y-1]&&0<=x-3&&x-3<=9&&0<=y-2&&y-2<=8){General=1;return;}
		if(ChessBoard[x-3][y+2]==(!CheckTurn?BlueCaptain:RedCaptain)&&!ChessBoard[x-1][y]&&!ChessBoard[x-2][y+1]&&0<=x-3&&x-3<=9&&0<=y+2&&y+2<=8){General=1;return;}
		if(ChessBoard[x-2][y+3]==(!CheckTurn?BlueCaptain:RedCaptain)&&!ChessBoard[x][y+1]&&!ChessBoard[x-1][y+2]&&0<=x-2&&x-2<=9&&0<=y+3&&y+3<=8){General=1;return;}
	}
	if(ChessBoard[x][y]==(CheckTurn?BlueSoldier:RedSoldier))
	{
		if(ChessBoard[x+1][y]==(!CheckTurn?BlueCaptain:RedCaptain)&&0<=x+1&&x+1<=9&&0<=y&&y<=8){General=1;return;}
		if(ChessBoard[x-1][y]==(!CheckTurn?BlueCaptain:RedCaptain)&&0<=x-1&&x-1<=9&&0<=y&&y<=8){General=1;return;}
		if(ChessBoard[x][y+1]==(!CheckTurn?BlueCaptain:RedCaptain)&&0<=x&&x<=9&&0<=y+1&&y+1<=8){General=1;return;}
		if(ChessBoard[x][y-1]==(!CheckTurn?BlueCaptain:RedCaptain)&&0<=x&&x<=9&&0<=y-1&&y-1<=8){General=1;return;}
		if(ChessBoard[x+1][y+1]==(!CheckTurn?BlueCaptain:RedCaptain)&&0<=x+1&&x+1<=9&&0<=y+1&&y+1<=8){General=1;return;}
		if(ChessBoard[x-1][y+1]==(!CheckTurn?BlueCaptain:RedCaptain)&&0<=x-1&&x-1<=9&&0<=y+1&&y+1<=8){General=1;return;}
		if(ChessBoard[x+1][y-1]==(!CheckTurn?BlueCaptain:RedCaptain)&&0<=x+1&&x+1<=9&&0<=y-1&&y-1<=8){General=1;return;}
		if(ChessBoard[x-1][y-1]==(!CheckTurn?BlueCaptain:RedCaptain)&&0<=x-1&&x-1<=9&&0<=y-1&&y-1<=8){General=1;return;}
	}
}
void Check()	
{
	for(int i=0;i<=9;i++)
		for(int j=0;j<=8;j++)
		{
			if(!ChessBoard[i][j])continue;
			CheckGeneral(i,j);
			if(General)return;
		}
}
void Print(int x,int y)
{
	if(ChessBoard[x][y]==RedCaptain)printf("red captain;");
	else if(ChessBoard[x][y]==BlueCaptain)printf("blue captain;");
	else if(ChessBoard[x][y]==RedGuard)printf("red guard;");
	else if(ChessBoard[x][y]==BlueGuard)printf("blue guard;");
	else if(ChessBoard[x][y]==RedElephant)printf("red elephant;");
	else if(ChessBoard[x][y]==BlueElephant)printf("blue elephant;");
	else if(ChessBoard[x][y]==RedHorse)printf("red horse;");
	else if(ChessBoard[x][y]==BlueHorse)printf("blue horse;");
	else if(ChessBoard[x][y]==RedCar)printf("red car;");
	else if(ChessBoard[x][y]==BlueCar)printf("blue car;");
	else if(ChessBoard[x][y]==RedDuck)printf("red duck;");
	else if(ChessBoard[x][y]==BlueDuck)printf("blue duck;");
	else if(ChessBoard[x][y]==RedSoldier)printf("red soldier;");
	else if(ChessBoard[x][y]==BlueSoldier)printf("blue soldier;");
	if(DieChess==RedCaptain)printf("red captain;");
	else if(DieChess==BlueCaptain)printf("blue captain;");
	else if(DieChess==RedGuard)printf("red guard;");
	else if(DieChess==BlueGuard)printf("blue guard;");
	else if(DieChess==RedElephant)printf("red elephant;");
	else if(DieChess==BlueElephant)printf("blue elephant;");
	else if(DieChess==RedHorse)printf("red horse;");
	else if(DieChess==BlueHorse)printf("blue horse;");
	else if(DieChess==RedCar)printf("red car;");
	else if(DieChess==BlueCar)printf("blue car;");
	else if(DieChess==RedDuck)printf("red duck;");
	else if(DieChess==BlueDuck)printf("blue duck;");
	else if(DieChess==RedSoldier)printf("red soldier;");
	else if(DieChess==BlueSoldier)printf("blue soldier;");
	else printf("NA;");
	printf((!isOver&&General)?"yes;":"no;");
	printf(isOver?"yes":"no");
	printf("\n");
}
int main()
{
	int n;
	ChessInit();
	scanf("%d",&n);
	for(int i=1,Startx,Starty,Endx,Endy;i<=n;i++)
	{
		scanf("%d%d%d%d",&Startx,&Starty,&Endx,&Endy);
		if(isOver){printf("Invalid command\n");continue;}
		Moveinit();
		Move(Startx,Starty,Endx,Endy);
		if(isOut)continue;
		Check();
		Print(Endx,Endy);
		Turn=(Turn?0:1);
	}
}
