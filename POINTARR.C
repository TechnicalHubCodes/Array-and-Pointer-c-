#include<stdio.h>
#include<conio.h>
int * func(int *,int *);
void main()
{
	int n,a[100],*b,i;
	clrscr();
	printf("Enter No of elements: ");
	scanf("%d",&n);
	printf("\nEnter Elements: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",a+i);
	}
	b=func(&n,a);
	printf("\nExact array elements: ");
	for(i=0;i<n;i++)
	{
		printf(" %d\t",*(b+i));
	}
	getch();
}
int * func(int *n,int in[100])
{
	int i,j,k=0;
	static int out[100];
	for(i=0;i<*n;i++)     //in: 1 2 1 2 3
	{
	 for(j=i+1;j<*n;j++)
	 {
		if(in[i]==in[j])
		{                            //in: 1 2 0 2 3
			in[j]=0;                  //out: 1 2 2 3
		}
	 }                               //in: 1 2 0 0 3
	}
	for(i=0;i<*n;i++)
	{
		if(in[i]!=0)                 //out: 1 2 3
		{
			out[k++]=in[i];
		}                             //n=k=3
	}
	*n=k;
	return out;
}
