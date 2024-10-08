#include<bits/stdc++.h>
#define ll long long
#define db double
#define vct vector
#define pi 3.141592653589793
#define mt 75
using namespace std;
const char *st="0123456789()+-*/";
db rad(db ang){return ang/180.0*pi;}
struct Image
{
	vct<vct<ll>> sth;
	ll sx,sy;
    Image(){};
	Image(ll sx,ll sy):sx(sx),sy(sy)
	{
		sth.resize(sx);
		fill(sth.begin(),sth.end(),vct<ll>(sy));
	}
    Image(string &str)
    {
        sx=sy=0;stringstream ss;string tmps;
        for(ss<<str;ss>>tmps;)
        {
            vector<ll>tmpv;
            for(auto i:tmps)tmpv.push_back(i!='.');
            sth.push_back(tmpv);
			++sx;sy<tmpv.size()?sy=tmpv.size():0;
        }
    }
    Image(const char *str)
    {
        sx=sy=0;stringstream ss;string tmps;
        for(ss<<str;ss>>tmps;)
        {
            vector<ll>tmpv;
            for(auto i:tmps)tmpv.push_back(i!='.');
            sth.push_back(tmpv);
			++sx;sy<tmpv.size()?sy=tmpv.size():0;
        }
    }
    Image subImage(ll sx,ll sy,ll ex,ll ey)
    {
        Image res(ex-sx+1,ey-sy+1);
        for(ll i=sx;i<=ex;i++)
            for(ll j=sy;j<=ey;j++)
				res.sth[i-sx][j-sy]=sth[i][j];
        return res;
    }
}ImageQ,rdset[16][mt];
db operator==(Image& img1,Image& img2)
{
	db cnt=0;
	for(ll i=0;i<img1.sx;i++)
		for(ll j=0;j<img1.sy;j++)
			cnt+=img2.sth[i][j]==img1.sth[i][j];
	return cnt/db(img1.sx*img1.sy);
}
Image cover(Image img1,Image img2,ll sx,ll sy)
{
	Image res(img1);
	for(ll i=max(0ll,-sx);i<min(img2.sx,img1.sx-sx);i++)
		for(ll j=max(0ll,-sy);j<min(img2.sy,img1.sy-sy);j++)
			res.sth[i+sx][j+sy]=img2.sth[i][j];
	return res;
}
Image denoise(Image img)
{
	Image res(img);
	ll dx[10]={0,0,1,1,0,-1,-1,-1,0,1},dy[10]={0,0,0,1,1,1,0,-1,-1,-1};
	for(ll x=0;x<img.sx;x++)
		for(ll y=0;y<img.sy;y++)
		{  
			ll cntBlack=0,cntAll=0;
			for(ll i=1;i<=9;i++)
			{  
				ll xx=x+dx[i],yy=y+dy[i];
				if(xx>=0&&xx<img.sx&&yy>=0&&yy<img.sy)cntAll++,cntBlack+=img.sth[xx][yy];
			}
			res.sth[x][y]=(cntBlack>(cntAll-cntBlack));
		}
	return res;
}
vct<Image>split(Image img,ll mins=15)
{
	vct<Image>res;
	queue<pair<ll,ll>>q;//存储连通块中的黑点
	ll minx,maxx,miny,maxy;
	for(ll j=0;j<img.sy;j++)
		for(ll i=0;i<img.sx;i++)//遍历整张图，注意变量枚举顺序
			if(img.sth[i][j])//如果此处存在黑点
			{  
				minx=miny=INT_MAX,maxx=maxy=INT_MIN;//得到与它相连的连通块
				queue<pair<ll,ll>>tmpq;
				ll dx[5]={0,0,1,0,-1}, dy[5]={0,1,0,-1,0};
				tmpq.push({i,j});
				q.push(tmpq.back());
				maxx<i?maxx=i:0,maxy<j?maxy=j:0,minx>i?minx=i:0,miny>j?miny=j:0;
				img.sth[i][j]=0;
				while(tmpq.size())
				{
					auto top=tmpq.front();tmpq.pop();
					for(ll k=1;k<=4;k++)
					{
						ll xx=top.first+dx[k],yy=top.second+dy[k];
						if(xx>=0&&xx<img.sx&&yy>=0&&yy<img.sy&&img.sth[xx][yy])
						{
							tmpq.push({xx,yy});
							q.push(tmpq.back());
							img.sth[xx][yy]=0;
							maxx<xx?maxx=xx:0,maxy<yy?maxy=yy:0,minx>xx?minx=xx:0,miny>yy?miny=yy:0;
						}
					}
				}
				if(q.size()>=mins)//这里的判断是防止有些噪点未被处理干净，被当为单个字符分离出去
				{  
					Image tmpimg(maxx-minx+1,maxy-miny+1);  //依据大小构建子图
					while(q.size())
					{
						auto p=q.front();q.pop();
						tmpimg.sth[p.first-minx][p.second-miny]=1;//将队列里的黑点放到子图的相应位置
					}
					res.push_back(tmpimg);//将子图放到列表里面
				}
				while(q.size())q.pop();
			}
	return res;
}
Image balance(Image img)
{
	Image res(65,38);
	ll sumx=0,sumy=0,sumc=0;
	for(ll i=0;i<img.sx;i++)
		for(ll j=0;j<img.sy;j++)
			if(img.sth[i][j])sumx+=i,sumy+=j,sumc++;
	ll midx=(2*sumx+sumc)/(2*sumc),midy=(2*sumy+sumc)/(2*sumc);  //确定中心位置
	ll delx=32-midx,dely=19-midy;//确定偏移量
	res=cover(res,img,delx,dely);//进行平移
	return res;
}
vct<Image>sign//各个字符对应的图像
{  
R"(
...........########...........
.........############.........
.......################.......
......##################......
.....####################.....
....######################....
...########################...
...##########....##########...
..#########........#########..
..########..........########..
.#########..........#########.
.########............########.
.########............########.
.########............########.
########..............########
########..............########
########..............########
########..............########
########..............########
########..............########
########..............########
########..............########
########..............########
########..............########
########..............########
.########............########.
.########............########.
.########............########.
.#########..........#########.
..########..........########..
..#########........#########..
...##########....##########...
...########################...
....######################....
.....####################.....
......##################......
.......################.......
.........############.........
...........########...........
)",
R"(
.............####..........
...........#######.........
........##########.........
.....#############.........
..################.........
.#################.........
.#################.........
.#################.........
.#################.........
..######..########.........
..###.....########.........
..........########.........
..........########.........
..........########.........
..........########.........
..........########.........
..........########.........
..........########.........
..........########.........
..........########.........
..........########.........
..........########.........
..........########.........
..........########.........
..........########.........
..........########.........
..........########.........
..........########.........
..........########.........
..........########.........
..........########.........
..........########.........
.##########################
###########################
###########################
###########################
###########################
.##########################
)",
R"(
.........#########..........
......##############........
...###################......
..#####################.....
.#######################....
.#######################....
.########################...
.#########......#########...
.#######.........#########..
.#######..........########..
.#######..........########..
.#######..........########..
.#######..........########..
..######..........########..
.................#########..
.................########...
................#########...
...............##########...
..............##########....
.............###########....
............###########.....
...........###########......
..........###########.......
.........###########........
........###########.........
.......###########..........
......###########.....#####.
.....###########.....#######
....###########......#######
...###########.......#######
..###########........#######
.###########.........#######
############################
############################
############################
############################
############################
.###########################
)",
R"(
.........##########.........
.....################.......
...####################.....
..######################....
..#######################...
..########################..
..########################..
..########.......##########.
..#######.........#########.
..#######..........########.
..#######..........########.
...######..........########.
...................########.
...................########.
..................########..
.................#########..
..........###############...
.........###############....
.........##############.....
.........###############....
.........################...
..........################..
.................##########.
...................########.
...................#########
....................########
....................########
....................########
....................########
...................#########
..###.............##########
.########........##########.
.##########################.
.#########################..
##########################..
.########################...
.######################.....
....#################.......
.......###########..........
)",
R"(
.................#####........
................#######.......
...............########.......
..............#########.......
.............##########.......
............###########.......
............###########.......
...........############.......
..........#############.......
.........##############.......
........###############.......
.......################.......
.......########.#######.......
......########..#######.......
.....########...#######.......
....########....#######.......
...#########....#######.......
...########.....#######.......
..########......#######.......
.########.......#######.......
##############################
##############################
##############################
##############################
##############################
##############################
...............########.......
...............########.......
...............########.......
...............########.......
...............########.......
...............########.......
.........####################.
........#####################.
........#####################.
........#####################.
........#####################.
.........####################.
)",
R"(
...######################...
...#######################..
...#######################..
...#######################..
...#######################..
...######################...
...#######..................
...#######..................
...#######..................
...#######..................
...#######..................
...#######..................
..########..########........
..####################......
..######################....
..#######################...
..########################..
..########################..
..#########################.
..########.......##########.
.....##...........#########.
...................#########
....................########
....................########
....................########
....................########
....................########
....................########
...#...............#########
..####............#########.
.########.......###########.
.##########################.
.#########################..
#########################...
.#######################....
..#####################.....
....#################.......
........##########..........
)",
R"(
....................######...
...............###########...
............###############..
..........#################..
........###################..
.......####################..
......####################...
.....################........
....############.............
...###########...............
...#########.................
..#########..................
..########...................
.########....................
.########....................
.#######....########.........
.#######..#############......
#########################....
##########################...
###########################..
###########################..
############......##########.
##########.........#########.
#########...........#########
########.............########
########.............########
########.............########
.#######.............########
.#######.............########
.########...........#########
.#########.........#########.
..##########.....###########.
...#########################.
...########################..
....######################...
.....####################....
......##################.....
........##############.......
...........########..........
)",
R"(
###########################.
############################
############################
############################
############################
###########################.
#######...........#########.
#######...........#########.
#######..........#########..
#######..........#########..
#######..........########...
#######.........#########...
#######.........########....
#######........#########....
.#####.........#########....
...............########.....
..............#########.....
..............########......
.............#########......
.............########.......
............#########.......
............#########.......
............########........
...........#########........
...........########.........
..........#########.........
..........########..........
..........########..........
.........########...........
.........########...........
........#########...........
........########............
........########............
.......########.............
.......########.............
.......#######..............
.......#######..............
.........#####..............
)",
R"(
..........#########.........
........#############.......
......#################.....
.....###################....
....#####################...
...#######################..
...#######################..
...#########.....#########..
..#########.......#########.
..########.........########.
..########.........########.
..########.........########.
..########.........########.
..########.........########.
...########.......########..
...#########.....#########..
....#####################...
.....###################....
......#################.....
......#################.....
....#####################...
...#######################..
..#########......##########.
.########..........########.
.########..........#########
########............########
########............########
########............########
########............########
#########..........#########
#########..........#########
.##########......##########.
.##########################.
..########################..
..########################..
...######################...
....####################....
......################......
.........##########.........
)",
R"(
.........#########..........
.......#############........
.....#################......
....###################.....
...#####################....
..#######################...
.########################...
.##########......#########..
.#########........#########.
#########..........########.
########............#######.
########............#######.
########............########
########............########
########............########
#########..........#########
.########.........##########
.##########......###########
..##########################
..##########################
...#########################
....########################
......############..########
........########....#######.
....................#######.
...................########.
...................########.
..................########..
.................#########..
...............##########...
.............############...
.........###############....
....###################.....
...###################......
...##################.......
...################.........
...##############...........
...############.............
....######..................
)",
R"(
...............####..
..............######.
............########.
...........##########
..........###########
.........############
........############.
.......###########...
......###########....
.....###########.....
.....##########......
....##########.......
....#########........
...#########.........
...########..........
..#########..........
..########...........
.#########...........
.########............
.########............
.########............
#########............
########.............
########.............
########.............
########.............
########.............
########.............
########.............
########.............
########.............
########.............
.########............
.########............
.########............
.#########...........
..########...........
..#########..........
..#########..........
...#########.........
...##########........
....#########........
.....#########.......
.....##########......
......###########....
.......###########...
........###########..
.........############
..........###########
...........##########
............#########
.............#######.
...............####..
.................#...
)",
R"(
..####...............
.######..............
#########............
##########...........
###########..........
############.........
.############........
...###########.......
....###########......
.....##########......
......##########.....
.......##########....
........#########....
.........#########...
..........########...
..........#########..
...........########..
...........#########.
............########.
............########.
............########.
............#########
.............########
.............########
.............########
.............########
.............########
.............########
.............########
.............########
.............########
.............########
............########.
............########.
............########.
...........#########.
...........########..
..........#########..
..........#########..
.........#########...
........##########...
.......##########....
.......#########.....
.....###########.....
....###########......
...###########.......
..###########........
############.........
###########..........
##########...........
#########............
.#######.............
..####...............
...#.................
)",
R"(
...........#####...........
..........#######..........
..........#######..........
..........#######..........
..........#######..........
..........#######..........
..........#######..........
..........#######..........
..........#######..........
..........#######..........
###########################
###########################
###########################
###########################
###########################
###########################
###########################
..........#######..........
..........#######..........
..........#######..........
..........#######..........
..........#######..........
..........#######..........
..........#######..........
..........#######..........
..........#######..........
..........#######..........
...........#####...........
)",
R"(
.##########################.
############################
############################
############################
############################
############################
.###########################
)",
R"(
...........####...........
..........######..........
..........#######.........
.........########.........
.........########.........
..........#######.........
..........######..........
.#####....######.....####.
.######...######...#######
#########..#####.#########
###############.##########
##########################
##########################
.########################.
......##############......
.........########.........
........###########.......
.......#############......
.....########.#######.....
....########..########....
....########..#########...
...########....########...
...########....########...
....#######.....#######...
.....#####......######....
......###.........##......
)",
R"(
......................####..
......................######
.....................#######
.....................#######
....................########
....................#######.
...................########.
...................#######..
..................########..
..................#######...
.................########...
.................#######....
................########....
................########....
................#######.....
...............########.....
...............#######......
..............########......
..............#######.......
.............########.......
.............#######........
............########........
............#######.........
...........########.........
...........#######..........
..........########..........
..........#######...........
..........#######...........
.........########...........
.........#######............
........########............
........#######.............
.......########.............
.......#######..............
......########..............
......#######...............
.....########...............
.....#######................
....########................
....#######.................
...########.................
...########.................
...#######..................
..########..................
..#######...................
.########...................
.#######....................
########....................
#######.....................
.######.....................
..#####.....................
)",
};
ll Signpos[16][2] =// 字符在原来尺寸下的左上角的位置
{  
	{7,4},{7,6},{7,5},{7,5},{7,4},{8,5},{7,5},{8,6},{7,5},{7,5},{4,8},{4,9},{13,6},{23,5},{7,6},{3,5}
};
char recognize(Image img)
{
	db rt=0;ll id=-1;  
	Image imgtmp=balance(img);//调整img的位置
	for(ll i=0;i<mt;i++)
		for(ll j=0;j<16;j++)
		{
			db r=(imgtmp==rdset[j][i]);//比较相似程度
			if(r>rt)rt=r,id=j;//如果匹配度最大记录匹配度/编号
		}
	return st[id];  //返回对应的字符
}
ll t,n,m;
vct<Image>ImageQ_splited;
void init(ll id)
{
	for(int i=0;i<16;i++)sign[i]=cover(Image(65,38),sign[i],Signpos[i][0],Signpos[i][1]);
	db Mmin=0.9,Mmax=1,Rmin,Rmax,Smin,Smax;
	if(0<=id&&id<30)Rmin=-2,Rmax=2,Smin=Smax=0;
	else if(30<=id&&id<90)Rmin=-10,Rmax=10,Smin=-0.1,Smax=0.1;
	else Rmin=-15,Rmax=15,Smin=-0.1,Smax=0.1;
	uniform_real_distribution<> M(Mmin,Mmax),R(Rmin,Rmax),S(Smin,Smax);//初始化随机数生成器
	default_random_engine ran(time(NULL));  //初始化随机数生成器
	for(ll i=0;i<16;i++)
		for(ll j=0;j<mt;j++)
		{
			db TM=M(ran),TMx=M(ran),TMy=M(ran),TR=R(ran),TSx=S(ran),TSy=S(ran);
			Image res(65,38);
			for(ll it=0;it<65;it++)
				for(ll jt=0;jt<38;jt++)
					if(sign[i].sth[it][jt])
					{
						db x=jt+0.5-19,y=it+0.5-32.5;//先对像素点进行平移，方便后面的旋转,扭曲操作
						x*=TM*TMx,y*=TM*TMy;//进行横向/纵向伸缩变换
						db xx=x*cos(rad(TR))-y*sin(rad(TR)),yy=x*sin(rad(TR))+y*cos(rad(TR));  //进行旋转变换
						x=xx+TSy*yy,y=yy+TSx*xx;  //进行扭曲变换
						ll X=(ll)(round(y+32.5-0.5)),Y=(ll)(round(x+19-0.5));  //最终的X, Y坐标
						if(X>=0&&X<65&&Y>=0&&Y<38)res.sth[X][Y]=1;
					}
			rdset[i][j]=balance(denoise(res));//对变换后的图像降噪后再摆正位置
		}
}
ll calc(string &stmt)
{
	vct<ll>stk1;vct<char>stk2;
    ll optnum=0,fg=0;
	auto cal=[&](char c)
	{
		ll b=stk1.back();stk1.pop_back();
		ll a=stk1.back();stk1.pop_back();
		switch (c)
		{
			case '+':{stk1.push_back(a+b);break;}
			case '-':{stk1.push_back(a-b);break;}
			case '*':{stk1.push_back(a*b);break;}
			case '/':{stk1.push_back(a/b);break;}
		}
	};
	auto level=[](char c)
	{
		switch(c)
		{
			case '(':{return 0;break;}
			case '+':{return 1;break;}
			case '-':{return 1;break;}
			case '*':{return 2;break;}
			case '/':{return 2;break;}
			default:{return -1;}
		}
	};
	for(auto c:stmt)
	{
		if(c>='0'&&c<='9')optnum=10*optnum+(c-48),fg=1;
		else
		{
			if(fg){stk1.push_back(optnum);fg=0,optnum=0;}
			if(stk2.empty())stk2.push_back(c);
			else
			{
				switch(c)
				{
					case '(':{stk2.push_back(c);break;}
					case ')':{while(stk2.back()!='('){cal(stk2.back());stk2.pop_back();}stk2.pop_back();break;}	
					default:{while(!stk2.empty()&&level(c)<=level(stk2.back())){cal(stk2.back());stk2.pop_back();}stk2.push_back(c);}
				}
			}
		}
	}
	if(isdigit(stmt.back()))stk1.push_back(optnum);
	while(stk2.size()){cal(stk2.back());stk2.pop_back();}
	return stk1.back();
}
int main()
{
	string word,question;
	cin>>t>>n>>m; 
	init(t);
    while(cin>>word){question+=word+' ';}
    ImageQ=Image(question);
    ImageQ=denoise(ImageQ);
    ImageQ_splited=split(ImageQ);
    word.clear();
    for(const auto &i:ImageQ_splited){word+=recognize(i);}
    cout<<calc(word)<<endl;
	return 0;
}
