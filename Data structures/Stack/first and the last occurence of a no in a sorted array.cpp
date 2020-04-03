//for finding the first occurence of a no in a sorted array
int Bsearch(int A[],int l,int r,int x){
	int res=-1;
	while(l<=r){
		mid = (l+r)/2;
		if(A[mid]==x) res=mid , r=mid-1;     //  for the last occurence set l=mid+1;
		else if(x<A[mid]) r=mid-1;
		else l=mid+1;
	}
	return res;
}
