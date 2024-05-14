#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class MaxHeap {
public:
    MaxHeap() : elements(1) {} // Initialize with a dummy element at index 0

    MaxHeap(const std::vector<int>& data) : elements(1) { 
        // TODO
      	for(auto &a : data){
            elements.push_back(a);
        }
        buildHeap();
    }

    void insertValueInHeap(int value) {
      	// TODO
      	elements.push_back(value);
        heapifyUp(elements.size() - 1);
    }

    void extractMax() {
      	// TODO
        if (isEmpty()) {
            return;
        }
        elements[1] = elements.back();
        elements.pop_back();
        heapifyDown(1);
    }
  
  	int peekTopOfHeap() const {
        // TODO
      	if(isEmpty()) return -1;
        return elements[1];
    }
  
  	int sizeOfHeap() const {
        // TODO
      	return elements.size() - 1;
    }

    bool isEmpty() const {
        // TODO
      	return elements.size() <= 1;
    }

    void print() const {
      	// TODO
      	for(int i = 1; i < elements.size(); i++) {
            cout << elements[i] << " ";
        }
        cout << endl;
    }
  
  	// Can add anything you needed

private:
    std::vector<int> elements;

    void buildHeap() {
        int n = sizeOfHeap();
        for(int i = n / 2; i >= 1; i--) {
            heapifyDown(i);
        }
    }

    void heapifyUp(int index) {
        // TODO
      	while(index > 1 && elements[parent(index)] < elements[index]) {
            swap(elements[parent(index)], elements[index]);
            index = parent(index);
        }
    }

    void heapifyDown(int index) {
        // TODO
      	int size = elements.size();
        while (1) {
            int left = leftChild(index);
            int right = rightChild(index);
            int largest = index;

            if (left < size && elements[left] > elements[largest]) {
                largest = left;
            }
            if (right < size && elements[right] > elements[largest]) {
                largest = right;
            }
            if (largest != index) {
                swap(elements[index], elements[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }

  	int parent(int index) const {
        // TODO
      	return index / 2;
    }

    int leftChild(int index) const {
        // TODO
      	return 2 * index;
    }

    int rightChild(int index) const {
        // TODO
      	return 2 * index + 1;
    }

  	// Can add anything you need
  	
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin >> t;
    std::vector<int> data(t);
    for (int i = 0; i < t; ++i){
        int value;
        cin >> value;
        data[i] = value;
    }
    
    MaxHeap maxHeap(data); // build max heap from array data
    
    maxHeap.print();
    
    string s;
    int value;
    cin >> s >> value;
    maxHeap.insertValueInHeap(value); // insertValueInHeap
    
    maxHeap.print();
    
    cin >> s;
    maxHeap.extractMax(); // extractMax
    
    maxHeap.print();

    return 0;
}