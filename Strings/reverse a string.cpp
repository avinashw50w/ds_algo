void reverseArray(string s,int start,int end){
	if(start>=end) return;
	swap(s[start],s[end]);
	reverseArray(s,start+1,end-1);
}
