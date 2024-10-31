package oop.java.classes;

import java.util.ArrayList;
import java.util.List;

public class Course {
    private String courseNo;
    private String courseName;
    private int credit;
    private List<Course> prerequisities = new ArrayList<Course>();

    public Course(String courseNo, String courseName, int credit) {
        this.setCourseNo(courseNo);
        this.setCourseName(courseName);
        this.setCredit(credit);
    }

    //getter setter
    public void setCourseNo(String courseNo) {
        this.courseNo = courseNo;
    }

    public String getCourseNo() {
        return this.courseNo;
    }

    public void setCourseName(String courseName) {
        this.courseName = courseName;
    }

    public String getCourseName() {
        return this.courseName;
    }

    public void setCredit(int credit) {
        this.credit = credit;
    }

    public int getCredit() {
        return this.credit;
    }

    //others
    public void display(){
        System.out.println("Course No: " + getCourseNo());
        System.out.println("Course Name: " + getCourseName());
        System.out.println("Credit: " + getCredit());
        System.out.println();
    }

    public void displayPrerequisities() {
        System.out.println("Prerequisities:");
        if (this.prerequisities.isEmpty()) {
            System.out.println("No prerequisities.");
            return;
        }
        for (Course course : getPrerequisities()) {
            System.out.println(course.getCourseNo() + " " + course.getCourseName());
        }
    }

    public void addPrerequisity(Course course) {
        if(this.prerequisities.contains(course) || course == null){
            System.out.println("Can not add prerequisity to the course because it is already in the plan of study or it is null.");
            return;
        }
        this.prerequisities.add(course);
    }

    public List<Course> getPrerequisities() {
        return this.prerequisities;
    }

    public void removePrerequisity(Course course) {
        this.prerequisities.remove(course);
    }
}
