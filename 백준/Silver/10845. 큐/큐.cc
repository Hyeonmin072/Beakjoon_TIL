#include<stdio.h>
#include<string.h>
int q[10001];
int main()
{
	char a[10];
	int n,k,i,st,ed;
	scanf("%d",&n);

	st=ed=-1; // 키 초기화
	for(i=1;i<=n;i++)
	{
		scanf("%s",&a);
		if(strcmp(a,"push")==0)
		{
			scanf("%d",&k);
			q[++st]=k;
		}
		else if(strcmp(a,"pop")==0)
		{
			if(st==ed) printf("-1\n");
			else printf("%d\n",q[++ed]);
		}
		else if(strcmp(a,"size")==0)
		{
			printf("%d\n",st-ed);
		}
		else if(strcmp(a,"empty")==0)
		{
			if(st==ed) printf("1\n");
			else printf("0\n");
		}
		else if(strcmp(a,"front")==0)
		{
			if(st==ed) printf("-1\n");
			else printf("%d\n",q[ed+1]);
		}
		else if(strcmp(a,"back")==0)
		{
			if(st==ed) printf("-1\n");
			else printf("%d\n",q[st]);
		}
	}
	return 0;
}