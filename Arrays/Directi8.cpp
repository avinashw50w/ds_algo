/*We r given 3 arrays  of equal size, a number k, we have to  find 3 number one from each array which add up to k.
Give the best solution. I first gave n3 and n2 solution.*/

// sort all the arrays : O(nlogn)

void solve(int a1[], int a2[], int a3[], int N, int K)
{

	sort(a1, a1 + N);
	sort(a2, a2 + N);
	sort(a3, a3 + N);

	REP(i, 0, N)
	{
		int l = 0, r = N - 1;

		while (l < N and r >= 0)
		{
			if (a1[i] + a2[l] + a3[r] == K)
			{
				cout << a1[i] << " " << a2[l] << " " << a3[r] << endl;
				break;
			}

			else if (a1[i] + a2[l] + a3[r] < K)
			{
				if (a2[l] < a3[r]) l++;
				else r--;
			}

			else
			{
				if (a2[l] < a3[r]) r--;
				else l++;
			}
		}
	}
}