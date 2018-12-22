package controllers;

import models.Student;
import play.mvc.With;

@With(Secure.class)
public class Students extends CRUD {
	
	@Check("studentNameModify") 
	public static void modifyName(String id){
		Student object = Student.findById(Long.parseLong(id));
		render("@changename", object);
	}

	public static void doModifyName(Student object){
		Student st = Student.findById(object.id);

		if (null != object.nameString) {
			// 保存新名字
			st.nameString = object.nameString;
			st.save();
			render("@modifynamedone", object);
		}
	}

}
