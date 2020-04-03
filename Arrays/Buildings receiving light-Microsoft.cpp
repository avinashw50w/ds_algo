/*Given are the heights of certain Buildings which lie adjacent to each other. 
Sunlight starts falling from left side of the buildings. 
If there is a building of certain Height, all the buildings to the right side of it having lesser heights 
cannot see the sun . The task is to find the total number of such buildings that receive sunlight.
Input:
First Line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case 
consists of two lines. First line of each test case contains an integer N denoting the number of buildings. Second line 
contains N space separated integers H1, H2,...HN denoting heights of buildings. */

int main() {
	int t; cin>>t;
	int n;
	while(t--) {
	    cin>>n;
	    int a, cnt = 0, maxx = INT_MIN;
	    for(int i = 0; i < n; ++i){
	        cin>>a;
	        if(a >= maxx) maxx = a, cnt++;
	    }
	    cout << cnt << endl;
	}
	return 0;
}