package models;

import play.data.validation.Required;
import play.db.jpa.Model;

import javax.persistence.Entity;
import javax.persistence.ManyToMany;
import java.util.List;

@Entity
public class Fee extends Model {

    public String feeName;//费用名称
    public int feeSize;//费用大小
    public String date;//时间

    @ManyToMany
    public List<Student> studentsFee;

    public String toString(){
        return feeName;
    }

}
