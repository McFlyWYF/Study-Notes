# activity之间的数据传递
## 一、基于Intent的通信
### 1.显式intent
* `Intent`接收两个参数`(Context context,Class)`,其中，传入方法的`class`类型告诉参数ActivityManager应该启动哪个活动，`Context`参数告诉ActivityManager在哪可以找到它。
```java
mCheatButton = (Button) findViewById(R.id.cheat_button);
mCheatButton.setOnClickListener(new View.OnClickListener(){
   @Override
   public void onClick(View v){
     Intent intent = new Intent(MainActivity.this,CheatActivity,class);
     startActivity(intent);
     }
)
```
### 2.隐式intent
## 二、activity间的数据传递
