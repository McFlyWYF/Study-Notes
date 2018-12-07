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
        List account = new ArrayList();
        List password = new ArrayList();

        int acc = 0;
        acc = 1607094101;
        for (int i = 0; i < 58; i++) {
            account.add(acc);
//            System.out.println(account);
            acc = acc + 1;

            password.add(Math.round(Math.random() * 1000));
        }

        render(account, password);

    }

}