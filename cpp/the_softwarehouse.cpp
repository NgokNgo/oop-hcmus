// THE SOFTWAREHOUSE
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class Employee {
private:
  string number;
  double salary;
  string name;
public:
  void setNumber(string number){ this->number = number; }
  string getNumber(){ return number; }
  void setSalary(int salary){ this->salary = salary; }
  double getSalary(){ return salary; }
  void setName(string name){ this->name = name; }
  string getName(){ return name; }

  Employee(string number, double salary, string name){
    setNumber(number);
    setSalary(salary);
    setName(name);
  }

  virtual void display() = 0;
};

class Programmer : public Employee {
private:
  string language;
public:
  void setLanguage(string language){ this->language = language; }
  string getLanguage(){ return this->language; }

  Programmer(string number, double salary, string name, string language) : Employee(number, salary, name){
    setLanguage(language);
  }

  void display(){
    cout << "Programmer info: " << endl;
    cout << "Number: " << getNumber() << endl;
    cout << "Salary: " << getSalary() << endl;
    cout << "Name: " << getName() << endl;
    cout << "Language: " << getLanguage() << endl;
    cout << endl;
  }
};

class Adminstrator : public Employee {
private:
    string department;
public:
    string getDepartment() {return this->department;}
    void setDepartment(string department) {this->department = department; }

    Adminstrator(string number, double salary, string name,string department) : Employee(number, salary, name) {
      setDepartment(department);
    }
    void display() {
      cout << "Administrator info: " << endl;
      cout << "Number: " << getNumber() << endl;
      cout << "Salary: " << getSalary() << endl;
      cout << "Name: " << getName() << endl;
      cout << "Department: " << getDepartment() << endl;
      cout << endl;
    }
};

class ProjectLeader : public Programmer {
private:
  unordered_map<string,Programmer*> team;
public:
  ProjectLeader(string number, double salary, string name, string language) : Programmer(number, salary, name, language){}

  void display(){
    cout << "---Leader info: " << endl;
    Programmer::display();
    cout << " --- Member in Team: "<<endl;
    for(auto pro : team){
      pro.second->display() ;
    }
    cout << "---end \n\n";
  }

  void addProgrammer(Programmer *programmer) {
    this->team[programmer->getNumber()] = programmer;
  }
};

class SoftwareHouse{
private:
  string name;
  unordered_map<string,Employee*> staffs;
public:
  void setName(string name){this->name = name;}
  string getName(){return this->name;}

  SoftwareHouse(string name){
    setName(name);
  }

  void display(){
    cout << "Name: " << getName() << endl;
  }
  void displayStaff(){
    cout << "Staffs:" << endl;
    for(auto p : staffs){
      p.second->display();
    }
  }

  void addEmployee(Employee *e) {
    this->staffs[e->getNumber()] = e;
  }
};

int main()
{
  Programmer p1("1", 455, "ronaldo", "C++");
  Programmer p2("2", 678, "messi", "python");
  ProjectLeader lead("00", 678, "messi","java");
  lead.addProgrammer(&p1);
  lead.addProgrammer(&p2);
  // lead.display();
  Adminstrator ad1("111", 8000, "Kale", "HR");
  Adminstrator ad2("112", 9000, "Charlie", "Business Analytics");
  Adminstrator ad3("113", 7500, "Ayaya", "F&B");
  // ad3.display();

  SoftwareHouse ss("man city");
  ss.addEmployee(&lead);
  ss.addEmployee(&ad1);
  ss.addEmployee(&p2);
  ss.displayStaff();
  return 0;
}