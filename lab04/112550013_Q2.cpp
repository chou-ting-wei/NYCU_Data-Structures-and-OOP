#include <cmath>
#include <vector>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

class Object
{
protected:
    string name;

public:
    // TODO: Add constructors or functions
    void setName(string name) { this->name = name; }
    string getName() { return name; }
    virtual ~Object() = default;
    virtual int getVal() { return 0; }
};

class Monster : public Object
{
private:
    int attackValue;

public:
    // TODO: Add constructors or functions
    void setAttackValue(int attackValue) { this->attackValue = attackValue; }
    int getAttackValue() { return attackValue; }
    int getVal() { return attackValue; }
};

class Food : public Object
{
private:
    int healValue;

public:
    // TODO: Add constructors or functions
    void setHealValue(int healValue) { this->healValue = healValue; }
    int getHealValue() { return healValue; }
    int getVal() { return healValue; }
};

class Player
{
private:
    string name;
    int health;

public:
    // TODO: Add constructors or functions
    void setName(string name) { this->name = name; }
    string getName() { return name; }
    void setHealth(int health) { this->health = health; }
    int getHealth() { return health; }
    void attack(int atk) { health -= atk; }
    void heal(int heal) { health += heal; }
};

class Room
{
private:
    Object *object;
    char tag;
      // std::shared_ptr<Object> object;

public:
    // TODO: Add constructors or functions
    void setObject(Object *object) { this->object = object; }
    Object *getObject() { return object; }
    void setTag(char tag) { this->tag = tag; }
    char getTag() { return tag; }
};

// TODO: Add constructors or functions
vector<Room> rooms;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    // TODO: Read input, create rooms and create player
    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        Room room;
        char c;
        cin >> c;
        if(c == 'm'){
            string s;
            int k;
            cin >> s >> k;
            Monster *monster = new Monster();
            monster->setName(s);
            monster->setAttackValue(k);
            room.setObject(monster);
            room.setTag('m');
        }
        else if(c == 'f'){
            string s;
            int k;
            cin >> s >> k;
            Food *food = new Food();
            food->setName(s);
            food->setHealValue(k);
            room.setObject(food);
            room.setTag('f');
        }
        else{
            room.setObject(nullptr);
            room.setTag('e');
        }
        rooms.push_back(room);
    }
    
    // TODO: Encounter objects in rooms
    Player player;
    string s;
    int k;
    cin >> s >> k;
    player.setName(s);
    player.setHealth(k);

    int l = rooms.size();
    for(int i = 0; i < l; i++){
        cout << player.getName() << "'s health: " << player.getHealth() << endl;
        if(player.getHealth() <= 0){
            cout << "Game Over" << endl;
            return 0;
        }

        if(rooms[i].getTag() == 'm'){
            cout << "Fight against " << rooms[i].getObject()->getName() << endl;
            player.attack(rooms[i].getObject()->getVal());
        }
        else if(rooms[i].getTag() == 'f'){
            cout << "Eat " << rooms[i].getObject()->getName() << endl;
            player.heal(rooms[i].getObject()->getVal());
        }
        else{
            cout << "Walk" << endl;
        }
    }

    cout << player.getName() << "'s health: " << player.getHealth() << endl;
    cout << "Win Win" << endl;

    return 0;
}