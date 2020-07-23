// C++ implementation
vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    vector<int> result;
    int T, B, L, R, dir, m, n;
    m = A.size();
    n = A[0].size();
    T = 0; B = m - 1; L = 0; R = n - 1; dir = 0;
    while (T <= B && L <= R) {
        if (dir == 0) {
            for (int i = L; i <= R; i++)
                result.push_back(A[T][i]);
            T++;
        }
        else if (dir == 1) {
            for (int i = T; i <= B; i++)
                result.push_back(A[i][R]);
            R--;
        }
        else if (dir == 2) {
            for (int i = R; i >= L; i--)
                result.push_back(A[B][i]);
            B--;
        }
        else if (dir == 3) {
            for (int i = B; i >= T; i--)
                result.push_back(A[i][L]);
            L++;
        }
        dir = (dir + 1) % 4;
    }

    // DO STUFF HERE AND POPULATE result
    return result;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}



//python implementation

class Solution:
# @param A : tuple of list of integers
# @return a list of integers
    def spiralOrder(self, A):
        m = len(A)
            n = len(A[0])
                T = 0
                    B = m - 1
                        L = 0
                            R = n - 1
                                direction = 0
                                            ret = []
                                                    while T <= B and L <= R:
                                                    if (direction == 0):
                                                            for i in range(L, R + 1) :
                                                                ret.append(A[T][i])
                                                                T += 1
                                                                        direction = 1
                                                                                elif direction == 1 :
                                                                                for i in range(T, B + 1) :
                                                                                    ret.append(A[i][R])
                                                                                    R -= 1
                                                                                            direction = 2
                                                                                                    elif direction == 2 :
                                                                                                    for i in range(R, L - 1, -1) :
                                                                                                        ret.append(A[B][i])
                                                                                                        B -= 1
                                                                                                                direction = 3
                                                                                                                        else:
                                                                                                                            for i in range(B, T - 1, -1) :
                                                                                                                                ret.append(A[i][L])
                                                                                                                                L += 1
                                                                                                                                        direction = 0
                                                                                                                                                return ret
