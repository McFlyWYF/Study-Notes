package controllers;

import play.mvc.Controller;

public class Register extends Controller {

    public static void register(){
        render();
    }

    public static void registerPost(String username,String password,String email,String sex){
        render(username,password,email,sex);
    }
}
