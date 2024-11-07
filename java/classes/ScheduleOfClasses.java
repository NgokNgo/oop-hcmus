package oop.java.classes;

import java.util.ArrayList;
import java.util.List;

public class ScheduleOfClasses {
    private String semester;
    private List<Section> sections;

    public ScheduleOfClasses(String semester){
        this.setSemester(semester);
        this.sections = new ArrayList<Section>();    
    }

    public void setSemester(String semester) {
        this.semester = semester;
    }

    public String getSemester(){
        return this.semester;
    }

    public void addSection(Course course, String sectionNo, String dayOfWeek, String timeOfDay, String room, int seatingCapacity) {
        Section section = new Section(sectionNo, dayOfWeek, timeOfDay, room, seatingCapacity);
        section.setCourse(course);
        if(!sections.contains(section)){
            sections.add(section);
        }
    }

    public List<Section> getSections(){
        return sections;
    }

    public void display() {
        System.out.println("Semester: " + this.getSemester());
        for(Section section:sections){
            section.display();
        }
    }
}
