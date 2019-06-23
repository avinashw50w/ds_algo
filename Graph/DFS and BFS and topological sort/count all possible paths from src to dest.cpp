
int paths = 0;

void count(int src, int dest) {
    if (src == dest) paths++;
    else {
        for (auto v: G[src]) {
            count(v, dest);
        }
    }
}