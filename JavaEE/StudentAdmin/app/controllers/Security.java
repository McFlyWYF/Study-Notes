package controllers;

public class Security extends Secure.Security {

    static boolean authenticate(String username,String password){
        boolean ret = username != null && password != null && username.equals("root") && password.equals("12345") || username.equals("stu") && password.equals("123");

        session.put("currentUser",username);
        return ret;
    }
}
