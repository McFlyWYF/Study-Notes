package models;

import play.db.jpa.Model;

import javax.persistence.Entity;

@Entity
public class Student extends Model {

    public String number;
    public String name;
    public String sex;
    public String classId;
    public String college;

    public Student(String number, String name, String sex, String classId, String college) {
        this.number = number;
        this.name = name;
        this.sex = sex;
        this.classId = classId;
        this.college = college;
    }
}
