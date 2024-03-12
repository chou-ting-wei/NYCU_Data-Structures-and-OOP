#include <iostream>
#include <string>
#include <vector>

class Person {
    public:
        std::string getName(){
            return name;
        }
        void setName(std::string n){
            name = n;
        }
    private:
        std::string name;
};

class Staff : public Person {
    public:
        void setSupervisor(Staff* s){
            supervisor = s;
        }
        Staff* getSupervisor(){
            return supervisor;
        }
    private:
        Staff* supervisor;
};

class Doctor : public Staff {
    public:
        int chkSup(Doctor* d){
            if(d != getSupervisor()) return 0;
            return 1;
        }
};

class Nurse : public Staff {
    public:
        int chkSup(Doctor* d){
            if(d != getSupervisor()) return 0;
            return 1;
        }
};

class Task {
    public:
        void setName(std::string n){
            name = n;
        }
        std::string getName(){
            return name;
        }
        void setNurse(Nurse* n){
            nurse = n;
        }
        Nurse* getNurse(){
            return nurse;
        }
    private:
        std::string name;
        Nurse* nurse;
};

class Patient : public Person {
    public:
        void addTask(Task* t){
            tasks.emplace_back(t);
        }
        std::vector<Task*> getTask(){
            return tasks;
        }
        void setDoctor(Doctor* d){
            doctor = d;
        }
        Doctor* getDoctor(){
            return doctor;
        }
    private:
        Doctor* doctor;
        std::vector<Task*> tasks;
};

Doctor d[105];
Nurse n[105];
Patient p[105];
Task t[105];

int main(void) {
	int dc, nc, pc;
    std::cin >> dc >> nc >> pc;

    std::string s;
    for(int i = 0; i < dc; i ++){
        std::cin >> s;
        d[i].setName(s);
    }
    for(int i = 0; i < nc; i ++){
        std::cin >> s;
        n[i].setName(s);
    }
    for(int i = 0; i < pc; i ++){
        std::cin >> s;
        p[i].setName(s);
    }

    int tc;
    std::cin >> tc;
    for(int i = 0; i < tc; i ++){
        int k;
        std::cin >> k;
        std::cin.get();
        getline(std::cin, s);
        t[i].setName(s);
        p[k].addTask(&t[i]);
    }

    for(int i = 0; i < nc; i ++){
        int nid, did;
        std::cin >> nid >> did;
        n[nid].setSupervisor(&d[did]);
    }
    for(int i = 0; i < dc; i ++){
        int did, sid;
        std::cin >> did >> sid;
        if(sid != -1){
            d[did].setSupervisor(&d[sid]);
        }
        else{
            d[did].setSupervisor(nullptr);
        }
    }

    int rac, tac;
    std::cin >> rac >> tac;
    for(int i = 0; i < rac; i ++){
        int adid, did, pid;
        std::cin >> adid >> did >> pid;
        if(d[did].chkSup(&d[adid])){
            p[pid].setDoctor(&d[did]);
        }
    }
    for(int i = 0; i < tac; i ++){
        int tid, adid, nid;
        std::cin >> tid >> adid >> nid;
        if(n[nid].chkSup(&d[adid])){
            t[tid].setNurse(&n[nid]);
        }
    }

    for(int i = 0; i < pc; i ++){
        std::cout << "name: " << p[i].getName() << std::endl;
        std::cout << "doctor: " << p[i].getDoctor()->getName() << std::endl;
        std::cout << "tasks: " << std::endl;
        std::vector<Task*> tmp = p[i].getTask();
        for(auto a : tmp){
            std::cout << a->getName() << " " << a->getNurse()->getName() << std::endl;
        }
    }
    
	return 0;
}