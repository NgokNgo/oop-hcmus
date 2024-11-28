package oop.java.classes;

import java.util.List;
import java.util.ArrayList;

public class Transcript {
    private Student student;
    private List<TranscriptEntry> transcriptEntries;

    public Transcript(Student student) {
        this.student = student;
        this.transcriptEntries = new ArrayList<TranscriptEntry>();
    }

    public void display(){
        for(TranscriptEntry te : transcriptEntries){
            te.display();
            System.out.println();
        }
    }

    public void addTranscriptEntry(TranscriptEntry te){
        transcriptEntries.add(te);
    }
}
