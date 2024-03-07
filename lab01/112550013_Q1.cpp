#include <iostream>
#include <string>

class Student {
    private:
        std::string id;
        std::string name;
        int score;
    public:
        Student() {}
        void setId(std::string newId) {
            id = newId;
        }
        void setName(std::string newName) {
            name = newName;
        }
        void setScore(int newScore) {
            score = newScore;
        }
        std::string getId() {
            return id;
        }
        std::string getName() {
            return name;
        }
        int getScore() {
            return score;
        }
};

class Teacher {
    private:
        std::string id;
        std::string name;
        Student* favoriteStudent;
    public:
        Teacher() {}
        void setId(std::string newId) {
            id = newId;
        }
        void setName(std::string newName) {
            name = newName;
        }
        void setFavoriteStudent(Student* newFavoriteStudent) {
            favoriteStudent = newFavoriteStudent;
        }
        std::string getId() {
            return id;
        }
        std::string getName() {
            return name;
        }
        std::string getFavoriteStudentId() {
            return favoriteStudent -> getId();
        }
        std::string getFavoriteStudentName() {
            return favoriteStudent -> getName();
        }
        int getFavoriteStudentScore() {
            return favoriteStudent -> getScore();
        }
        void setFavoriteStudentScore(int newScore) {
            favoriteStudent -> setScore(newScore);
        }
};

int main(void) {
    int sc, tc, mc;
    std::cin >> sc >> tc >> mc;

    Student s[105];
    Teacher t[105];
    
    for(int i = 0; i < sc; i ++){
        int scr;
        std::string id, nm;
        std::cin >> id >> nm >> scr;
        s[i].setId(id);
        s[i].setName(nm);
        s[i].setScore(scr);
    }

    for(int i = 0; i < tc; i ++){
        std::string id, nm, sm;
        std::cin >> id >> nm >> sm;
        t[i].setId(id);
        t[i].setName(nm);
        for(int j = 0; j < sc; j ++){
            if(s[j].getId() == sm){
                t[i].setFavoriteStudent(&s[j]);
                break;
            }
        }
    }

    for(int i = 0; i < mc; i ++){
        std::string id;
        int scc;
        std::cin >> id >> scc;

        for(int j = 0; j < tc; j ++){
            if(t[j].getId() == id){
                t[j].setFavoriteStudentScore(scc);
            }
        }
    }

    for(int j = 0; j < tc; j ++){
        std::string stn = t[j].getFavoriteStudentName(), stid = t[j].getFavoriteStudentId();
        int stsc = t[j].getFavoriteStudentScore();
        std::cout << "[" << t[j].getId() << "]" <<  t[j].getName() << "'s favorite student is [" << stid << "]" << stn << ".\n";
        std::cout << "The student's score is " << stsc << ".\n";
    }
}