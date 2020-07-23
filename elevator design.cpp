enum direction = {UP, DOWN};

class Elevator {
    bool moving;
    direction dir;
    int floors;
    int current_floor;
    vector<int> floor_request; // floor_request[i] = j represents ith floor was requested at time j
    set<pair<int, int>> requests; // first: time of request, second: floor no
public:
    Elevator(int floors) {
        moving = false;
        dir = UP;
        this->floors = floors;
        current_floor = 1;
        floor_request.resize(floors + 2, 0);
        requests.clear();
    }

    void listen() {
        int floor_no, time;
        while (cin >> floor_no >> time) {
            floor_request[floor_no] = time;
            requests.insert({time, floor_no});
        }
    }

    void process() {
        while (true) {
            while (!requests.size()) {
                moving = false;
            };

            if (!moving) {
                moving = true;
                int requested_floor = *(requests.begin()).second;
                dir = current_floor <= requested_floor ? UP : DOWN;
            }
            else {
                if (dir == UP) {
                    for (int i = current_floor + 1; i <= this->floors; ++i) {
                        if (floor_request[i]) {
                            gotoFloor(i);
                        }
                    }
                    moving = false;
                } else {
                    for (int i = current_floor - 1; i >= 1; --i) {
                        if (floor_request[i]) {
                            gotoFloor(i);
                        }
                    }
                    moving = false;
                }
            }
        }
    }

    void gotoFloor(int floor) {
        sleep(500);
        current_floor = floor;
        requests.erase(requests.find({floor_request[floor], floor}));
        floor_request[floor] = 0;
    }

};

int main() {
    Elevator elevator = new Elevator();
    elevator.listen();
}
