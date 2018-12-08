package models;

import play.db.jpa.Model;

import javax.persistence.Entity;

@Entity
public class User extends Model {

    public int account;
    public int password;

    public User(int account, int password) {
        this.account = account;
        this.password = password;
    }
}
