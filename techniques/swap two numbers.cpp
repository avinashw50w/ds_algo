
void swap(int& a,int& b){
	a^=b^=a^=b;
}
int main(){
	int a=4, b=5;
	swap(a,b);
	cout<<a<<" "<<b;
	return 0;
}
