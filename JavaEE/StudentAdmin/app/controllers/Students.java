package controllers;

import models.Student;
import play.mvc.With;

@With(Secure.class)
public class Students extends CRUD {

    @Check("studentNameModify")
    public static void modifyName(String id){
        Student object = Student.findById(Long.parseLong(id));
        render("@changename",object);
    }


    public static void doModifyName(Student object){
        Student st = Student.findById(object.id);

        if (null != object.name) {
            // 保存新名字
            st.name = object.name;
            st.save();
            render("@modifynamedone", object);
        }
    }

    public static boolean check(String profile){
        if(Security.isConnected()){
            String user = Security.connected();
            boolean rst = false;
            if(profile.equals("studentNameModify") && user.equals("stu"))
                rst = true;
            return rst;
        }
        else{
            return false;
        }
    }

}
