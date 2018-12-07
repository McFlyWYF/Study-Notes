package models;

import play.db.jpa.Model;

import javax.persistence.Entity;

@Entity
public class User extends Model {

    public String account;
    public String password;

}
