/*Given 3 positives numbers a, b and c. Return the minimum flips required in some bits of a and b to make ( a OR b == c ). (bitwise OR operation).
Flip operation consists of change any single bit 1 to 0 or change the bit 0 to 1 in their binary representation.*/

class Solution {
public:
	int minFlips(int a, int b, int c) {
		int x = 0, y = 0, z = 0;
		int ans = 0;

		for (int i = 0; i < 31; ++i) {
			x = a & (1 << i);
			y = b & (1 << i);
			z = c & (1 << i);

			if (z == 0) {
				if (x and y) ans += 2;
				else if (x or y) ans++;
			}
			else {
				if (!x and !y) ans++;
			}
		}

		return ans;
	}
};