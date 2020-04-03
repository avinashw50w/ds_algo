/*Given a source string and a destination string write a program to display sequence of strings to travel from source to destination Can you?
Rules for traversing:
1. You can only change one character at a time 
2. Any resulting word has to be a valid word from dictionary
Example: Given source word CAT and destination word DOG , one of the valid sequence would be 
CAT -> COT -> DOT -> DOG
Another valid sequence can be 
CAT -> COT - > COG -> DOG

One character can change at one time and every resulting word has be a valid word from dictionary*/

int main() {
	string source = "CAT";
	string destination = "DOG";
	cout<<source<<"->"
	while(source!=destination){
   		for (int i=0; source[i]!='\0'; i++){
          	if(source[i]!=destination[i]){
                oldcharacter=source[i];
                source[i]=destination[i];
                if(source NOT in "dictionary")
                	source[i]=oldcharacter;
                else{
                    if(source==destination){
                        cout<<source;
                        break;
                    }
                    else
                        cout<<source<<"->";
                                        
                }
            }
   		}
	}
}