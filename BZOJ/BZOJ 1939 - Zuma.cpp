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
int f[111][111][11],val[111];
int main()
{
	memset(f,0x3f3f3f3f,sizeof f);
	int n=read(),K=read();
	for(int i=1;i<=n;++i)val[i]=read();
	for(int i=1;i<=n;++i)
		for(int j=0;j<K;++j)
			f[i][i][j]=K-j-1;
	for(int l=2;l<=n;++l)//ö�����䳤�� 
	{
		for(int i=1,j=i+l-1;j<=n;++i,++j)//ö���������Ҷ˵� 
		{
			{//K-1��������� 
				f[i][j][K-1]=min(f[i][j][K-1],f[i+1][j][0]);//���ܹ�K-1��ʱ�������� 
				if(val[i]==val[i+1])//��i��i+1���� 
				{
					f[i][j][K-1]=min(f[i][j][K-1],f[i+1][j][K-1]);
				}
				for(int k=i+2;k<=j;++k)//ͬ�ϣ���i��k������������ʹi��k����������
				{
					if(val[i]==val[k])
					{
						f[i][j][K-1]=min(f[i][j][K-1],f[i+1][k-1][0]+f[k][j][K-1]);
					}
				}
			}
			{//������� 
				for(int k=K-2;k>=0;--k)//ö��������ͬ������ 
				{
					f[i][j][k]=min(f[i][j][k],f[i][j][k+1]+1);//����һ���µ�����
					if(val[i]==val[i+1])//��i��i+1���� 
					{
						f[i][j][k]=min(f[i][j][k],f[i+1][j][k+1]);
					}
					for(int m=i+2;m<=j;++m)
					{
						if(val[i]==val[m])
						{
							f[i][j][k]=min(f[i][j][k],f[i+1][m-1][0]+f[m][j][k+1]);
						}
					}
				} 
			}
		}
	}
	write(f[1][n][0]);
	return 0;
}

