#include<bits/stdc++.h>
using namespace std;
int matrix[1001][1001],lenx,leny;
char mp[1010][1010],cpy[8][8]=
{
"  +---+",
" /   /|",
"+---+ |",
"|   | +",
"|   |/",
"+---+"
};
const int st[6]={2,1,0,0,0,0},ed[6]={6,6,6,6,5,4};
void update(int x,int y)
{
    for(int i=5;~i;--i)
        for(int j=st[i];j<=ed[i];++j)
        {
            mp[5-i+x][j+y]=cpy[i][j];
            if(5-i+x>lenx)lenx=5-i+x;
            if(j+y>leny)leny=j+y;
        }
}

int main()
{
	int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            scanf("%d",&matrix[i][j]);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            for(int k=1;k<=matrix[i][j];++k)
                update((n-i)*2+3*k-2,(n-i)*2+4*j-3);
    for(int i=lenx;i>=1;--i)
    {    
        for(int j=1;j<=leny;++j)putchar(mp[i][j]=='\000'?'.':mp[i][j]);
        putchar('\n');
    }
}
