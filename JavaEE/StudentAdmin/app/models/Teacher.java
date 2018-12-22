package models;

import play.*;
import play.db.jpa.*;
import play.data.validation.*;
import javax.persistence.*;
import java.util.*;

@Entity
public class Teacher extends Model {
	@Required
	@MaxSize(8)
	public String name;

	public String email;

	@OneToMany(mappedBy = "myTeacher", cascade = CascadeType.ALL, fetch = FetchType.LAZY)
	public List<Student> students;
	
	public String toString() {
		return name;
	}
}
