#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

int a[5];
int T;

bool v[25][25][25][25];

struct node{
	int w[5];
	int cnt;
};

int main()
{
	while(scanf("%d%d%d%d%d",&a[0],&a[1],&a[2],&a[3],&T)!=EOF)
	{
		node q[25000];
		if(a[0]<T && a[1]<T && a[2]<T && a[3]<T)
		{
			printf("-1\n");
			continue;
		}
		a[4]=400;
		memset(v,0,sizeof(v));
		int head=0;
		int rear=0;
		node s;
		s.cnt = 0;
		v[0][0][0][0]=1;
		for(int i = 0; i < 4; i++)
			s.w[i]= 0;
		s.w[4] = 400;
		q[rear++]=s;
		while(head!=rear)
		{
			//cout<<q[head].w[0]<<" "<<q[head].w[1]<<" "<<q[head].w[2]<<" "<<q[head].w[3]<<" "<<q[head].w[4]<<"   "<<q[head].cnt<<endl;
			if(q[head].w[0]==T || q[head].w[1]==T || q[head].w[2]==T || q[head].w[3]==T)
			{
				printf("%d\n",q[head].cnt);
				//cout<<endl;
				break;
			}
			for(int i = 0; i < 5; i++)
				for(int j = 0; j < 5; j++)
				{
					if(i==j)
						continue;
					node tmp;
					if(q[head].w[i]+q[head].w[j]<=a[i])
					{
						
						for(int k = 0; k < 5; k++)
						{
							if(k == i)
								tmp.w[i]=q[head].w[i]+q[head].w[j];
							else if(k == j)
								tmp.w[j]=0;
							else
								tmp.w[k]=q[head].w[k];
						}
						if(!v[tmp.w[0]][tmp.w[1]][tmp.w[2]][tmp.w[3]])
						{
							tmp.cnt = q[head].cnt+1;
							v[tmp.w[0]][tmp.w[1]][tmp.w[2]][tmp.w[3]] = 1;
							q[rear++]=tmp;
						}
					}
					else
					{
						
						for(int k = 0; k < 5; k++)
						{
							if(k == i)
								tmp.w[i]=a[i];
							else if(k == j)
								tmp.w[j]=q[head].w[j]-(a[i]-q[head].w[i]);
							else
								tmp.w[k]=q[head].w[k];
						}
						if(!v[tmp.w[0]][tmp.w[1]][tmp.w[2]][tmp.w[3]])
						{
							v[tmp.w[0]][tmp.w[1]][tmp.w[2]][tmp.w[3]] = 1;
							tmp.cnt = q[head].cnt+1;
							q[rear++]=tmp;
						}
					}
				}
			head++;
		}
		if(head == rear)
			printf("-1\n");
	}
}
