#include<iostream>
#include<string>
#include<map>

using namespace std;

class Department;
class Patient;
class GroupDoctor;
class Doctor;

class Doctor{
private:
    string name;
    string address;
    GroupDoctor *group;
public:
    void setName(string name){this->name = name;}
    string getName(){return name;}
    void setAddress(string address){this->address = address;}
    string getAddress(){return address;}
    void setGroup(GroupDoctor *group){
        this->group = group;
    }
    GroupDoctor *getGroup(){
        return group;
    }

    Doctor(string name, string address){
        setName(name);
        setAddress(address);
    }
    void display(){
        cout << "Name: " << getName() << endl;
        cout << "Address: " << getAddress() << endl;
    }
};

class GroupDoctor{
private:
    string ID;
    Doctor *leader;
    map<string, Doctor*> doctors;
    map<string, Patient*> patients;
public:
    void setID(string ID){this->ID = ID;}
    string getID(){return ID;}
    void setLeader(Doctor *leader){
        this->leader = leader;
        leader->setGroup(this);
    }

    GroupDoctor(string ID, Doctor *leader ){
        setID(ID);
        setLeader(leader);
    }
    void showLeader(){
        leader->display();
    }
    void showDoctors(){
        for(auto doctor : doctors){
            doctor.second->display();
        }
    }
    void showPatients();

    void addDoctor(Doctor *doctor){
        doctors[doctor->getName()] = doctor;
        doctor->setGroup(this);
    }
    void addPatient(Patient *patient);
};

class Patient{
private:
    string name;
    string bdate;
    string room;
    Department *department;
    GroupDoctor *group;
public:
    void setName(string name){this->name = name;}
    string getName(){return name;}
    void setBdate(string bdate){this->bdate = bdate;}
    string getBdate(){return bdate;}
    void setRoom(string room){this->room = room;}
    string getRoom(){return room;}

    void setDepartment(Department *department){
        this->department = department;
    }
    Department *getDepartment(){
        return department;
    }
    void setGroup(GroupDoctor *group){
        this->group = group;
    }
    GroupDoctor *getGroup(){
        return group;
    }

    Patient(string name, string bdate){
        setName(name);
        setBdate(bdate);
    }
    void display(){
        cout << "Name: " << getName() << endl;
        cout << "Bdate: " << getBdate() << endl;
        cout << "Room: " << getRoom() << endl;
    }
    void showConsultant(){
        cout << "Consultant: " << endl; 
        group->showLeader(); 
        cout << "Group Doctors: " << group->getID() << endl;
    }
};

class Department{
private:
    string name;
    map <string, Patient*> patients;
public:
    void setName(string name){this->name = name;}
    string getName(){return name;}

    Department(string name){
        setName(name);
    }
    void showPatients(){
        for(auto patient : patients){
            patient.second->display();
        }
    }

    void addPatient(Patient *patient){
        patients[patient->getName()] = patient;
        patient->setDepartment(this);
    }  
};

class Hospital{
public:
    void addPatient(Patient *patient, Department *department, string room){
        patient->setRoom(room);
        department->addPatient(patient);
    }
    void setGroupForPatient(Patient *patient, GroupDoctor *group){
        group->addPatient(patient);
    }
};

void GroupDoctor::showPatients(){
    for(auto patient : patients){
        patient.second->display();
    }
}

void GroupDoctor::addPatient(Patient *patient){
    patients[patient->getName()] = patient;
    patient->setGroup(this);
}

int main(){
    Hospital hospital;
    Doctor bs1("BS1", "Address1");
    Doctor bs2("BS2", "Address2");
    GroupDoctor nhom1("Nhom1",&bs1);
    nhom1.addDoctor(&bs2);
    // nhom1.showDoctors();

    Patient p1("P1", "Bdate1");
    Patient p2("P2", "Bdate2");
    Department khoa("Khoa nhi");
    hospital.addPatient(&p1, &khoa, "Room1");
    hospital.addPatient(&p2, &khoa, "Room2");
    hospital.setGroupForPatient(&p1, &nhom1);
    p1.showConsultant();
    // khoa.showPatients();


    return 0;
}