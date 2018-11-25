package models;

import play.db.jpa.Model;

import javax.persistence.Entity;

@Entity
public class Course extends Model {

    public int id;
    public String coursename;
    public int redict;
    public String teacher;

    public Course(int id, String coursename, int redict, String teacher) {
        this.id = id;
        this.coursename = coursename;
        this.redict = redict;
        this.teacher = teacher;
    }
}
