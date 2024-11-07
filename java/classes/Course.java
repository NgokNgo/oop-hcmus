package oop.java.classes;

import java.util.ArrayList;
import java.util.List;

public class Course {
    private String courseNo;
    private String courseName;
    private int credit;
    private List<Course> prerequisities;
    private List<Section> sections;

    public Course(String courseNo, String courseName, int credit) {
        this.setCourseNo(courseNo);
        this.setCourseName(courseName);
        this.setCredit(credit);
        this.prerequisities = new ArrayList<Course>();
        this.sections = new ArrayList<Section>();
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

    public void scheduleSection(String sectionNo, String dayOfWeek, String timeOfDay, String room, int seatingCapacity) {
        Section section = new Section(sectionNo, dayOfWeek, timeOfDay, room, seatingCapacity);
        section.setCourse(this);
        this.addSection(section);
    }

    public List<Section> getSections() {
        return this.sections;
    }

    public void addSection(Section section) {
        if(this.sections.contains(section) || section == null){
            System.out.println("Can not add section to the course because it is already in the plan of study or it is null.");
            return;
        }
        this.sections.add(section);
    }

    public void removeSection(Section section) {
        if(!this.sections.contains(section)){
            System.out.println("Can not remove section from the course because it is not in the plan of study.");
            return;
        }
        this.sections.remove(section);
        section.setCourse(null);
    }
}
