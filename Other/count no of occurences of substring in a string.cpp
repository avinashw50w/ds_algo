#include<stdio.h>
#include<string.h>
int countSubstring(const char *str,const char *sub){
	 int c = 0 ,l = strlen(sub);
 
        while (*str != '\0') {
                if (strncmp(str++, sub, l)) continue;
               // if (!overlap) str += l - 1;
                c++;
        }
        return c;
}


int main(){
	char str[100],sub[100];
	scanf("%s",str);
	scanf("%s",sub);
	int ans = countSubstring2(str,sub);
	printf("\n%d",ans);
	return 0;
	
}
