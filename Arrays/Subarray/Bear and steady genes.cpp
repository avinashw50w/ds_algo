
/*A gene is a string which consists chars A, C, T and G. The gene is balanced if freq of each
char is n/4 where n is the length of the gene. Find the length of minimum subarray which
should be replaced such that the gene becomes balanced.
eg. gene = ACTGAAAG, then the subarray [5..6] (AA) is replaced with CT or TC. So ans = 2
*/
int n;
map<char, int> f;

bool ok() {
    for (auto p : f)
        if (p.second > n / 4) return false;
    return true;
}

// Complete the steadyGene function below.
int steadyGene(string gene) {
    n = gene.length();
    for (char c : gene) f[c]++;
    if (ok()) return 0;
    int j = 0, ans = n;
    for (int i = 0; i < n; ++i) {
        while (j < n and !ok()) {
            f[gene[j]]--;
            j++;
        }

        if (ok()) ans = min(ans, j - i);

        f[gene[i]]++;
    }

    return ans;
}