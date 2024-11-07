package oop.java;

import oop.java.classes.Professor;
import oop.java.classes.ScheduleOfClasses;
import oop.java.classes.Student;
import oop.java.classes.Course;
import oop.java.classes.PlanOfStudy;

public class Main {
    public static void main(String[] args) {
        Course dsa = new Course("CSE 101", "DSA", 3);
        Course oop = new Course("CSE 102", "OOP", 3); 

        oop.addPrerequisity(dsa);
        
        Student student = new Student("1", "John Doe", "CSE", "BS");
        
        student.addToPlanOfStudy(oop);
        student.addToPlanOfStudy(dsa);
        student.addToPlanOfStudy(dsa);
        student.addToPlanOfStudy(oop);

        System.out.println("============================");
        student.displayPlanOfStudy();

        System.out.println("============================");
        ScheduleOfClasses sem1 = new ScheduleOfClasses("24-25/I");
        sem1.addSection(dsa, "A", "Mon", "9:00-11:00", "A101", 50);
        sem1.addSection(oop, "A", "Tue", "9:00-11:00", "A102", 50);
        sem1.addSection(oop, "B", "Wed", "9:00-11:00", "A103", 50);
        sem1.display();

    }
}