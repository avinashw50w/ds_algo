
// Returns cube root of a no n
double cubicRoot(double n)
{
    // Set start and end for binary search
    double start = 0, end = n;
 
    // Set precision
    double e = 0.0000001;
 
    while (true)
    {
        double mid = (start + end)/2;
        double error = fabs(n - mid*mid*mid);
 
        // If error is less than e then mid is
        // our answer so return mid
        if (error <= e)
            return mid;
 
        // If mid*mid*mid is greater than n set
        // end = mid
        if ((mid*mid*mid) > n)
            end = mid;
 
        // If mid*mid*mid is less than n set
        // start = mid
        else
            start = mid;
    }
}
//////////////////////////////////////////////////////////////
// Newton-Raphson's method

double cubicRoot(double n)
{
	const double e = 0.0000001;

	double res = 1.0;
	while(fabs(n - res*res*res) > epsilon)
	{
		res = (res*2.0 + n/(res*res))/3.0;
	}
	return res;
}
