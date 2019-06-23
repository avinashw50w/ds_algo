/* Problem : Given a value V, if we want to make change for V Rs, and we have infinite supply of each of the denominations in Indian currency, 
i.e., we have infinite supply of { 1, 2, 5, 10, 20, 50, 100, 500, 1000} valued coins/notes, what is the minimum number of coins and/or notes
 needed to make the change?  */
 
int deno[] = {1,2,5,10,20,50,100,500,1000};
int n = sizeof deno/sizeof deno[0];
vector<int> res;

// to find the min set of denominations required  //
void func(int money){
	for(int i=n-1; i>=0; --i){
		while(money >= deno[i]){
			money -= deno[i];
			ans.push_back(deno[i]);
		}
	}
}

// if you want to calculate the min number of denominations //

int func1(int money){
	int ans = 0;
	for(int i=n-1; i>=0; --i){
		if(money >= deno[i]){
			ans += money/deno[i];
			money %= deno[i];
		}
	}
	return ans;
}
