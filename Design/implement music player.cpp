/*Implement a music player where there are n songs and needs to be played in a randomized order.
A played song must not be repeated until all the unrepeated songs have been played.

Naive approach : used played boolean array to keep track of the played songs
Optimised : use the idea of fisher-yates shuffling algo,
take a pointer to the right (index n-1) => then pick a random song in the index range [0...n-1]
=> play that song => swap the played song with the right => decrement right index
*/

class Player {
	vector<int> songs;

	Player(vector<int> a) {
		for (int x : a) songs.push_back(x);
	}

	void play_list() {
		for (int i = n - 1; i > 0; --i) {
			int j = rand() % (i + 1);
			play(j);
			swap(a[i], a[j]);
		}
		play(a[0]);
	}
}


