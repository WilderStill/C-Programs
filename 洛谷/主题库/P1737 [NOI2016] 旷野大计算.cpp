#include<bits/stdc++.h>
using namespace std;
int main()
{
    int op;
    scanf("%d",&op);
    switch(op)
    {
        case 1:{printf("I\nI\n+ 1 2\n+ 3 3\n- 4\nO 5");break;}
        case 2:{printf("I\n< 1 4\n+ 1 2\n- 3\nS 4\nO 5");break;}
        case 3:{printf("I\n< 1 999\nS 2\nC 3 -0.5\n+ 4 4\nO 5");break;}
        case 4:{printf("I\nC 1 0.000000000001\n< 2 114\nS 3\n< 4 114\n> 2 112\n+ 5 6\nS 7\nC 8 -0.5\n< 9 115\n- 10\n+ 11 1\n+ 12 5\nO 13");break;}
        case 5:{for(int i=1;i<=32;i++)printf("I\n");for(int i=1;i<=31;i++)printf("< %d %d\n",i,32-i);printf("+ 32 33\n");for(int i=1;i<=30;i++)printf("+ %d %d\n",33+i,i+63);printf("O 94");break;}
        case 6:
		{
			int k=2;
			string a[31]={"-4398046510884","-8796093021988","-17592186044196","-35184372088612","-70368744177444","-140737488355108","-281474976710436","-562949953421092","-1125899906842404","-2251799813685028","-4503599627370249","-9007199254740772","-18014398509481764","-36028797018963748","-72057594037927716","-144115188075855652","-288230376151711524","-576460752303423268","-1152921504606846756","-2305843009213693732","-4611686018427387684","-9223372036854775588","-18446744073709551396","-36893488147419103012","-73786976294838206244","-147573952589676412708","-295147905179352825636","-590295810358705651492","-1180591620717411303204","-2361183241434822606628","-4722366482869645213476"};
			//2^42-220~2^72-220  long long存不下，就用string存吧 
			printf("I\n");
			printf("< 1 41\n");
			for(int i=31;i>=1;i--)
			{
				printf("C %d %s\n",k,a[i-1].c_str());
				printf("S %d\n",k+1);
				printf("O %d\n",k+2);
				printf("- %d\n",k+3);
				printf("< %d %d\n",k+4,41+i);
				printf("+ %d %d\n",k+5,k); 
				k+=6;
			}
			printf("> %d 41\n",k);
			printf("O %d",k+1);
			break;
		}
		case 7:{printf("I\nI\n+ 1 2\n+ 3 3\n- 4\nO 5");break;}
		case 8:
		{
			//只算到 In(4+sqrt(15)) , 计算器NB 
			printf("I\n");
			printf("> 1 114\n");
			printf("C 2 2.0634370688955605467272811726201\n");
			printf("S 3\n");
			printf("C 4 -0.887298334620741688517926539978236773937633025540819832675154107295416657242528255923059519\n");
			printf("< 5 114\n");
			printf("O 6");
			break;
		}
		case 9:
		{
			int num[17],k=16;
			for(int i=1;i<=16;i++)printf("I\n"),num[i]=i;
			for(int i=1;i<=15;i++)
				for(int j=i+1;j<=16;j++)
				{
					printf("+ %d %d\n",num[i],num[j]);//a+b
					printf("- %d\n",num[j]);
					printf("+ %d %d\n",num[i],k+2);//a-b
					{
						printf("C %d 0.000000000001\n",k+3);
						printf("< %d 114\n",k+4);
						printf("S %d\n",k+5);
						printf("< %d 114\n",k+6);
						printf("> %d 112\n",k+3);
						printf("+ %d %d\n",k+7,k+8);
						printf("S %d\n",k+9);
						printf("C %d -0.5\n",k+10);
						printf("< %d 115\n",k+11);
						printf("- %d\n",k+12);
						printf("+ %d %d\n",k+3,k+13);
						printf("+ %d %d\n",k+7,k+14);
					}//abs(a-b)
					printf("- %d\n",k+15);
					printf("+ %d %d\n",k+1,k+16);
					printf("> %d 1\n",k+17);
					//min(a,b)=(a+b-|a-b|)/2
					num[i]=k+18;
					printf("- %d\n",k+18);
					printf("+ %d %d\n",k+1,k+19);
					num[j]=k+20;
					k+=20;
				}
			for(int i=1;i<=16;i++)printf("O %d\n",num[i]);
			break;
		}
		case 10://是在调不出来了，只能看题解了qwq 
		{
			string ln3="1.098612288668109691395245236922525704647490557822749451734694333637494293218608966873615755";
			string xi="1.066957896924816708625046347307968444026981971467516479768472256920460185416443976074219013";
			string Sxi="0.788675134594812882254574390250978727823800875635063438009301163241988836151466673690233534";
			printf("I\nI\nI\n");						
			printf("> 1 130\n> 2 130\n");
			printf("+ 4 5\n");
			printf("C 4 -%s\nC 5 -%s\nC 6 -%s\n",ln3.c_str(),ln3.c_str(),ln3.c_str());			
			printf("S 7\nS 8\nS 9\n");
			printf("> 4 4\n"); 					
			printf("> 4 3\n");
			printf("> 5 4\n");
			printf("> 5 3\n");
			printf("+ 13 14\n+ 15 16\n");
			printf("- 17\n- 18\n");
			printf("+ 19 20\n");
			printf("+ 10 19\n");
			printf("+ 11 20\n");
			printf("+ 12 21\n");
			printf("C 22 %s\nC 23 %s\nC 24 %s\n",xi.c_str(),xi.c_str(),xi.c_str());
			printf("S 25\nS 26\nS 27\n");
			printf("+ 28 29\n");
			printf("- 30\n");
			printf("+ 31 32\n");
			printf("C 33 -%s\n",Sxi.c_str());
			printf("< 34 %d\n",266+41);
			for(int i=36,j=63;j>=0;j--,i+=12)
			{
				printf("< 3 %d\n",41+j);
				printf("+ %d %d\n",i,i-1);
				printf("S %d\n",i+1);
				printf("< %d 179\n",i+2);
				printf("> %d 178\n",i);
				printf("+ %d %d\n",i+4,i+3);
				printf("S %d\n",i+5);
				printf("C %d -0.5\n",i+6);
				printf("< %d %d\n",i+7,180);
				printf("- %d\n",i+3);
				printf("+ %d %d\n",i+9,i+8);
				printf("+ %d %d\n",i+10,i-1);
			}
			printf("> 803 41\n");
			printf("C 804 0.100000000064\n");
			printf("- 805\n");
			printf("O 806");
			break;
		}
    }
    return 0;
}
