# Activity生命周期
* 1.onCreate()
* 2.onStart()
* 3.onResume()
* 4.onPause()
* 5.onStop()
* 6.onDestroy()
### 千万不能自己去调用Activity生命周期方法，只需在Activity子类里覆盖这些方法
* 启动应用，执行1,2,3.
* 退出应用,执行4.5.6.
* 后台运行，执行4,5.

### 覆盖onSaveInstanceState(Bundle)方法不仅仅用于处理与设备旋转，数据从头开始的问题，还可以解决数据丢失问题，在系统销毁activity之前保存数据
