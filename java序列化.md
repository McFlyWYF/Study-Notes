# java序列化
* 一个对象可以被表示为一个字节序列，该字节序列包括该对象的数据、有关对象的类型的信息和存储在对象中数据的类型。
* 将序列化对象写入文件之后，可以从文件中读取出来，并且对它进行反序列化，也就是说，对象的类型信息、对象的数据，还有对象中的数据类型可以用来在内存中新建对象。
* 类 ObjectInputStream 和 ObjectOutputStream 是高层次的数据流，它们包含序列化和反序列化对象的方法。
### 序列化，就是将对象写入文件中，反序列化就是从文件中读取数据。序列化writeObject(),反序列化readObject().
* 检验一个类的实例是否能序列化十分简单， 只需要查看该类有没有实现 java.io.Serializable接口。
## 示例代码
* Employee.java
```java
public class Employee1 implements Serializable{

	public String name;
	public String address;
	public int number;
	public transient int SSN;
	public void mailCheck() {
		System.out.println(name+" "+address);
	}
}
```
* #SerializeDemo.java
```java
public class SerializeDemo{

	public static void main(String[] args) {
		/*
		 * 序列化，写入文件中
		Employee1 e = new Employee1();
		e.name = "Jhon";
		e.number = 10086;
		e.address = "NUC";
		e.SSN = 111;
		try {
			FileOutputStream fileout = new FileOutputStream("/test/employee.ser");
			ObjectOutputStream out = new ObjectOutputStream(fileout);
			out.writeObject(e);
			out.close();
			fileout.close();
			System.out.println("successful!");
		}catch (IOException e1) {
			e1.printStackTrace();
		}
		*/
		/*
		 * 反序列化，从文件中读取
		Employee1 e = null;
		try {
			FileInputStream filein = new FileInputStream("/test/employee.ser");
			ObjectInputStream in = new ObjectInputStream(filein);
			e = (Employee1)in.readObject();
			in.close();
			filein.close();
		}catch (IOException e1) {
			e1.printStackTrace();
			return;
		}catch (ClassNotFoundException e2) {
			System.out.println("Is not found!");
			e2.printStackTrace();
			return;
		}
		System.out.println("........");
		System.out.println("name:"+e.name);
		System.out.println("number:"+e.number);
		System.out.println("address:"+e.address);
		System.out.println("SSN:"+e.SSN);
		 */
	}
}
```
