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
### 2.1使用intent extra(从父activity向子activity传入数据)
* extra信息可以是任意数据，它包含在Intent中，由启动方activity发送出去。extra也是一种键值结构，可以把它想象成构造函数。Intent.putExtra()方法接收两个参数，一个参数固定为String类型的键，另一个参数是键值，可以是多种数据类型。该方法返回intent自身。
* CheatActivity
```java
public static Intent newIntent(Context packageContext, boolean answerIsTrue){
        Intent intent = new Intent(packageContext,CheatActivity.class);
        intent.putExtra(EXTRA_ANSWER_IS_TRUE,answerIsTrue);
        return intent;
    }
```
* MainActivity
```java
        mcheatButton = (Button) findViewById(R.id.cheat_button);
        mcheatButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                boolean answerIsTrue = mQuestionsBank[mCurrentIndex].isAnswerTrue();
                Intent intent = CheatActivity.newIntent(MainActivity.this,answerIsTrue);
                startActivity(intent);

            }
        });
 ```
 ### 2.2 从子activity向父activity返回数据
 * startActivityForResult()接收两个参数，一个是intent，一个是请求代码。
 ```java
  private static final int REQUEST_CODE_CHEAT = 0;
  startActivityForResult(intent,REQUEST_CODE_CHEAT);
 ```
 * 实现子activity发送返回信息给父activity，有两种方法：
 * 2.2.1   public final void setResult(int resultcode)
 * 2.2.2   public final void setResult(int resultcode,Intent data)
 #### 一般来说，resultCode可以是以下任意一个预定义常量。
 * Activity.RESULT_OK
 * Activity.RESULT_CANCELED
 ## 代码示例
 ```java
 public class MainActivity extends AppCompatActivity {
 private boolean mIsCheater;
 private static final int REQUEST_CODE_CHEAT = 0;
 @Override
    protected void onCreate(Bundle savedInstanceState) {
    mNextButton = (Button) findViewById(R.id.next_button);
        mNextButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                mCurrentIndex = (mCurrentIndex + 1) % mQuestionsBank.length;
                mIsCheater = false;
                updateQuestion();
            }
        });
        mcheatButton = (Button) findViewById(R.id.cheat_button);
        mcheatButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                //具体逻辑
                //Intent intent = new Intent(MainActivity.this,CheatActivity.class);
                boolean answerIsTrue = mQuestionsBank[mCurrentIndex].isAnswerTrue();
                Intent intent = CheatActivity.newIntent(MainActivity.this, answerIsTrue);
                startActivityForResult(intent, REQUEST_CODE_CHEAT);
                //startActivity(intent);

            }
        });
        @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        if (resultCode != Activity.RESULT_OK) {
            return;
        }
        if (requestCode == REQUEST_CODE_CHEAT) {
            if (data == null) {
                return;
            }
            mIsCheater = CheatActivity.wasAnswerShown(data);
        }
    }
private void checkAnswer(boolean userPressedTrue) {
        boolean answerIsTrue = mQuestionsBank[mCurrentIndex].isAnswerTrue();

        int messageResId = 0;
        if (mIsCheater) {
            messageResId = R.string.judgement_toast;
        } else {
            if (userPressedTrue == answerIsTrue) {
                messageResId = R.string.correct_toast;
            } else {
                messageResId = R.string.incorrect_toast;
            }
        }
        Toast.makeText(this, messageResId, Toast.LENGTH_SHORT).show();
    }
    
 ```
 ```java
 public class CheatActivity extends AppCompatActivity {

    private static final String EXTRA_ANSWER_IS_TRUE =
            "com.example.myapplication.answer_is_true";

    private static final String EXTRA_ANSWER_SHOWN =
            "com.example.myapplication.answer_shown";

    private boolean mAnswerIsTrue;
    private TextView mAnswerTextView;
    private Button mShowAnswerButton;

    public static Intent newIntent(Context packageContext, boolean answerIsTrue){
        Intent intent = new Intent(packageContext,CheatActivity.class);
        intent.putExtra(EXTRA_ANSWER_IS_TRUE,answerIsTrue);
        return intent;
    }

    public static boolean wasAnswerShown(Intent result){
        return result.getBooleanExtra(EXTRA_ANSWER_SHOWN,false);
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_cheat);
        mAnswerIsTrue = getIntent().getBooleanExtra(EXTRA_ANSWER_IS_TRUE,false);

        mAnswerTextView = (TextView) findViewById(R.id.answer_text_view);
        mShowAnswerButton = (Button) findViewById(R.id.show_answer_button);
        mShowAnswerButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (mAnswerIsTrue){
                    mAnswerTextView.setText(R.string.true_button);
                }else{
                    mAnswerTextView.setText(R.string.false_button);
                }
                setActivityShownResult(true);
            }
        });
    }

    private void setActivityShownResult(boolean isAnswerShown) {
        Intent data = new Intent();
        data.putExtra(EXTRA_ANSWER_SHOWN,isAnswerShown);
        setResult(RESULT_OK,data);
    }
}
```
