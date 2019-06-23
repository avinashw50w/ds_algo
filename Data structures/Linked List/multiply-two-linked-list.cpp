
/*The method multiplies 
two  linked lists l1 and l2
and returns their product*/

/*You are required to complete this method*/
long long  multiplyTwoLists (node* l1, node* l2)
{
  	const int mod = 1000000007;
  	long long num1 = 0, num2 = 0;
  	
  	node *curr = l1;
  	while(curr) {
      	num1 = (num1*10 + curr->data)%mod;
      	curr = curr->next;
  	}
  
  	curr = l2;
  	while(curr) {
      	num2 = (num2*10 + curr->data)%mod;
      	curr = curr->next;
  	}
  
  	return (num1 * num2)%mod;
}