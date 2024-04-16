#include <iostream>
#include <vector>

using namespace std;

class ListNode {
public:
    int data;
    ListNode *next;
    ListNode(int x) : data(x), next(NULL) {}
};

class LinkedList {
private:
    ListNode* head;

public:
    LinkedList() : head(NULL) {}

    void push_back(int data) {
        //TODO
        ListNode* tmp = head;
        if(!tmp){
            head = new ListNode(data);
        }
        else{
            while(tmp -> next){
                tmp = tmp -> next;
            }
            tmp -> next = new ListNode(data);
        }
    }

    bool isPalindrome() {
        //TODO
        vector<int> v;
        ListNode* tmp = head;
        while(tmp){
            v.emplace_back(tmp -> data);
            tmp = tmp -> next;
        }

        int flg = 1;
        for(int i = 0; i < int(v.size()) / 2; i ++){
            if(v[i] != v[int(v.size()) - 1 - i]){
                flg = 0;
                break;
            }
        }
        return flg;
    }

    ListNode* reverse(ListNode* node) {
        //TODO
        return NULL;
    }


    ~LinkedList() {
        ListNode *current = head;
        while (current != NULL) {
            ListNode *next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    LinkedList lst;
    int length, num;

    cin >> length;

    for (int i = 0; i < length; i++) {
        cin >> num;
        lst.push_back(num);
    }

    bool result = lst.isPalindrome();
    cout << (result ? "Yes" : "No") << endl;

    return 0;
}