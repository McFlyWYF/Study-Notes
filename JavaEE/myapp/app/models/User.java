package models;

import play.db.jpa.Model;

import javax.persistence.Entity;

@Entity
public class User extends Model {
    public String username;
    public String password;
    public String email;
    public String sex;

    public User(String username, String password, String email, String sex) {
        this.username = username;
        this.password = password;
        this.email = email;
        this.sex = sex;
    }
}
