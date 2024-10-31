package oop.java.classes;

import java.util.ArrayList;
import java.util.List;

public class PlanOfStudy {
    private List<Course> courses = new ArrayList<Course>();

    public List<Course> getCourses() {
        return this.courses;
    }

    public void displayCourses() {
        if (this.courses.isEmpty()) {
            System.out.println("No courses in the plan of study.");
            return;
        }
        for (Course course : this.courses) {
            course.display();
        }
    }

    public void addCourse(Course course) {
        if(this.courses.contains(course) || course == null){
            System.out.println("Can not add course to the plan of study because it is already in the plan of study or it is null.");
            return;
        }
        List<Course> prerequisities = course.getPrerequisities();
        //check if prerequisities are in courses
        for (Course p : prerequisities) {
            if (!this.courses.contains(p)) {
                System.out.println("Prerequisity " + p.getCourseName() + " is not in the plan of study.");
                return;
            }
        }
        this.courses.add(course);
        System.out.println("Course " + course.getCourseName() + " added to the plan of study.");
    }    
}
