#include <iostream>

class CircularQueue {
public:
    CircularQueue(int size) {
        this->size = size + 1;
        front = 0;
        rear = 0;
        arr = new int[size];
    }

    void enQueue(int data) {
        if(isFull()){
            std::cout << "Queue is full" << std::endl;
        }
        else{
            arr[rear] = data;
            rear = (rear + 1) % size;
        }
    }

    void deQueue() {
        if(isEmpty()){
            std::cout << "Queue is empty" << std::endl;
        }
        else{
            front = (front + 1) % size;
        }
    }

    int peek() {
        if(isEmpty()){
            std::cout << "Queue is empty" << std::endl;
            return -1;
        }
        else{
            return arr[front];
        }
    }

    bool isEmpty() {
        return front == rear;
    }

    bool isFull() {
        return (rear + 1) % size == front;
    }

    void expand(int newSize) {
        int ns = newSize+1;
        if(ns <= size){
            std::cout << "Can only expand the size" << std::endl;
            return;
        }
        int *newArr = new int[ns];
        for(int i = 0; i < size; i++){
            newArr[i] = arr[(front + i) % size];
        }
        front = 0;
        rear = size - 1;
        size = ns;
        delete[] arr;
        arr = newArr;
    }

private:
    int *arr;
    int front, rear, size;
};

int main(void) {
	CircularQueue q(5);
	q.enQueue(1);
	q.enQueue(2);
	q.enQueue(3);
	q.enQueue(4);
	q.enQueue(5);
	q.enQueue(6);
	q.expand(6);
	q.enQueue(6);
	q.deQueue();
	std::cout << q.peek() << std::endl;
	q.deQueue();
	std::cout << q.peek() << std::endl;
	q.enQueue(10);
	std::cout << q.peek() << std::endl;
	q.deQueue();
	q.deQueue();
	q.deQueue();
	q.deQueue();
	std::cout << q.peek() << std::endl;
	q.deQueue();
	std::cout << q.peek() << std::endl;
	q.deQueue();
}