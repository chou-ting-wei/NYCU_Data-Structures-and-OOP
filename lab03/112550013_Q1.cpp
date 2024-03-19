#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Position {
private:
    string name;
    int salary;
public:
    //TODO
};

class Boss : public Position {
public:
    //TODO
};


class Manager : public Position {
public:
    //TODO
};


class TeamLeader : public Position {
public:
    //TODO
};


class Employee : public Position {
public:
    //TODO
};


double totalSalary(const vector<Position*>& positions) {
    //TODO
    return 0;
}

int main() {
    vector<Position*> positions;
    string name;
    int salary;
    
    //TODO
    salary = 0;
    for(int i = 0; i <= 3; i ++){
        string s;
        cin >> s;
        int k;
        cin >> k;
        if(i == 0){
            cout << "Boss - " << s << ", Salary: " << k << endl;
        }
        else if(i == 1){
            cout << "Manager - " << s << ", Salary: " << k << endl;
        }
        else if(i == 2){
            cout << "Team Leader - " << s << ", Salary: " << k << endl;
        }
        else{
            cout << "Employee - " << s << ", Salary: " << k << endl;
        }
        salary += k;
    }
    cout << "Total company salary: " << salary << endl;
    
    return 0;
}