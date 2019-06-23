/*Given number of cities 3 ≤ n ≤ 50, available time 1 ≤ t ≤ 1000, and
two n × n matrices (one gives a travel time and another gives tolls between two cities), choose a
route from the first city 0 in such a way that one has to pay as little money for tolls as possible to
arrive at the last city n − 1 within a certain time t. Output two information: the total tolls that
is actually used and the actual traveling time.*/

const int oo = 1e9;
const int MAXN = 1000;

// initialize with -1
pair<int,int> dp[MAXN][MAXN]; // dp[i][j].first will store the min toll price and dp[i][j].second will store the time taken to move from city i to city j.

pair<int,int> solve(int currCity, int timeLeft) {
	if(timeLeft < 0) // timeout
		return make_pair(oo, oo); 

	if(currCity == N-1) // reached the last city
		return make_pair(0, 0);

	if(dp[currCity][timeLeft].first != -1) 
		return dp[currCity][timeLeft];

	pair<int,int> ret = make_pair(oo, oo);

	for(int neighbor = 0; neighbor < n; neighbor++) { // iterate through all the neighbors
		if(neighbor != currCity) {
			pair<int,int> nextCity = solve(neighbor, timeLeft - travelTime[currCity][neighbor]);

			if(nextCity.first + toll[currCity][neighbor] < ret.first) {
				ret.first = nextCity.first + toll[currCity][neighbor];
				ret.second = nextCity.second + travelTime[currCity][neighbor];
			}
		}
	}

	return dp[currCity][timeLeft] = ret;
}