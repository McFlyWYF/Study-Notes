package controllers;

import models.User;
import play.data.validation.*;
import play.mvc.Controller;
import play.mvc.results.Result;

import java.text.Normalizer;

public class Login extends Controller {

    public static void login() {
        render();
    }

    public static void loginPost(@Required String username, String password){

        render(username,password);
    }

}
