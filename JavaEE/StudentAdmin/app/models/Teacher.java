package models;

import play.data.validation.MaxSize;
import play.data.validation.Required;
import play.db.jpa.Model;

import javax.persistence.*;
import java.util.List;

@Entity
public class Teacher extends Model {

    @MaxSize(8)
    public String name;
    public String email;

    @OneToMany(mappedBy = "myTeacher",cascade = CascadeType.ALL,fetch = FetchType.LAZY)
    public List<Student> students;

    @ManyToOne
    public Course teachCourse;

    public String toString(){
        return name;
    }
}
