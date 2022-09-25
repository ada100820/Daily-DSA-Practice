/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

class MyCircularQueue {
public:
    int *arr;
    int front;
    int rear;
    int size;
    MyCircularQueue(int k) {
        arr = new int[k];
        front = -1;
        rear = -1;
        size = k;
    }
    bool enQueue(int value) {
        if(isFull()) return false;
        if(isEmpty()) front = 0;
        rear = (rear + 1) % size;
        arr[rear] = value;
        return true;
    }
    bool deQueue() {
        if(isEmpty()) return false;
        if(front == rear) front = rear = -1;
        else front = (front + 1) % size;
        return true;
    }
    int Front() {
        if(isEmpty()) return -1;
        return arr[front];
    }
    int Rear() {
        if(isEmpty()) return -1;
        return arr[rear];
    }
    bool isEmpty() {
        return front == -1;
    }
    bool isFull() {
        return ((rear + 1) % size) == front;
    }
};


/*
Intuition:
--> We can use a circular array to implement the queue.
--> We can use the modulo operator to wrap around the array.
--> We can use the front and rear pointers to keep track of the front and rear of the queue.
--> We can use the size variable to keep track of the size of the queue.

Approach:
--> In enQueue, we check if the queue is full. If it is, we return false else we check if the queue is empty. If it is,
    we set the front to 0. We increment the rear pointer and set the value at the rear pointer to the value & finally we
    return true.
--> In deQueue, we check if the queue is empty. If it is, we return false else we check if the front and rear are equal.
--> If they are, we set the front and rear to -1 else we increment the front pointer and finally we return true.
--> Time Complexity: O(1)
--> Space Complexity: O(n), where n is the size of the queue
*/
