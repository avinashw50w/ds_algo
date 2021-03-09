/*You are given an array tasks where tasks[i] = [actuali, minimumi]:

actuali is the actual amount of energy you spend to finish the ith task.
minimumi is the minimum amount of energy you require to begin the ith task.
For example, if the task is [10, 12] and your current energy is 11, you cannot start this task. However, if your current energy is 13, you can complete this task, and your energy will be 3 after finishing it.

You can finish the tasks in any order you like.

Return the minimum initial amount of energy you will need to finish all the tasks.

IDEA: sort the tasks acc to the energy left after doing the tasks in descending order
use greedy approach and find the minimum energy required to finish all the tasks
*/

int minimumEffort(vector<vector<int>>& tasks) {
    sort(tasks.begin(), tasks.end(), [](auto & a, auto & b) {
        return a[1] - a[0] > b[1] - b[0];
    });

    int curr_energy = 0;
    int ans = 0;

    for (auto e : tasks) {
        int actual = e[0];
        int mini = e[1];
        if (curr_energy < mini) {
            int required = mini - curr_energy;
            ans += required;
            curr_energy += required;
        }
        curr_energy -= actual;
    }

    return ans;
}