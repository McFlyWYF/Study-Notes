package models;

import play.data.validation.Required;
import play.db.jpa.Model;

import javax.persistence.*;
import java.sql.Connection;
import java.sql.ResultSet;
import java.util.List;

@Entity
public class Student extends Model {

    public String name;
    public String number;
    public String sex;
    public String college;


    public String credit;

    @ManyToOne
    public Teacher myTeacher;

    @ManyToMany
    public List<Course> courses;

    @ManyToMany(mappedBy = "studentsFee",cascade = CascadeType.ALL,fetch = FetchType.LAZY)
    public List<Fee> fees;

    public String toString(){
        return name;
    }

}
