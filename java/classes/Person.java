package oop.java.classes;

public class Person {
    // write Person class here
    private String ssn;
    private String name;

    public Person(String ssn, String name) {
        this.setSsn(ssn);
        this.setName(name);;
    }

    // getter setter
    public void setSsn(String ssn){
        this.ssn = ssn;
    }

    public String getSsn() {
        return this.ssn;
    }

    public void setName(String name){
        this.name = name;
    }

    public String getName() {
        return this.name;
    }

    //others
    public void display() {
        System.out.println("Name: " + getName());
        System.out.println("SSN: " + getSsn());
    }
}
