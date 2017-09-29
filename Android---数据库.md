# 数据库的操作
## 1.创建数据库
SQLiteOpenHelper 是一个抽象类，有两个抽象方法，`onCreate()`和`onUpgrade()`,在这两个方法中去实现具体逻辑.SQLiteOpenHelper也有两个实例方法，`getWritableDatabase()`和`getReadableDatabase()`,这两个方法都可以创建或打开一个现有的数据库。
 ```java
 public class MyDatabaseHelper extends SQLiteOpenHelper {

    public static final String CREATE_BOOK = "create table Book ("

            +"id integer primary key sutoincrement,"
           +"author text,"
            +"price real,"
            +"name text)";
 private Context mContext;

    public MyDatabaseHelper(Context context, String name, SQLiteDatabase.CursorFactory factory,int version){
        super(context,name,factory,version);
        mContext = context;
    }

    @Override
    public void onCreate(SQLiteDatabase db){
·        db.execSQL(CREATE_BOOK);
        Toast.makeText(mContext,"Create succeeded",Toast.LENGTH_SHORT).show();
    }
public class MainActivity extends AppCompatActivity {

    private MyDatabaseHelper dbHelper;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        dbHelper = new MyDatabaseHelper(this,"BookStore.db",null,2);
        Button createDatabase = (Button) findViewById(R.id.create_database);
        createDatabase.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v){
                dbHelper.getWritableDatabase();
            }
        });
     }
```
## 2.升级数据库
* `onUpgrade()`方法适用于对数据库进行升级的
```java
public static final String CREATE_CATEGORY = "create table Category("
            +"id integer primary key autoincrement,"
            +"category_name text,"
            +"category_code integer)";
 @Override
    public void onCreate(SQLiteDatabase db){
        db.execSQL(CREATE_BOOK);
       db.execSQL(CREATE_CATEGORY);
        Toast.makeText(mContext,"Create succeeded",Toast.LENGTH_SHORT).show();
    }
 @Override
    public void onUpgrade(SQLiteDatabase db,int oldVersion,int newVersion){

        db.execSQL("drop table if exists Book");
        db.execSQL("drop table if exists Category");
        onCreate(db);
    }
```
将其中的1换位比1大的数字 `dbHelper = new MyDatabaseHelper(this,"BookStore.db",null,2);`
 
### 3.添加数据
* `insert()`方法,接收3个参数，第一个是表名，第二个为null，第三个是一个`ContentValues`对象，提供一个`put()`方法，用于向ContentValues传入对象
```java
Button addData = (Button) findViewById(R.id.add_data);
        addData.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v){
                SQLiteDatabase db = dbHelper.getWritableDatabase();
                ContentValues values = new ContentValues();
                //开始第一条数据
                values.put("name","The Da Vinci Code");
                values.put("author","Dan Brown");
                values.put("pages","454");
                values.put("price",16.96);
                db.insert("Book",null,values);//插入第一条数据
                values.clear();
                //开始第二条数据
                values.put("name","The Lost");
                values.put("author","Dan Brown");
                values.put("pages","510");
                values.put("price",18.96);
                db.insert("Book",null,values);//插入第二条数据
            }
        });
```
## 4.更新数据
* `update()`方法,接收4个参数
```java
Button updateData = (Button) findViewById(R.id.update_data);
        updateData.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v){
                SQLiteDatabase db = dbHelper.getWritableDatabase();
                ContentValues values = new ContentValues();
                values.put("price",10.99);
                db.update("Book",values,"name = ?",new String[]{
                        "The Da Vinci Code"});
                }
            });
```
## 5.删除数据
* `delete()`方法
```java
  Button deleteData = (Button) findViewById(R.id.delete_data);
        deleteData.setOnClickListener(new View.OnClickListener(){

            @Override
            public void onClick(View v) {
                SQLiteDatabase db = dbHelper.getWritableDatabase();
                db.delete("Book","pages > ?",new String[]{"500"});
            }
        });
```
## 6.查找数据
 ```java
 Button queryData = (Button) findViewById(R.id.query_data);
        queryData.setOnClickListener(new View.OnClickListener(){

            @Override
            public void onClick(View v){
                SQLiteDatabase db = dbHelper.getWritableDatabase();
                //查询Book中所有的数据
                Cursor cursor = db.query("Book",null,null,null,null,null,null);
                if (cursor.moveToFirst()){
                    do{
                        //遍历Cursor对象，取出数据并打印
                        String name = cursor.getString(cursor.getColumnIndex("name"));
                        String author = cursor.getString(cursor.getColumnIndex("author"));
                        int pages = cursor.getInt(cursor.getColumnIndex("pages"));
                        double price = cursor.getDouble(cursor.getColumnIndex("price"));

                        Log.d("MainActivity","book name is " + name);
                        Log.d("MainActivity","book author is " + author);
                        Log.d("MainActivity","book pages is " + pages);
                        Log.d("MainActivity","book price is " + price);
                    }while (cursor.moveToNext());
                }
                cursor.close();
            }
        });
```
## 使用SQL操作数据库
* ### 添加数据
```java
db.execSQL("insert into Book (name,author,pages,price) values(?,?,?,?)",
                new String[] {"The Da Vinci Code","Dan Brown","454","69.56"});
```
* ### 更新数据
```java       
        db.execSQL("update Book set price = ? where name = ?",new String[]{"10.99","The Da Vinci Code"});
```
* ### 删除数据
```java 
        db.execSQL("delete from Book where pages > ?",new String[]{"500"});
```
* ### 查询数据
```java       
        db.rawQuery("selete * from Book",null);
```
