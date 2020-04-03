
// lambdas are anonymous functions //

auto f = [](auto a, auto b) { 
	return a < b;
}

bool b = f(2, 5);  // returns true;

bool b1 = f(5, 2.4); // return false;
