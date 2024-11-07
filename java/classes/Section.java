package oop.java.classes;

public class Section {
    private String sectionNo;
    private String dayOfWeek;
    private String timeOfDay;
    private String room;
    private int seatingCapacity;
    private ScheduleOfClasses semester;
    private Course course;

    public Section(String sectionNo, String dayOfWeek, String timeIfDay, String room, int seatingCapacity) {
        this.setSectionNo(sectionNo);
        this.setDayOfWeek(dayOfWeek);
        this.setTimeOfDay(timeOfDay);
        this.setRoom(room);
        this.setSeatingCapacity(seatingCapacity);
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

    public void display(){
        System.out.println("Course: "+this.getCourse().getCourseName());
        System.out.println("SectionNo: "+this.getSectionNo());
        System.out.println("Day of Week: "+this.getDayOfWeek());
        System.out.println("Time of Day: "+this.getTimeOfDay());
        System.out.println("Room: "+this.getRoom());
        System.out.println("Seating Capacity: "+this.getSeatingCapacity());
    }

    public Course getCourse() {
        return course;
    }

    public void setCourse(Course course) {
        this.course = course;
        if(course != null && !course.getSections().contains(this)){
            course.addSection(this);
        }
    }

}
