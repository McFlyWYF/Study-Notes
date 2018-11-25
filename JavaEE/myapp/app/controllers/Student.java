package controllers;

import play.mvc.Controller;

public class Student extends Controller {

    public static void information(String number, String name, String sex, String classId, String college){
        render(number,name,sex,classId,college);
    }

    public static void updateStudent(){
        render();
    }

    public static void deleteInfo(){
        render();
    }

    public static void addStudent(){
        render();
    }

    public static void studentInfo(){
        render();
    }
}
