/* https://cybergeeksquad.co/2023/03/robot-bounded-in-circle-amazon-oa.html
On an infinite plane, a robot initially stands at (0, 0) and faces north. The robot can receive one of 
three instructions:
- “G”: go straight 1 unit;
- “L”: turn 90 degrees to the left;
- “R”: turn 90 degrees to the right.

The robot performs the instructions given in order, and repeats them forever.

Return true if and only if there exists a circle in the plane such that the robot never leaves the circle.

eg. Input:  instructions = “GGLLGG”
Output: true
*/

class Solution {
public:
    int dx[4]{0, 0, -1, 1};
    int dy[4]{1, -1, 0, 0};
    
    int turnLeft(int d) {
        if (d == 0) return 2;
        if (d == 2) return 1;
        if (d == 1) return 3;
        return 0;
    }
    
    int turnRight(int d) {
        if (d == 0) return 3;
        if (d == 3) return 1;
        if (d == 1) return 2;
        return 0;
    }
    
    bool isRobotBounded(string instructions) {
         int x, y, direct;
         x = y = direct = 0;
        instructions += instructions + instructions + instructions;
         for(auto c : instructions)
             if (c == 'L') 
                 direct = turnLeft(direct);
             else if (c == 'R') 
                 direct = turnRight(direct);
             else {
                 x += dx[direct];
                 y += dy[direct];
             }
          if (x == 0 && y == 0) return true;
          return false;
    }
};

// another
class Solution {
    public bool isRobotBounded(string instructions) {
        // init position
        int pos[2] = {0, 0};
        
        // directions north, east, south, west 
        int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        int face = 0;
       
        for(char c: instructions) {
            if(c == 'L') {
                face = face == 0 ? 3 : face - 1;
            }
            else if(c == 'R') {
                face = face == 3 ? 0 : face + 1;
            }
            else {
                pos[0] = pos[0] + dirs[face][0];
                pos[1] = pos[1] + dirs[face][1];
            }
        }
        return (face != 0 || (pos[0] == 0 && pos[1] == 0));
    }
}