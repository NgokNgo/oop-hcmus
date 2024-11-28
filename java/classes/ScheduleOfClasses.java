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
        for(Section section:sections){
            if(section.getSectionNo().equals(sectionNo)){
                System.out.println("SectionNo already exists");
                return;
            }
        }
        
        Section section = new Section(sectionNo, dayOfWeek, timeOfDay, room, seatingCapacity);
        course.scheduleSection(section);
        sections.add(section);
    }

    public Section getSections(String SectionNo){
        for(Section section:sections){
            if(section.getSectionNo().equals(SectionNo)){
                return section;
            }
        }
        return null;
    }

    public void display() {
        System.out.println("Semester: " + this.getSemester());
        for(Section section:sections){
            section.display();
            System.out.println();
        }
    }
}
