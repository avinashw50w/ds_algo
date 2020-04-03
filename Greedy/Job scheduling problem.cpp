/* Problem : Given an array of jobs where every job has a deadline and associated profit if the job is finished before the deadline. 
			It is also given that every job takes single unit of time, so the minimum possible deadline for any job is 1. 
			How to maximize total profit if only one job can be scheduled at a time. 
Input: Four Jobs with following deadlines and profits
  JobID    Deadline      Profit
    a        4            20   
    b        1            10
    c        1            40  
    d        1            30
Output: Following is maximum profit sequence of jobs
        c, a   */

struct Job{
   char id;      // Job Id
   int dead;    // Deadline of job
   int profit;  // Profit if job is over before or on deadline
};

bool comparison(Job &a, Job &b) { return (a.profit > b.profit); }
 
// Returns minimum number of platforms required
void printJobScheduling(Job arr[], int n){
    // Sort all jobs according to decreasing order of profit
    sort(arr, arr+n, comparison);
 
    bool slot[n];  // To keep track which job takes which time slot
 
 	fill(slot, slot+n, -1);
    // Iterate through all given jobs
    for (int i = 0; i < n; i++)
    {
       // Find a free slot for this job (Note that we start
       // from the last possible slot)
       for (int j = min(n, arr[i].dead)-1; j >= 0; j--)
       {
          // Free slot found
          if (slot[j] == -1)
          {
             slot[j] = i; // Make this slot occupied by the job whose id is i
             break;
          }
       }
    }
 
    // Print the result
    for (int i=0; i<n; i++)
       if (slot[i] != -1)
         cout << arr[slot[i]].id << " ";
}
 
// Driver program to test methods
int main()
{
    Job arr[5] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27},
                   {'d', 1, 25}, {'e', 3, 15}};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Following is maximum profit sequence of jobs\n";
    printJobScheduling(arr, n);
    return 0;
}

/* Examples:

Input: Four Jobs with following deadlines and profits
  JobID    Deadline      Profit
    a        4            20   
    b        1            10
    c        1            40  
    d        1            30
Output: Following is maximum profit sequence of jobs
        c, a   


Input:  Five Jobs with following deadlines and profits
   JobID     Deadline     Profit
     a         2           100
     b         1           19
     c         2           27
     d         1           25
     e         3           15
Output: Following is maximum profit sequence of jobs
        c, a, e
		
*/
