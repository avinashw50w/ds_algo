/*Amazon Technical Academy (ATA) provides in-demand, technical training to current Amazon employees looking 
to broaden their skill sets. ATA has admitted a group of n prospective trainees with varying skill levels. 
To better accommodate the trainees, ATA has decided to create classes tailored to the skill levels. 
A placement examination will return a skill level that will be used to group the trainees into classes, 
where levels[i] represents the skill level of trainee i. All trainees within a class must have a skill level 
within maxSpread(ie the diff bw any two trainees within a class should not be greater than maxSpread), 
a specified range of one another. Determine the minimum number of classes that must be formed.
*/

int solve(vector<int> levels, int maxSpread) {
	int n = levels.size();
	if (n == 0) {
		return 0;
	}

	sort(levels.begin(), levels.end());
	int min_level_in_class = levels[0], classes = 1;
	
	for (int i = 1; i < n; ++i) {
		if (a[i] - min_level_in_class > maxSpread) {
			classes++;
			min_level_in_class = a[i];
		}
	}

	return classes;
}