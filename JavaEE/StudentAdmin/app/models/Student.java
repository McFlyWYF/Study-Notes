package models;

import play.*;
import play.data.validation.*;
import play.db.jpa.*;
import javax.persistence.*;
import java.util.*;

@Entity
public class Student extends Model {

	@Required
	public String nameString;
	
	@Required
	@Email
	public String email;
	public String address;
	
	@Required
	@ManyToOne
	public Teacher myTeacher;
	
	public String toString() {
		return nameString;
	}
	
}