#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::string;
using std::vector;

class Item
{
private:
    string name;

public:
    // TODO: Add constructors or functions
    Item(){
        name = "";
    }
      Item(string name){
        this->name = name;
    }
    string getName() const{
        return name;
    }
    friend ostream &operator<<(ostream &os, const Item &item){
        os << item.name;
        return os;
    }
    friend istream &operator>>(istream &is, Item &item){
        is >> item.name;
        return is;
    }
};

class Magic
{
private:
    string name;
    int manaCost;

public:
    // TODO: Add constructors or functions
    Magic(){
        name = "";
        manaCost = 0;
    }
    Magic(string name, int manaCost){
        this->name = name;
        this->manaCost = manaCost;
    }
      string getName() const{
        return name;
    }
    int getManaCost() const{
        return manaCost;
    }
    friend ostream &operator<<(ostream &os, const Magic &magic){
        os << magic.name << " " << magic.manaCost;
        return os;
    }
    friend istream &operator>>(istream &is, Magic &magic){
        is >> magic.name >> magic.manaCost;
        return is;
    }
};

class Player
{

private:
    string name;
    int strength;
    int mana;
    vector<Item> items;
    Magic magic;

public:
    // TODO: Add constructors or functions
    Player(){
        name = "";
        strength = 0;
        mana = 0;
    }
    string getName() const{
        return name;
    }
    int getStrength() const{
        return strength;
    }
    int getMana() const{
        return mana;
    }
    vector<Item> getItems() const{
        return items;
    }
    Magic getMagic() const{
        return magic;
    }
    Player operator++(){
        strength++;
        return *this;
    }
    Player operator++(int){
        Player temp = *this;
        mana++;
        return temp;
    }
    Player operator+(Item item){
        items.push_back(item);
        return *this;
    }
    Player operator+(Magic magic){
        if(this->mana >= magic.getManaCost()){
            if(this->magic.getName() == "" || (this->magic.getName() != "" && this->magic.getManaCost() <= magic.getManaCost())){
                this->magic = magic;
            }
        }
        return *this;
    }
    friend ostream &operator<<(ostream &os, const Player &player){
        os << player.name << "\nStrength: " << player.strength << "\nMana: " << player.mana << endl;
        int tmp = (int)player.items.size() > player.strength ? player.strength : (int)player.items.size();
        os << "Items(" << tmp << "):\n";
        if(player.items.size() > 0){
            for (int i = (int)player.items.size() - tmp; i < (int)player.items.size(); i++){
            os << player.items[i] << "\n";
            }
        }
        else{
            os << "No item\n";
        }
        if(player.magic.getName() != ""){
            os << "Magic:\n" << player.magic;
        }
        else{
            os << "Magic:\nNo Magic\n";
        }
        
        return os;
    }
    friend istream &operator>>(istream &is, Player &player){
        is >> player.name >> player.strength >> player.mana;
        return is;
    }
};

// TODO: Add constructors or functions


int main()
{
    Player player;
    cin >> player;

    int strengthTrainingCount, manaTrainingCount;
    cin >> strengthTrainingCount >> manaTrainingCount;
    for (int i = 0; i < strengthTrainingCount; i++)
    {
        ++player;
    }
    for (int i = 0; i < manaTrainingCount; i++)
    {
        player++;
    }

    int getItemTimes, getMagicTimes;
    cin >> getItemTimes >> getMagicTimes;
    for (int i = 0; i < getItemTimes; i++)
    {
        Item item;
        cin >> item;
        player = player + item;
    }
    for (int i = 0; i < getMagicTimes; i++)
    {
        Magic magic;
        cin >> magic;
        player = player + magic;
    }

    cout << player;

    return 0;
}