#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	int t;
	scanf("%d",&t);
	char w[10][21],stem[21],sub[21];
	int i,j,k,n,len,minlen,minindx,missing,found;
	while(t--){
		scanf("%d",&n);
		minlen=21;
		for(i=0;i<n;i++){
			scanf("%s",w[i]);
			len=strlen(w[i]);
			if(len<minlen){        //  find the word with the smallest length and store its length and index,let that word be w_min
				minlen = len;
				minindx = i;
			}
		}
		found=0;
		for(i=minlen;i>0;i--){            //   no of charachters of w_min that should be copied to sub   
			for(j=0;j<=minlen-i;j++){
				strncpy(sub,w[minindx]+j,i);         // copy i no of chars of w_min starting from index j,to sub
				sub[i]='\0';
				missing=0;
				for(k=0;k<n;k++){                   //  checking if sub is present in all other words
					if(strstr(w[k],sub)==NULL){
						missing=1;                  // if not present in any word ,then break the loop and find another sub
						break;
					}
				}
					if(!missing){                  // if sub is present in all the words
						if(!found){                 //  if stem word is not yet found then copy sub to stem
							strncpy(stem,sub,i);
							stem[i]='\0';
						}
						else{                  // if a stem word is already found then 
							if(strcmp(sub,stem)<0){        // check if sub is lexicographically smaller than the stem word.Note that len of both sub and stem is same here.
								strncpy(stem,sub,i);           //  if sub is lexically smaller than copy sub to stem   
								stem[i]='\0';
							}
						}
						found=1;                        //  now the  stem word has been found 
					}
			}
			if(found) break;                   // if the stem word is found ,then no need to check other stem words of length less than the curent stem word
		}
		puts(stem);
	}
	return 0;
}
