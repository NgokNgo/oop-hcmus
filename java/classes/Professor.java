package oop.java.classes;

import java.util.HashMap;
import java.util.Map;

public class Professor extends Person{
    private String title;
    private Map<String, Student> advisees = new HashMap<String, Student>();

    public Professor(String ssn, String name, String title) {
        super(ssn, name);
        this.setTitle(title);
    }

    //getter setter
    public void setTitle(String title) {
        this.title = title;
    }

    public String getTitle() {
        return this.title;
    }

    //others
    public void display() {
        super.display();
        System.out.println("Title: " + getTitle());
    }

    public void addAdvisee(Student student) {
        if (student.getAdvisor() != null) {
            System.out.println("Student is already an advisee of this professor.");
            return;
        }
        this.advisees.put(student.getSsn(), student);
        student.setAdvisor(this);
    }

    public void removeAdvisee(Student student) {
        this.advisees.remove(student.getSsn());
        student.setAdvisor(null);
    }

    public void displayAdvisees() {
        if (this.advisees.isEmpty()) {
            System.out.println("No advisees.");
            return;
        }
        System.out.println("Advisees:");
        for (Student student : this.advisees.values()) {
            student.display();
            System.out.println();
        }
    }
}