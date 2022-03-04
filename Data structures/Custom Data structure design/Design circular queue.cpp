// Design a circular queue

class CQueue {
    int front;
    int rear;
    int size;
    vector<int> a;

    CQueue(int size) {
        this->front = 0;
        this->rear = 0;
        this->size = size;
        a = vector<int>(size, -1);
    }

    bool enqueue(int value) {
        if (isFull()) return false;
        if (isEmpty()) {
            front = rear = 0;
            a[rear] = value;
            size++;
            return true;
        }

        rear = (rear + 1) % a.size();
        a[rear] = value;
        size++;
        return true;
    }

    bool dequeue() {
        if (isEmpty()) return false;
        a[front] = -1;
        front = (front + 1) % a.size();
        size--;
        return true;
    }

    int front() {
        return a[front];
    }

    int rear() {
        return a[rear];
    }

    bool isFull() {
        return size == (int)a.size();
    }

    bool isEmpty() {
        return size == 0;
    }
}