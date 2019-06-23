/*There are N students in a class. Some of them are friends, while some are not. Their friendship is transitive in nature. 
For example, if A is a direct friend of B, and B is a direct friend of C, then A is an indirect friend of C. 
And we defined a friend circle is a group of students who are direct or indirect friends.
Given a N*N matrix M representing the friend relationship between students in the class. If M[i][j] = 1, 
then the ith and jth students are directfriends with each other, otherwise not. And you have to output the 
total number of friend circles among all the students.
Example 1:
Input: 
[[1,1,0],
 [1,1,0],
 [0,0,1]]
Output: 2
Explanation:The 0th and 1st students are direct friends, so they are in a friend circle. 
The 2nd student himself is in a friend circle. So return 2.*/

 public int findCircleNum(int[][] M) {
        int size=M.length;
        if(size==0) return 0;
        UnionFind uf = new UnionFind(size);
        for(int i=0; i<size;i++){
            for(int j=0; j<size; j++){
                if(i==j) continue;
                if(M[i][j]==1){
                    uf.union(i,j);
                }
            }
        }
        return uf.cycles();
    }
    
    public class UnionFind{
        public int[] arr;
        public UnionFind(int size){
            arr = new int[size];
            for(int i=0;i<size; i++){
                arr[i]=i;
            }
        }
        
        public int root(int i){
            while(arr[i] !=i){
                arr[i] =arr[arr[i]];
                i=arr[i];
            }
            return i;
        }
        
        public void union(int i, int j){
            int r1 =root(i);
            int r2 =root(j);
            if(r1 == r2) return;
            arr[r1] =r2;
        }
        public int cycles(){
            int cnt=0;
            for(int i=0;i<arr.length ;i++){
                if(arr[i] == i){
                    cnt++;
                }
            }
            return cnt;
        }
    }

/*X. DFS
https://discuss.leetcode.com/topic/85031/neat-dfs-java-solution
BTW, visited use boolean[] better.*/
    public void dfs(int[][] M, int[] visited, int i) {
        for (int j = 0; j < M.length; j++) {
            if (M[i][j] == 1 && visited[j] == 0) {
                visited[j] = 1;
                dfs(M, visited, j);
            }
        }
    }
    public int findCircleNum(int[][] M) {
        int[] visited = new int[M.length];
        int count = 0;
        for (int i = 0; i < M.length; i++) {
            if (visited[i] == 0) {
                dfs(M, visited, i);
                count++;
            }
        }
        return count;
    }
    
X. BFS
https://discuss.leetcode.com/topic/85021/java-bfs-equivalent-to-finding-connected-components-in-a-graph
public int findCircleNum(int[][] M) {
    int count = 0;
    for (int i=0; i<M.length; i++)
        if (M[i][i] == 1) { count++; BFS(i, M); }
    return count;
}

public void BFS(int student, int[][] M) {
    Queue<Integer> queue = new LinkedList<>();
    queue.add(student);
    while (queue.size() > 0) {
        int queueSize = queue.size();
        for (int i=0;i<queueSize;i++) {
            int j = queue.poll();
            M[j][j] = 2; // marks as visited
            for (int k=0;k<M[0].length;k++) 
                if (M[j][k] == 1 && M[k][k] == 1) queue.add(k);
        }
    }
}
http://bookshadow.com/weblog/2017/04/03/leetcode-friend-circles/
Floyd-Warshall 求传递闭包
Floyd-Warshall算法参阅：
https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm
    def findCircleNum(self, M):
        """
        :type M: List[List[int]]
        :rtype: int
        """
        N = len(M)
        for k in range(N):
            for i in range(N):
                for j in range(N):
                    M[i][j] = M[i][j] or (M[i][k] and M[k][j])
        cnt = 0
        vset = set()
        for x in range(N):
            if x not in vset:
                cnt += 1
                for y in range(x + 1, N):
                    if M[x][y]: vset.add(y)
        return cnt