/*Design a system that gives us the no of hits in the system in the last 5 minutes.

IDEA:
We are only concerned about hits in the last 5 minutes(300 seconds).
Approach 1:
we can use a queue to store the timestamp(unix) when there was a hit
- keep removing hits from the front of the queue if the timestamp < current_timestamp - 300
- when we want to calculate the hits, we need to iterate over all the queue and count the hits
- Drawbacks: the queue size can increase significantly if the no of hits are more
		we also need to iterate over the queue which is O(N)

Approach 2:
use a fixed sized array 'time' of size 300 to store the timestamps. How ?
module the timestamp with 300, eg, 524 % 300 = 224, then store 524 in the index 224
and increment the counter at index 224.
In case the index x % 300 is already occupied, then just replace it. Because collision
will only occur when 300 seconds have passed.
*/

class HitCounter {
	vector<int> time;
	vector<int> counter;
	int size;
public:
	HitCounter(int N) {
		this->size = N;
		time = vector<int>(N, -1);
		counter = vector<int>(N, 0);
	}

	void hit(int timestamp) {
		int index = timestamp % N;
		if (time[index] != timestamp) {
			time[index] = timestamp;
			counter[index] = 1;
		}
		else
			counter[index]++;
	}

	int hitCount() {
		int count = 0;
		for (int i = 0; i < counter.size(); ++i) {
			count += counter[i];
		}

		return count;
	}
}

void hits