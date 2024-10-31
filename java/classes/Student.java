package oop.java.classes;

public class Student extends Person {
    private String major;
    private String degree;
    private Professor advisor;
    private PlanOfStudy planOfStudy;

    public Student(String ssn, String name, String major, String degree) {
        super(ssn, name);
        this.setmajor(major);
        this.setdegree(degree);
        this.planOfStudy = new PlanOfStudy();
    }

    //getter setter
    public void setmajor(String major) {
        this.major = major;
    }

    public String getMajor() {
        return this.major;
    }

    public void setdegree(String degree) {
        this.degree = degree;
    }

    public String getDegree() {
        return this.degree;
    }

    public void setAdvisor(Professor advisor) {
        this.advisor = advisor;
    }

    public Professor getAdvisor() {
        return this.advisor;
    }

    //others
    public void display() {
        super.display();
        System.out.println("Major: " + getMajor());
        System.out.println("Degree: " + getDegree());
    }

    public void displayAdvisor() {
        if (this.advisor == null) {
            System.out.println("Advisor: None");
            return;
        }
        System.out.println("Advisor:");
        this.advisor.display();
    }
    
    public void addToPlanOfStudy(Course course) {
        this.planOfStudy.addCourse(course);
    }

    public void displayPlanOfStudy() {
        this.planOfStudy.displayCourses();
    }
}