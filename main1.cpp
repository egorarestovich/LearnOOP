#include <iostream>

class Fruit {
protected:
    static int count;
    int id;
    std::string color;
    int weight;
    static int countoffruits;
public:
    Fruit() : id(count), weight(0), color("") {
        count++;
    }
    int getId() {
        return id;
    }
    virtual void getInfo() {
        std::cout << id << '\n';
    }
    void MinusCountOfFrukts() {
        countoffruits--;
    }
    void printcount() {
        std::cout << countoffruits << '\n';
    }
};

class Apple : public Fruit {
public:
    void getInfo() override {
        std::cout << id << " " << color << '\n';
    }
    Apple() {
        countoffruits++;
    }
};

class Human {
public:
    void BringFrukt(Fruit& frukt) {
        frukt.MinusCountOfFrukts();
    }
};

int Fruit::count = 0;
int Fruit::countoffruits = 1;

int main() {
    Apple apple;
    Fruit frukt;
    Human human;
    frukt.printcount();
    human.BringFrukt(apple);
    human.BringFrukt(frukt);
    apple.printcount();
}