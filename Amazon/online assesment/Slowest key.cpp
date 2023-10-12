/* https://cybergeeksquad.co/2023/03/slowest-key-amazon-oa-2022.html
A newly designed keypad was tested, where a tester pressed a sequence of n keys, one at a time.
You are given a string keysPressed of length n, where keysPressed[i] was the ith key pressed in the testing sequence, 
and a sorted list releaseTimes, where releaseTimes[i] was the time the ith key was released. Both arrays are 0-indexed.
The 0th  key was pressed at the time 0, and every subsequent key was pressed at the exact time the previous key was released.
The tester wants to know the key of the keypress that had the longest duration. The ith keypress had a duration
 of releaseTimes[i] – releaseTimes[i – 1], and the 0 keypress had a duration of releaseTimes[0].

 Return the key of the keypress that had the longest duration. If there are multiple such keypresses, 
 return the lexicographically largest key of the keypresses.

 input:  releaseTimes = [9,29,49,50], keysPressed = “cbcd”
 output:  “c”
*/

char solve(vector<int> releaseTime, string keysPressed) {
	int min_duration = 0;
	set<char, greater<char>> st;
	for (int i = 1; i < releaseTime.size(); ++i) {
		int duration = releaseTime[i] - releaseTime[i-1];
		if (duration > min_duration) {
			duration = min_duration;
			st.insert(keysPressed[i]);
		}
	}

	return *st.begin();
}