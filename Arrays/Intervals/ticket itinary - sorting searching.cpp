/* You are given a set of airline tickets with the source and destination airports.
 * Write a method that takes a set of tickets and reconstructs the itinerary.
 *
 * EXAMPLE
 *
 * Input:
 * [MUC, LHR], [CDG, MUC], [SFO, SJC], [LHR, SFO]
 *
 * Output:
 * [CDG, MUC] -> [MUC, LHR] -> [LHR, SFO] -> [SFO, SJC]
 *
 * Source: Careercup (Google interview)
 */

struct ticket {
	string src, dest;
};

vector<ticket> tickets;

void init() {
	int N; cin>> N;

	while(N--) {
		cin >> src >> dest;
		tickets.push_back({src, dest});
	}
}

vector<ticket> getItinerary() {
	vector<ticket> res;
	map<string, ticket> sources;
	set<string> destinations;

	for(auto t: tickets) {
		sources[t.src] = t;
		destinations.insert(t.dest);
	}

	string src;

	for(auto t: sources) {
		if(destinations.count(t.first) == 0) {
			src = t.first;
			break;
		}
	}

	while(sources.find(src) != sources.end()) {
		res.push_back(sources[src]);
		src = sources[src].dest;
	}

	return res;
}

int main() {

	init();

	vector<ticket> itinerary = getItinerary();
}

/////////////////////////////////////////////////////