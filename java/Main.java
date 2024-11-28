package oop.java;

import oop.java.classes.Professor;
import oop.java.classes.ScheduleOfClasses;
import oop.java.classes.Section;
import oop.java.classes.Student;
import oop.java.classes.Course;
import oop.java.classes.PlanOfStudy;

public class Main {
    public static void main(String[] args) {
        Course dsa = new Course("CSE 101", "DSA", 3);
        Course oop = new Course("CSE 102", "OOP", 3); 

        oop.addPrerequisity(dsa);
        
        Student student = new Student("1", "John Doe", "CSE", "BS");
        Student student2 = new Student("2", "Alapaca", "CSE", "BS");
        
        student.addToPlanOfStudy(oop);
        student.addToPlanOfStudy(dsa);
        student.addToPlanOfStudy(dsa);
        student.addToPlanOfStudy(oop);

        System.out.println("============================");
        // student.displayPlanOfStudy();

        System.out.println("============================");
        ScheduleOfClasses sem1 = new ScheduleOfClasses("24-25/I");
        sem1.addSection(dsa, "A", "Mon", "9:00-11:00", "A101", 50);
        sem1.addSection(oop, "A", "Tue", "9:00-11:00", "A102", 50);
        sem1.addSection(oop, "B", "Wed", "9:00-11:00", "A103", 50);
        // sem1.display();
        
        System.out.println("============================");
        // oop.displaySections();

        System.out.println("============================");
        Section sec_dsa = sem1.getSections("A");
        Section sec_oop = sem1.getSections("B");
        sec_dsa.enroll(student);
        sec_dsa.enroll(student);
        sec_dsa.enroll(student2);
        sec_oop.enroll(student);
        
        // sec_dsa.displayEnrolledStudents();
        // student.displaySections();
        System.out.println("============================");
        sec_dsa.postGrade(student, "10");
        sec_dsa.postGrade(student2, "9");
        sec_oop.postGrade(student, "8");
        sec_oop.postGrade(student2, "7");

        // student.displayTranscript();
        // student2.displayTranscript();
    }
}