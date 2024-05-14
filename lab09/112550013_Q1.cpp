#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

class MyQueue {
private:
    stack<int> stack1;
    stack<int> stack2;
    void transfer() {
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }

public:
    MyQueue() {
        
    }
    
    void enQueue(int x) {
        // TODO
      	stack1.push(x);
    }
    
    int deQueue() {
        // TODO
        if (stack2.empty()) {
            transfer();
        }
        int top = stack2.top();
        stack2.pop();
        return top;
    }
    
    int peek() {
        // TODO
        if (stack2.empty()) {
            transfer();
        }
        return stack2.top();
    }
    
    bool isEmpty() {
        // TODO
      	return stack1.empty() && stack2.empty();
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    MyQueue queue;
    string command;
    while(cin >> command){
        int value;
        if (command == "enqueue") {
            // TODO
          	cin >> value;
            queue.enQueue(value);
            cout << "Enqueued " << value << endl;
        } else if (command == "dequeue") {
            // TODO
            if(queue.isEmpty()) cout << "Queue is empty" << endl;
          	else cout << "Dequeued " << queue.deQueue() << endl;
        } else if (command == "peek") {
            // TODO
            if(queue.isEmpty()) cout << "Queue is empty" << endl;
          	else cout << "Front element: " << queue.peek() << endl;
        } else if (command == "empty") {
            // TODO
          	if(queue.isEmpty()){
              cout << "Queue is empty" << endl;
            }else{
              cout << "Queue is not empty" << endl;
            }
        } else {
            cout << "Invalid command" << endl;
        }
    }
    return 0;
}