#include <iostream>

using namespace std;

class LinkedList;

class ListNode {
private:
    int data;
    ListNode *next;
public:
    ListNode() : data(0), next(nullptr) {}
    ListNode(int a) : data(a), next(nullptr) {}

    friend class LinkedList;
};

class LinkedList {
public:
    LinkedList() : first(nullptr) {}
    void PrintList();
    void Push_back(int x);
    void Interleave(LinkedList& list2);

private:
    ListNode* first;
};

void LinkedList::PrintList() {
    if (first == nullptr) {
        cout << "Linked list is empty" << endl;
        return;
    }

    ListNode *current = first;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void LinkedList::Push_back(int x) {
    //todo
    ListNode* tmp = first;
    if(!tmp){
        first = new ListNode(x);
    }
    else{
        while(tmp -> next){
            tmp = tmp -> next;
        }
        tmp -> next = new ListNode(x);
    }
}

void LinkedList::Interleave(LinkedList& list2) {
    //todo
    ListNode *tmp1 = first, *tmp2 = list2.first, *lst = tmp1;
    while(tmp2){
        if(tmp1 && tmp2){
            ListNode *tmp = new ListNode(tmp2 -> data);
            tmp -> next = tmp1 -> next;
            tmp1 -> next = tmp;
            tmp1 = tmp -> next;
            tmp2 = tmp2 -> next;
            lst = tmp;
        }
        else if(tmp2){
            if(!first){
                first = new ListNode(tmp2 -> data);
                lst = first;
                tmp2 = tmp2 -> next;
            }
            else{
                ListNode *tmp = new ListNode(tmp2 -> data);
                lst -> next = tmp;
                lst = tmp;
                tmp2 = tmp2 -> next;
            }
        }
    }
}

int main() {
    LinkedList list1;
    LinkedList list2;
    int count1, count2, num;

    cin >> count1;
    for (int i = 0; i < count1; i++) {
        cin >> num;
        list1.Push_back(num);
    }

    cin >> count2;
    for (int i = 0; i < count2; i++) {
        cin >> num;
        list2.Push_back(num);
    }

    list1.Interleave(list2);
    list1.PrintList();

    return 0;
}