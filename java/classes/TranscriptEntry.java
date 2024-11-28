package oop.java.classes;

public class TranscriptEntry {
    private String grade;
    private Section section;

    public TranscriptEntry(String grade, Section section) {
        this.setGrade(grade);
        this.setSection(section);
    }
    
    public void setGrade(String grade) {
        this.grade = grade;
    }

    public String getGrade() {
        return this.grade;
    }

    public void setSection(Section section) {
        this.section = section;
    }

    public Section getSection() {
        return this.section;
    }

    public void display(){
        System.out.println("Section: " + section.getSectionNo());
        System.out.println("Grade: " + getGrade());
    }
}
