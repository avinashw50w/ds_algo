/*You are given a set of n types of rectangular 3-D boxes, where the i^th box has height h(i), width w(i) and depth d(i)
(all real numbers). You want to create a stack of boxes which is as tall as possible, but you can only stack a box on
top of another box if the dimensions of the 2-D base of the lower box are each strictly larger than those of the 2-D base
of the higher box. Of course, you can rotate a box so that any side functions as its base. It is also allowable to use multiple
instances of the same type of box.

Following are the key points to note in the problem statement:
1) A box can be placed on top of another box only if both width and depth of the upper placed box are smaller
than width and depth of the lower box respectively.
2) We can rotate boxes. For example, if there is a box with dimensions {1x2x3} where 1 is height, 2×3 is base,
then there can be three possibilities, {1x2x3}, {2x1x3} and {3x1x2}.
3) We can use multiple instances of boxes. What it means is, we can have two different rotations of a box as part of our
maximum height stack.

Following is the solution based on DP solution of LIS problem.

1) Generate all 3 rotations of all boxes. The size of rotation array becomes 3 times the size of original array.
For simplicity, we consider depth as always smaller than or equal to width.

2) Sort the above generated 3n boxes in decreasing order of base area.

3) After sorting the boxes, the problem is same as LIS with following optimal substructure property.
dp(i) = Maximum possible Stack Height with box i at top of stack
dp(i) = { Max ( dp(j) ) + height(i) } where j < i and width(j) > width(i) and depth(j) > depth(i).
If there is no such j then dp(i) = height(i)

4) To get overall maximum height, we return max(dp(i)) where 0 < i < n 

NOTE that any rotation of a box will not be taken again, cuz we are taking boxes having strictly
greater length and width than the prev box
all combination of length and width of a box after rotation:
l w | h
h w | l
l h | w
if we pick any two boxes, say l w and h w, one of the dimension is matching, so it is not strictly increasing,
and that's why we can take atmost one rotation of a box.
*/
struct Box {
	int h, w, l;
};

bool comp(const Box& box1, const Box& box2) { return (box1.l * box1.w) > (box2.l * box2.w); }

int  boxStacking(Box a[], int n) {

	Box box[3 * n];
	int idx = 0;
	// store the 3 rotations of each box //
	for (int i = 0; i < n; ++i) {
		box[idx++] = a[i];

		box[idx].h = a[i].l;
		box[idx].l = max(a[i].h, a[i].w);
		box[idx].w = min(a[i].h, a[i].w);
		idx++;

		box[idx].h = a[i].w;
		box[idx].l = max(a[i].h, a[i].l);
		box[idx].w = min(a[i].h, a[i].l);
		idx++;
	}

	n = 3 * n;

	sort(box, box + n, comp); // descending order in base area

	/* dp[i] –> Maximum possible Stack Height with box i on top */
	int dp[n];
	for (int i = 0; i < n; ++i) dp[i] = box[i].h;

	// similar approach as in LIS problem
	for (int i = 1; i < n; ++i)
		for (int j = 0; j < i; ++j)
			// here we are taking box whose dimensions are strictly larger than the previous
			// box in terms of both its length and width, because if the previous box's
			// length of width is same as the curr box then it means it is the same box
			// rotated in some manner
			if ( box[i].l < box[j].l
			        and
			        box[i].w < box[j].w
			        and
			        dp[j] + box[i].h > dp[i]
			   )

			{	dp[i] = dp[j] + box[i].h;   }


	return *max_element(dp, dp + n);
}

