#include<stdio.h>
#include<string.h>

int main(){
	int i;
	int d_off,m_off,y_off,c_off,p,q,r;
	int d,m,y;
	l1:

	printf("\nEnter the day ,month and year :");
	scanf("%d%d%d",&d,&m,&y);
	int y1=y/100;
	int y2=y%100;
	int k,l,n;
	for(i=1;i<=25;i++){
		k=4*i;
		if(k>y1){
			l=k-1;
			break;
		}
	}
	n=l-y1;
	c_off=n*2;
	r = (y2+(y2/4))%7;

		y_off= r;

		
	switch(m){
		case 1 : m_off = 0;
		break;
		case 2 : m_off = 3;
		break;
		case 3 : m_off = 3;
		break;
		case 4 : m_off = 6;
		break;
		case 5 : m_off = 1;
		break;
		case 6 : m_off = 4;
		break;
		case 7 : m_off = 6;
		break;
		case 8 : m_off = 2;
		break;
		case 9 : m_off = 5;
		break;
		case 10 : m_off = 0;
		break;
		case 11 : m_off = 3;
		break;
		case 12 : m_off = 5;
		break;
	}
	
	d_off = d%7;
	p = d_off + m_off + y_off + c_off;
	q = p%7;
	switch(q){
		case 0 : printf("Sunday");
		break;
		case 1 : printf("Monday");
		break;
		case 2 : printf("Tuesday");
		break;
		case 3 : printf("Wednesday");
		break;
		case 4 : printf("Thursday");
		break;
		case 5 : printf("Friday");
		break;
		case 6 : printf("Saturday");
		break;
	}
	int z;
printf("\nPress 1 if wanna continue else pree 0 to exit...");
scanf("%d",&z);
if(z==1)
goto l1;
else 
	return 0;
}

