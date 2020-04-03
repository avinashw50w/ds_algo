/*Given enter image description here and enter image description here. You want to count the number of integers in the interval enter 
image description here, coprime with enter image description here.
Algorithm: Go straight to the inverse — calculate the number of not mutually Prime numbers.
Consider all the Prime factors of a number enter image description here; we denote them using enter image description here.
How many numbers are in the interval enter image description here divisible by enter image description here ? They are: ciel(r/pi)
However, if we simply sum these numbers, we get the wrong answer — some numbers will be totaled several times (those that are divided to 
several enter image description here). Therefore it is necessary to use the formula of inclusions-exclusions.
For example, 2^k to iterate over a subset of the set of all p_i's, calculate their product, and to add or subtract in the formula of 
inclusions-exclusions next term.*/

int solve (int n, int r) {
 vector<int> p;
	for (int i=2; i*i<=n; ++i)
		if (n % i == 0) {
 			p.push_back (i);
			while (n % i == 0)
 				n /= i;
		}
	if (n > 1)
 		p.push_back (n);
 
	int sum = 0;
	for (int msk=1; msk<(1<<p.size()); ++msk) {
		int mult = 1, bits = 0;
		for (int i=0; i<(int)p.size(); ++i)
			if (msk & (1<<i)) {
				++bits;
 				mult *= p[i];
			}
 
			int cur = r / mult;
			if (bits % 2 == 1)
 				sum += cur;
			else
 				sum -= cur;
	}
 
	return r - sum;
}