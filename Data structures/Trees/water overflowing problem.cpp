/*Program to find amount of water in a given glass
There are some glasses with equal capacity as 1 litre. The glasses are kept as follows:

    			   1
		         2   3
		      4    5    6
		    7    8    9   10
You can put water to only top glass. If you put more than 1 litre water to 1st glass, water overflows and 
fills equally in both 2nd and 3rd glasses. Glass 5 will get water from both 2nd glass and 3rd glass and so on.
If you have X litre of water and you put that water in top glass, how much water will be contained by jth glass in ith row?

Example. If you will put 2 litre on top.
1st – 1 litre
2nd – 1/2 litre
3rd – 1/2 litre

The approach is similar to Method 2 of the Pascal’s Triangle. If we take a closer look at the problem, the problem boils down to Pascal’s Triangle.

                        1   ---------------- 1
		         	  2   3 ---------------- 2
                   4    5    6  ------------ 3
		        7    8    9   10  --------- 4
Each glass contributes to the two glasses down the glass. Initially, we put all water in first glass. Then we keep 1 litre 
(or less than 1 litre) in it, and move rest of the water to two glasses down to it. We follow the same process for the 
two glasses and all other glasses till ith row. There will be i*(i+1)/2 glasses till ith row.*/

// find water at the jth column of the ith row.
// if X amount of water is poured at the top
int findWater(int i, int j, int X) {
	if(j > i) return -1;

	// there are i*(i+1)/2 glasses till the ith row
	float glass[(i*(i+1))/2];

	memset(glass, 0, sizeof(glass));

	int idx = 0;
	// put all the water into the first glass
	glass[0] = X;

	for(int row = 1; row <= i; ++row) {

		for(int col = 1; col <= row; ++col, ++idx) {

			X = glass[idx];

			glass[idx] = (X >= 1.0) ? 1.0 : X;

			X = (X >= 1.0) ? X-1 : 0.0;

			glass[idx + row] += X/2;
			glass[idx + row + 1] += X/2;
		}
	}
	// i*(i-1)/2 = no of glasses till previous row
	return glass[(i*(i-1))/2 + j-1];
}