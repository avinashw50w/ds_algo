#include <iostream>
using namespace std;

/* Problem : given a set of activities with their starting and finishing times.
Find the maximum set of activities that can be done if
	only one activity can be done at a time.  */

/*just check the no of activities which dont overlap with its adjacent activities*/

vector<int> A;   // stores the order of activities
int N;          // no of activities

struct timing {
	int idx;
	float start;
	float finish;
};

bool comp(const timing& a, const timing& b) { return a.finish < b.finsih; }
vector<timing> schedule;

void func(vector<timing> V) {
	// sort the activities in increasing order of their finish times
	// because we want the maximum no of activities
	// so need to consider activities which ended earlier
	sort(V, V + N, comp);

	A.push_back(V[0].idx);  //  put the activity with the least finish time into the final list
	int j = 0;
	for (int i = 1; i < N; ++i) {
		if (V[i].start >= V[j].finish) {
			A.push_back(V[i].idx);
			j = i;
		}
	}
}


