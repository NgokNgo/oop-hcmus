package oop.java.classes;

import java.util.List;
import java.util.ArrayList;
public class Section {
    private String sectionNo;
    private String dayOfWeek;
    private String timeOfDay;
    private String room;
    private int seatingCapacity;
    private ScheduleOfClasses semester;
    private Course course;
    private List<Student> enrolledStudents;

    public Section(String sectionNo, String dayOfWeek, String timeIfDay, String room, int seatingCapacity) {
        this.setSectionNo(sectionNo);
        this.setDayOfWeek(dayOfWeek);
        this.setTimeOfDay(timeOfDay);
        this.setRoom(room);
        this.setSeatingCapacity(seatingCapacity);
        this.course = null;
        this.enrolledStudents = new ArrayList<Student>();
    }

    public String getSectionNo() {
        return sectionNo;
    }

    public void setSectionNo(String sectionNo) {
        this.sectionNo = sectionNo;
    }

    public String getDayOfWeek() {
        return dayOfWeek;
    }

    public void setDayOfWeek(String dayOfWeek) {
        this.dayOfWeek = dayOfWeek;
    }

    public String getTimeOfDay() {
        return timeOfDay;
    }

    public void setTimeOfDay(String timeOfDay) {
        this.timeOfDay = timeOfDay;
    }

    public String getRoom() {
        return room;
    }

    public void setRoom(String room) {
        this.room = room;
    }

    public int getSeatingCapacity() {
        return seatingCapacity;
    }

    public void setSeatingCapacity(int seatingCapacity) {
        this.seatingCapacity = seatingCapacity;
    }

    public ScheduleOfClasses getSemester() {
        return semester;
    }

    public void setSemester(ScheduleOfClasses semester) {
        this.semester = semester;
    }

    public Course getCourse() {
        return course;
    }

    public void setCourse(Course course) {
        this.course = course;
    }

    public void display(){
        if(this.getCourse() != null){
            System.out.println("Course: "+this.getCourse().getCourseName());
        }
        System.out.println("SectionNo: "+this.getSectionNo());
        System.out.println("Day of Week: "+this.getDayOfWeek());
        System.out.println("Time of Day: "+this.getTimeOfDay());
        System.out.println("Room: "+this.getRoom());
        System.out.println("Seating Capacity: "+this.getSeatingCapacity());
    }

    public void enroll(Student student){
        if(enrolledStudents.contains(student)){
            System.out.println("Student already enrolled in this section");
            return;
        }
        if(enrolledStudents.size() >= seatingCapacity){
            System.out.println("Section is full");
            return;
        }

        enrolledStudents.add(student);
        student.addSection(this);
    }

    public void dropStudent(Student student){
        if(enrolledStudents.contains(student)){
            enrolledStudents.remove(student);
            student.dropSection(this);
        }
    }

    public void displayEnrolledStudents(){
        for(Student student: enrolledStudents){
            student.display();
        }
    }

    public void postGrade(Student student, String grade){
        if(!enrolledStudents.contains(student)){
            System.out.println("Student not enrolled in this section");
            return;
        }

        TranscriptEntry te = new TranscriptEntry(grade, this);
        student.getTranscript().addTranscriptEntry(te);
    }
}
