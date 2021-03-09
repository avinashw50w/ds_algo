/*Minimum Initial Energy Required To Cross Street
Given an array containing positive and negative numbers. The array represents checkpoints from
one end to other end of street. Positive and negative values represent amount of energy at that
checkpoint. Positive numbers increase the energy and negative numbers decrease. Find the
minimum initial energy required to cross the street such that Energy level never becomes 0 or
less than 0.

Note : The value of minimum initial energy required will be 1 even if we cross street
successfully without loosing energy to less than and equal to 0 at any checkpoint. The 1 is
required for initial check point.*/

int solve(vector<int> a) {
	int enery = 0, required = 0, f = 0;

	for (int e : a) {
		enery += e;

		if (energy <= 0) {
			required += abs(energy) + 1;
			energy = 1;
			f = 1;
		}
	}

	return f ? required : 1;
}