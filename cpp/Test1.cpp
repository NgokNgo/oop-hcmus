#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Instructor;

class Room{
private:
    int roomNumber;
    int capacity;
    Instructor* instructor;
public:
    Room(int roomNumber, int capacity){
        this->roomNumber = roomNumber;
        this->capacity = capacity;
        instructor = nullptr;
    }
    void setRoomNumber(int roomNumber){this->roomNumber = roomNumber;}
    int getRoomNumber(){return this->roomNumber;}
    void setCapacity(int capacity){this->capacity = capacity;}
    int getCapacity(){return this->capacity;}
    Instructor* getInstructor(){return this->instructor;}

    void attachInstructor(Instructor* instructor){
        this->instructor = instructor;
    }
    void detachInstructor(Instructor* instructor){
        this->instructor = nullptr;
    }
};

class Instructor{
private:
    string name;
    vector<Room*> room;
public:
    Instructor(string name){
        this->name = name;
    }
    void setName(string name){this->name = name;}
    string getName(){return this->name;}
    void display(){
        cout << "Instructor: " << getName() << endl;
        cout << "Room using: "<<endl;
        for(int i = 0; i < room.size(); i++){
            cout << room[i]->getRoomNumber() << endl;
        }
    }

    void bookRoom(Room* room){
        if(room->getInstructor() == nullptr){
            this->room.push_back(room);
            room->attachInstructor(this);
            cout << "Booked ! "<<endl;
        }
    }
    void returnRoom(Room* room){
        for(int i = 0; i < this->room.size(); i++){
            if(this->room[i] == room){
                this->room.erase(this->room.begin() + i);
            }
        }
        room->detachInstructor(this);
        cout << "Returned ! "<<endl;
    }
};



int main(){
    Instructor instructor1("John");
    Instructor instructor2("Jane");
    Room room1(1, 30);
    Room room2(2, 40);
    Room room3(3, 50);

    instructor1.bookRoom(&room1);
    instructor1.bookRoom(&room2);
    instructor2.bookRoom(&room3);

    cout << "gv1 tra phong 1 cho gv2"<<endl;
    instructor1.returnRoom(&room1);
    instructor2.bookRoom(&room1);

    instructor1.display();
    instructor2.display();
}