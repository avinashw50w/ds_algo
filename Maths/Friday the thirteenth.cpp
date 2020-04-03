// find the freq of the 13th date falling on sun, mon, tue, ... , sat from the year 1990 to 1990+N-1, where N is given

#include <iostream>
using namespace std;
#define REP(i,a,b) for (int i=a;i<b;++i)

int year[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int lyear[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int N, day = 13, y = 1990;

bool isLeap(int y) 
{
	return ((y%4 == 0 and y%100 != 0) or y%400 == 0);	
}
int main() {
	
	int N;
	
	int sum[7] = {};

	cin >> N;
	
	REP (i, 0, N)
	{
		REP (month, 0, 12) 
		{
			sum[day%7]++;
			
			if (isLeap(y))
				day += lyear[month];
			else
				day += year[month];
		}	
		y++;
	}
		
	REP (i, 0, 7) cout << sum[i] << " ";
}
