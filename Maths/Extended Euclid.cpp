// store x, y, and g as global variables

void extendedEuclid(int a, int b) {
	if (b == 0) { 
		g = a;
		x = 1; 
		y = 0;  
	}
	else{
		extendedEuclid(b, a % b);
	
		int tmp = x;
		x = y;
		y = tmp - (a/b)*y;
	}	
}
///////////////////////////////////////////////////////////////
int GCDext(int a, int b, int &x, int &y) {
    int g = a;
    x = 1;
    y = 0;
    if (b != 0) {
        g = GCDext(b, a % b, y, x);
        y -= (a / b) * x;
    }
    return g;
}
//////////////////////////////////////////////////////////////
/* Extended Euclid: Solving Linear Diophantine Equation
Motivating problem: Suppose a housewife buys apples and oranges at a total cost of 8.39 SGD. If
an apple is 25 cents and an orange is 18 cents, how many of each type of fruit does she buys?
This problem can be modeled as a linear equation with two variables: 25x + 18y = 839. Since
we know that both x and y must be integers, this linear equation is called the Linear Diophantine
Equation. We can solve Linear Diophantine Equation with two variables even if we only have one
equation! This is different from System of Linear Equations discussed later in Section 5.5.5. The
solution for the Linear Diophantine Equation is as follow [20].
Let a and b be integers with d = gcd(a, b). The equation ax + by = c has no integral solutions
if d | c is not true. But if d | c, then there are infinitely many integral solutions. The first solution
(x0, y0) can be found using the Extended Euclid algorithm shown below (also see [4], Chapter 31),
and the rest can be derived from x = x0 + (b/d)n, y = y0 - (a/d)n, where n is an integer.  
*/

tuple<int,int,int> extEuclid(int a,int b){
	int x, y, g;
	if(b == 0) return make_tuple(1,0,a);
	tie(x,y,g) = extEuclid(b, a%b);
	return make_tuple(y, x - (a/b)*y, g);
}
