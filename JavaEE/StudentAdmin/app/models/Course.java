package models;

import play.data.validation.Required;
import play.db.jpa.Model;

import javax.persistence.*;
import java.util.List;

@Entity
public class Course extends Model {

    public String CourseId;
    public String CourseName;
    public String credit;

    @ManyToMany(mappedBy = "courses",cascade = CascadeType.ALL,fetch = FetchType.LAZY)
    public List<Student> students;

    @OneToMany(mappedBy = "teachCourse",cascade = CascadeType.ALL,fetch = FetchType.LAZY)
    public List<Teacher> teachers;

    public String toString(){
        return CourseName;
    }
}
