struct test{
	int a,b,c;
};
 
bool comp(const test d,const test e)
{
	if(d.a==e.a)
	return d.b<e.b;	//Incresing Order according to second value (if first values are equal)
	else
	return d.a<e.a;	//Increasing Order according to First value (if first values are not equal)
}
 
 
bool comp1(const test d,const test e)
{
	if(d.a==e.a)
	return d.b>e.b;	//Dncresing Order according to second value (if first values are equal)
	else
	return d.a>e.a;	//Dncreasing Order according to First value (if first values are not equal)
}
 
 
int main()
{
		struct test arr[20]={0};
 		int i,m,r,t;
 		scanf("%d",&t);
 
		 for(i=0;i<t;i++)
			scanf("%d %d",&arr[i].a,&arr[i].b);
 
		for(int i=0;i<t;i++)
			printf("%d %d\n",arr[i].a,arr[i].b);
 
		sort(arr,arr+t,comp);
 
		printf("\n\n");
 
		for(int i=0;i<t;i++)
			printf("%d %d\n",arr[i].a,arr[i].b);
 
		sort(arr,arr+t,comp1);
 
		printf("\n\n");
 
		for(int i=0;i<t;i++)
			printf("%d %d\n",arr[i].a,arr[i].b);
 
 
 
return 0;		
}
/*
 stdin copy
3
1 3
3 2
2 4
  stdout copy
1 3
3 2
2 4


1 3
2 4
3 2


3 2
2 4
1 3
*/
