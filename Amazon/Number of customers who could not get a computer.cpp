/*Write a function “runCustomerSimulation” that takes following two inputs
a) An integer ‘n’: total number of computers in a cafe and a string:
b) A sequence of uppercase letters ‘seq’: Letters in the sequence occur in pairs. The first
occurrence indicates the arrival of a customer; the second indicates the departure of that same
customer.

A customer will be serviced if there is an unoccupied computer. No letter will occur more than
two times.
Customers who leave without using a computer always depart before customers who are currently
using the computers. There are at most 20 computers per cafe.

For each set of input the function should output a number telling how many customers, if any
walked away without using a computer. Return 0 if all the customers were able to use a computer.

runCustomerSimulation (2, “ABBAJJKZKZ”) should return 0*/

int solve(int n, string s) {
	int n = s.length();
	vector<int> seen(26, 0);
	int ans = 0, occupied = 0;

	for (int i = 0; i < n; ++i) {
		char c = s[i] - 'A';
		// if customer enters
		if (seen[c] == 0) {
			seen[c] = 1;
			// assign a computer if available
			if (occupied < n) {
				occupied++;
				// customer c is assigned a computer
				seen[c] = 2;
			}
			else
				++ans;
		}
		else {
			// customer was assigned a computer so release the computer
			if (seen[c] == 2)
				occupied--;
			seen[c] = 0;
		}
	}

	return ans;
}