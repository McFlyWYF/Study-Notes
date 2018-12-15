package controllers;

import play.*;
import play.mvc.*;

import java.lang.reflect.Array;
import java.util.*;

import models.*;

//@With(Secure.class)
public class Application extends Controller {

    public static void index() {
        String user = Security.connected();
        render(user);
    }

    public static void users() {
        render();

    }

    public static void registerSucc() {
        int account = 0;
        int password = 0;

        int acc = 0;
        acc = 1607094101;
        for (int i = 0; i < 58; i++) {
            account = acc;

            acc = acc + 1;

            password = (int) Math.round(Math.random() * 1000);

            User user = new User(account,password);
            user.save();
        }

        render(account,password);

    }

}