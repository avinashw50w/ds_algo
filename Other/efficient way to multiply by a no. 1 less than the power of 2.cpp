# include<iostream>
using namespace std;
 //  let's take 7 which is(8-1)
int main(){
	int n;
	cout<<"\nEnter a no to be multiplied by 7 :";  // 7= 8-1     n*8 - n = n*7
	cin>>n;
	cout<<"\n"<<(n<<3)-n;
	
	cout<<"\nEnter a no to be multiplied by 17 :";   //17 = 16+1       n*16 + n = n*17
	cin>>n;
	cout<<"\n"<<(n<<4)+n;
}

// time and space complexity is O(n)
