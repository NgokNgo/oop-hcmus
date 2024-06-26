#include <iostream>
#include<map>

using namespace std;
class Professor;
class Transcipt;
class Student;
class TransciptEntry;
class Section;
class PlanOfStudy;
class Course;

class Person{
private:
  string ssn;
  string name;
public:
  void setSsn(string ssn){this->ssn = ssn;}
  string getSsn(){return ssn;}
  void setName(string name){this->name = name;}
  string getName(){return name;}

  Person(string ssn, string name){
    setSsn(ssn);
    setName(name);
  }

  virtual void display(){
    cout << "SSN: " << getSsn() << endl;
    cout << "Name: " << getName() << endl;
  }
};

class Section{
private:
  string sectionNo;
  char dayOfWeek;
  string timeOfDay;
  string semester;
  string room;
  int seatingCapacity;
  Professor *teacher;
  Course *course;
  map <string, Student*> students;
  map <string, Student*> waitlist;
public:
  void setSectionNo(string sectionNo){this->sectionNo = sectionNo;}
  string getSectionNo(){return sectionNo;}
  void setDayOfWeek(char dayOfWeek){this->dayOfWeek = dayOfWeek;}
  char getDayOfWeek(){return dayOfWeek;}
  void setTimeOfDay(string timeOfDay){this->timeOfDay = timeOfDay;}
  string getTimeOfDay(){return timeOfDay;}
  void setSemester(string semester){this->semester = semester;}
  string getSemester(){return semester;}
  void setRoom(string room){this->room = room;}
  string getRoom(){return room;}
  void setSeatingCapacity(int seatingCapacity){this->seatingCapacity = seatingCapacity;}
  int getSeatingCapacity(){return seatingCapacity;}

  // constructor
  Section(string sectionNo, char dayOfWeek, string timeOfDay, string semester, string room, int seatingCapacity){
    setSectionNo(sectionNo);
    setDayOfWeek(dayOfWeek);
    setTimeOfDay(timeOfDay);
    setSemester(semester);
    setRoom(room);
    setSeatingCapacity(seatingCapacity);
  }
  
  void teachBy(Professor *professor){
    this->teacher = professor;
  }
  void setCourse(Course *course){
    this->course = course;
  }
  void enroll(Student *student);
  void drop(Student *student);
  void postGrade(Student *student, string grade);
};

class Course{
private:
  string courseNo;
  string courseName;
  int credits;
  map<string, Course*> prerequisites;
  map<string, Section*> sections;
public:
  void setCourseNo(string courseNo){this->courseNo = courseNo;}
  string getCourseNo(){return courseNo;}
  void setCourseName(string courseName){this->courseName = courseName;}
  string getCourseName(){return courseName;}
  void setCredits(int credits){this->credits = credits;}
  int getCredits(){return credits;}

  Course(string courseNo, string courseName, int credits){
    setCourseNo(courseNo);
    setCourseName(courseName);
    setCredits(credits);
  }
  ~Course(){
    for(auto section : sections){
      delete section.second;
    }
  }
  void showInfo(){
    cout << "Course No: " << getCourseNo() << endl;
    cout << "Course Name: " << getCourseName() << endl;
    cout << "Credits: " << getCredits() << endl;
  }
  void showSections(){
    for(auto section : sections){
      cout << "Section No: " << section.second->getSectionNo() << endl;
    }
  }

  void addPrerequisites(Course *course){
    prerequisites[course->getCourseNo()] = course;
  }
  void addSection(Section *section){
    sections[section->getSectionNo()] = section;
  }
  Section *scheduleSection(char dayOfWeek, string timeOfDay, string semester, string room, int seatingCapacity){
    Section *section = new Section(this->getCourseName() + semester, dayOfWeek, timeOfDay, semester, room, seatingCapacity);
    section->setCourse(this);
    this->addSection(section);
    return section;
  } 
};

class PlanOfStudy{
private:
  Student *student;
  map<string, Course*> courses;
public:
  void addCourse(Course *course){
    courses[course->getCourseNo()] = course;
  }
  void display(){
    for(auto course : courses){
      course.second->showInfo();
      cout << endl;
    }
  }
};

class TransciptEntry{
private:
  string grade;
  Section *section;
  Transcipt *transcipt;
public:
  void setGrade(string grade){this->grade = grade;}
  string getGrade(){return grade;}
  TransciptEntry(){}
  TransciptEntry(string grade, Section *s){
    this->section = s;
    setGrade(grade);
  }

  bool pass(){
    if(grade[0] == 'A' || grade[0] == 'B' || grade[0] == 'C' || grade[0] == 'D'){
      return true;
    }
    return false;
  }
};

class Transcipt{
private:
  Student *student;
  map<string, TransciptEntry*> entries;
public:
    Transcipt(Student *student){ this->student = student; }
  ~Transcipt(){
    for(auto entry : entries){
      delete entry.second;
    }
  }

  void display();

  void addEntry(Course *course, string grade){
    TransciptEntry *entry = new TransciptEntry;
    entry->setGrade(grade);
    entries[course->getCourseNo()] = entry;
  }
  
  void checkPass(Course *course){
    if(entries[course->getCourseNo()]->pass()){
      cout << "Course " << course->getCourseNo() << " passed" << endl;
    }
    else{
      cout << "Course " << course->getCourseNo() << " failed" << endl;
    }
  }
};

class Student : public Person{
private:
  string major;
  string degree;
  Professor *advisor;
  PlanOfStudy *plan;
  Transcipt *transcipt;
  map <string, Section*> sections;
public:
  void setMajor(string major){this->major = major;}
  string getMajor(){return major;}
  void setDegree(string degree){this->degree = degree;}
  string getDegree(){return degree;}
  Transcipt *getTranscipt(){return transcipt;}

  Student(string ssn, string name, string major, string degree) : Person(ssn, name){
    setMajor(major);
    setDegree(degree);
    plan = new PlanOfStudy;
    transcipt = new Transcipt(this);
  }
  ~Student(){
    delete plan;
    delete transcipt;
  }

  void display(){
    cout << "Student info: " << endl;
    Person::display();
    cout << "Major: " << getMajor() << endl;
    cout << "Degree: " << getDegree() << endl;
    cout << endl;
  }

  void setAdvisor(Professor *professor){
    this->advisor = professor;
  }
  void addCourse(Course *course){
    this->plan->addCourse(course);
  }
  void displayPlanOfStudy(){
    this->plan->display();
  }
  void addSection(Section *section){
    sections[section->getSectionNo()] = section;
  }
  void dropSection(Section *section){
    sections.erase(section->getSectionNo());
  }
  void verifyCompletion(Course *course){
    this->transcipt->checkPass(course);
  }
};

class Professor : public Person{
private:
  string title;
  map<string, Student*> advisees; 
  map<string, Section*> sections;
public:
  void setTitle(string title){this->title = title;}
  string getTitle(){return title;}

  Professor(string ssn, string name, string title) : Person(ssn, name){
    setTitle(title);
  }

  void showAdvisee(){
    cout << "Professor info: " << endl;
    Person::display();
    cout << "Title: " << getTitle() << endl;
    cout << "--Advisees-- " << endl;
    for(auto advisee : advisees){
      advisee.second->display();
    }
    cout << endl;
  }
  void showSections(){
    for(auto section : sections){
      cout << "Section No: " << section.second->getSectionNo() << endl;
    }
    cout << endl;
  }

  void addAdvisee(Student *student){
    advisees[student->getSsn()] = student;
    student->setAdvisor(this);
  }
  void teach(Section *section){
    sections[section->getSectionNo()] = section;
    section->teachBy(this);
  }
};

void Transcipt::display(){
  cout << "Transcipt of student: " << student->getName() << endl;
  for(auto entry : entries){
    cout << "Course: " << entry.first << " | Grade: " << entry.second->getGrade() << endl;
  }
}

void Section::enroll(Student *student){
  if(students.size() < seatingCapacity){
    students[student->getSsn()] = student;
    student->addSection(this);
    cout << "Enroll success" << endl;
  }
  else{
    waitlist[student->getSsn()] = student;
    student->dropSection(this);
    cout << "Section is full, student is now on waitlist" << endl;
  }
}
  
void Section::drop(Student *student){
  students.erase(student->getSsn());
  cout << "Student dropped" << endl;
}

void Section::postGrade(Student *student, string grade){
  if(students.find(student->getSsn()) != students.end()){
    student->getTranscipt()->addEntry(course, grade);
  }
}

int main(){
  Student student("1", "An", "Computer Science", "BS");
  Student student2("2", "Manh", "Computer Science", "BS");
  Professor professor("234", "Ba", "PhD");
  professor.addAdvisee(&student);
  // student.display();

  Course course("CS101", "Intro to CS", 3);
  Course course2("CS102", "Intro to CS2", 3);
  student2.addCourse(&course);
  // student2.displayPlanOfStudy();

  Section *section = course.scheduleSection('M', "8:00-9:00", "Fall", "A1", 100);
  professor.teach(section);
  // professor.showSections();
  section->enroll(&student2);

  section->postGrade(&student2, "A");
  student2.getTranscipt()->display();
  student2.verifyCompletion(&course);
  return 0;
}