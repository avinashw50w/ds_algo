
int strstr(string s, string x)
{
    int i, j, flag = 0;
     for(i=0; i<s.size(); ++i) {
         for(j=0; j<x.size(); ++j) {
             if(s[i+j] != x[j]){
                 break;
             }
         }
         if(j == x.size()) return i;
     }
     return -1;
}
///////////////////////////////////////////////////////////////
/* Driver Function */ 
char* StrStr(char *str, char *substr)
{
	  while (*str) 
	  {
		    char *Begin = str;
		    char *pattern = substr;
		    
		    // If first character of sub string match, check for whole string
		    while (*str && *pattern && *str == *pattern) 
			{
			      str++;
			      pattern++;
		    }
		    // If complete sub string match, return starting address 
		    if (!*pattern)
		    	  return Begin;
		    	  
		    str = Begin + 1;	// Increament main string 
	  }
	  return NULL;
}
