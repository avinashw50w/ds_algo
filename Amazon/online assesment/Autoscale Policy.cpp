/*
A scaling computing system checks its average utilization every second while it monitors. 
It implements an autoscale policy to increase or reduce instances depending on the current load as described below. 
Once an action of increasing or reducing the number of instances is performed, the system will stop monitoring 
for 10 seconds. During that time, the number of instances does not change.
- If the average utilization < 25%, then an action is instantiated to reduce the number of instances 
by half if the number of instances is greater than 1. Take the ceiling if the number is not an integer. 
If the number of instances is 1, take no action.
- If 25% s average utilization s 60%, take no action.
- If the average utilization > 60%, then an action is instantiated to double the number of instances if the 
doubled value does not exceed 2* 108. If the number of instances exceeds this limit upon doubling, take no action.

Given an array of integers that represent the average utilization at each second, determine the number of 
instances at the end of the time frame.
*/

int solve(vector<int> util, int instances) {
	for (int i = 0; i < util.size(); ) {
		if (util[i] < 25 and instances > 1) {
			instances = (instances + 1) / 2;
			i += 10;
		} else if (util[i] > 60) {
			instances = min(2 * 10^8, 2 * instances);
			i += 10;
		}
	}

	return instances;
}