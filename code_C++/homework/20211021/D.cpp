#include<iostream>
#include<cstdio>
using namespace std;
int b,j,top,top2;
char a[20]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J'};
char stack[100005],stack2[100005];
bool t=true;
int main()
{
//	freopen("palsquare.in","r",stdin);
//	freopen("palsquare.out","w",stdout);
	cin>>b;
	for(int i = 1; i <= 200 ; i++)
	{
		j=i*i;
		top=0;
		while(j >= b)
		{
			stack[++top]=a[ j % b ];
			j/=b;
		}
		stack[++top]=a[j];
		for(j = 1 ; j <= top/2; j++)
		{
			if(stack[j] != stack[top-j+1]) t=false;
		}
		if(t==true)
		{
			j=i;
			top2=0;
			while(j >= b)
			{
				stack2[++top2]=a[j % b];
				j/=b;
			}
			stack2[++top2]=a[j];
			for(j = top2; j >= 1; j--)
			{
				printf("%c",stack2[j]);
			}
			printf(" ");
			for(j = top; j >= 1; j--)
			{
				printf("%c",stack[j]);
			}
			printf("\n");
		}
		t=true;
	}
	return 0;
}
