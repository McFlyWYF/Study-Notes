# java封装
* 通过get和set方法让外界类来获取私有变量
* 只修改类的内部结构，无需修改其他调用片段
* People.java
```java
public class People {

	private String name;
	private String id;
	private int age;
	
	public void setName(String name) {
		this.name = name;
	}
	public String getName() {
		return name;
	}
	
	public void setId(String id) {
		this.id = id;
	}
	public String getId() {
		return id;
	}
	
	public void setAge(int age) {
		this.age = age;
	}
	public int getAge() {
		return age;
	}
}
```
* #PeopleDemo.java
```java
public class PeopleDemo {

	public static void main(String[] args) {
		People peo = new People();
		peo.setName("James");
		peo.setId("M");
		peo.setAge(20);
		System.out.println("Name: "+peo.getName());
		System.out.println("Id: "+peo.getId());
		System.out.println("Age: "+peo.getAge());
	}

}
```
