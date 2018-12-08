package controllers;

import models.User;

public class Security extends Secure.Security {

    static boolean authenticate(int username,int password){

        User user = new User(username,password);
        boolean ret = (username == user.account) && (password == user.password);

        session.put("currentUser",username);
        return ret;
    }
}
