/*
Amazon is hosting a team hackathon.
- Each team will have exactly teamSize developers.
- A developer’s skill level is denoted by skill[i].
- The difference between the maximum and minimum skill levels within a team cannot exceed a threshold, maxDiff.
- Determine the maximum number of teams that can be formed from the contestants.

eg.
skill = [3, 4, 3, 1, 6, 5]
team5ize = 3
maxDiff = 2

At most, 2 teams can be formed: [3, 3, 1] and [4, 6, 5].
*/

int solve(vector<int> skill, int teamSize, int maxDiff) {
	int teams = 0;
	for (int i = 0; j = teamSize - 1; j < n;) {
		if (skill[j] - skill[i] <= maxDiff) {
			teams++;
			i = j + 1;
			j += teamSize;
		} else {
			i++; j++;
		}
	}

	return teams;
}