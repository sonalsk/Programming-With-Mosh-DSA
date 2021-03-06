#include <iostream>
#include <cassert>

using namespace std;

class myQueue {
    private:
        int capacity;
        int numElements;
        int front;
        int back;
        int * queueArr;
    
    public:
        myQueue(int);
        bool isEmpty();
        int getFront();
        int getBack();
        void enqueue(int);
        int dequeue();
        int getSize();
        void showqueue();
        void print();
};

myQueue::myQueue(int size) {
    capacity = size;
    queueArr = new int[size];
    assert(queueArr != NULL);
    numElements = 0;
    front = 0;
    back = -1;
}

bool myQueue::isEmpty() {
    return (numElements == 0);
}

int myQueue::getFront() {
    if (isEmpty()) {
        return -1;
    }
    else {
        return queueArr[front];
    }
}

int myQueue::getBack() {
    if (isEmpty()) {
        return -1;
    }
    else {
        return queueArr[back];
    }
}

void myQueue::enqueue(int value) {
    if (numElements == capacity) {
        return;
    }
    back = (back + 1) % capacity;
    queueArr[back] = value;
    
    numElements++;
}

int myQueue::dequeue() {
    if (isEmpty()) {
        return -1;
    }
    
    int tmp = queueArr[front];
    queueArr[front] = 0;
    front = (front + 1) % capacity;

    numElements--;
    return tmp;
}

int myQueue::getSize() {
    return numElements;
}

void myQueue::showqueue() {
    cout << "Real Queue: ";
    int i = front;
    int count = 0;
    while (count != numElements) {
        cout << queueArr[i % capacity] << " ";
        i++;
        count++;
    }
    cout << endl;
}

void myQueue::print() {
    cout << "Array View: ";
    for (int i = 0; i <capacity; i++) {
        cout << queueArr[i] << " ";
    }
    cout << endl;
}

int main() {
    myQueue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(50);

    q.showqueue();
    q.print();
    cout << "Front: " << q.getFront() << " Back: " << q.getBack() << endl << endl;

    q.dequeue();
    q.dequeue();
    q.dequeue();

    q.showqueue();
    q.print();
    cout << "Front: " << q.getFront() << " Back: " << q.getBack() << endl << endl;

    q.enqueue(70);
    q.enqueue(80);
    q.enqueue(90);
    
    q.dequeue();

    q.showqueue();
    q.print();
    cout << "Front: " << q.getFront() << " Back: " << q.getBack() << endl << endl;
    
    q.enqueue(900);
    
    q.showqueue();
    q.print();
    cout << "Front: " << q.getFront() << " Back: " << q.getBack() << endl << endl;

    // q.showqueue();
    // q.print();


    cout << q.getBack() << endl;
}
