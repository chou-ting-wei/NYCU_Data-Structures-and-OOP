#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Shape {
private:
    string color;
public:
    //TODO hint : you can define virtual functions here
    void setc(string s){
        color = s;
    }
    string getc(){
        return color;
    }
    virtual double geta(){
        return 0;
    }
    virtual void out(){
        return;
    }
};

class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    //TODO
    void setwh(double w, double h){
        width = w;
        height = h;
    }
    double geta(){
        return width * height;
    }
    void out(){
        cout << "Name: Rectangle, Color: " << getc() << ", Area: " << geta() << endl;
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    //TODO
    void setr(double r){
        radius = r;
    }
    double geta(){
        return acos(-1) * radius * radius;
    }
    void out(){
        cout << "Name: Circle, Color: " << getc() << ", Area: " << geta() << endl;
    }
};


class Triangle : public Shape {
private:
    double base;
    double height;
public:
    //TODO
    void setbh(double b, double h){
        base = b;
        height = h;
    }
    double geta(){
        return base * height / 2;
    }
    void out(){
        cout << "Name: Triangle, Color: " << getc() << ", Area: " << geta() << endl;
    }
};

class ShapeManager {
private:
    vector<Shape*> shapes;
public:
    //TODO hint : you can define functions here to know the information of each shape and calculate the total area
    void adds(Shape* s){
        shapes.emplace_back(s);
    }
    void listShapes(){
        for(auto a : shapes){
            a->out();
        }
    }
    double calculateTotalArea(){
        double ret = 0;
        for(auto a : shapes){
            ret += a->geta();
        }
        return ret;
    }
};

int main() {
    
    ShapeManager manager;

    string color;
    
    double width, height;
    //TODO
    cout << "All shapes:" << endl;
    cin >> color >> width >> height;
    Rectangle* r = new Rectangle();
    r -> setwh(width, height);
    r -> setc(color);
    manager.adds(r);

    double radius;
    //TODO
    cin >> color >> radius;
    Circle* c = new Circle();
    c -> setr(radius);
    c -> setc(color);
    manager.adds(c);

    double base, triHeight;
    //TODO
    cin >> color >> base >> triHeight;
    Triangle* t = new Triangle;
    t -> setbh(base, triHeight);
    t -> setc(color);
    manager.adds(t);
    
    manager.listShapes();
    cout << "Total area: " << manager.calculateTotalArea() << endl;

    return 0;
}