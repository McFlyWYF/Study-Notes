# OpenCv使用Python实现
## 图像的读取和写入
```python
#读入图像
img = cv2.imread('E:\MachineLearning\image\img1.jpg')

#打印图像尺寸
h,w = img.shape[:2]
print(h,w)

#保存原jpg格式为png格式
cv2.imwrite('E:\MachineLearning\image\img3.png',img)
```
* 原图

![Image Text](https://raw.github.com/wangyufei1006/Java-Design-patterns/master/Image/img44.png)
## 显示图像和结果
```python
#添加字体支持
from matplotlib.font_manager import FontProperties
font = FontProperties(fname=r"c:\windows\fonts\SimSun.ttc",size = 14)

#读入图像
img = cv2.imread('E:\MachineLearning\image\img1.jpg')

#转换颜色空间
gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)#灰度图

#显示积分图像
fig = plt.figure()
subplot(121)
plt.gray()
imshow(gray)
title(u'灰度图', fontproperties= font)
axis('off')

#计算积分图像
intim = cv2.integral(gray)

#归一化
intim = (255.0*intim)

#显示积分图像
subplot(122)
plt.gray()
imshow(intim)
title(u'积分图', fontproperties= font)
axis('off')
show()

#用opencv显示图像
#cv2.imshow("Image", gray)
#cv2.waitKey()
```
* 灰度图

![Image Text](https://raw.github.com/wangyufei1006/Java-Design-patterns/master/Image/img40.png)

* 积分图

![Image Text](https://raw.github.com/wangyufei1006/Java-Design-patterns/master/Image/img43.png)

# 从种子像素开始应用泛洪(漫水)填充
```python
#添加字体支持
from matplotlib.font_manager import FontProperties
font = FontProperties(fname=r"c:\windows\fonts\SimSun.ttc",size = 14)

#读入图像
img = cv2.imread('E:\MachineLearning\image\img1.jpg')

#转换颜色空间
rgb = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)

#显示原图
fig = plt.figure()
subplot(121)
plt.gray()
imshow(rgb)
title(u'原图',fontProperties = font)
axis('off')

#获取图像尺寸
h,w = img.shape[:2]
print(h,w)

#泛洪填充
diff = (6,6,6)
mask = zeros((h+2,w+2),numpy.uint8)
cv2.floodFill(img,mask,(10,10),(255,255,0),diff,diff)

#显示泛洪填充后的结果
subplot(122)
imshow(img)
title(u'泛洪填充',fontproperties = font)
axis('off')
show()

cv2.namedWindow('flood fill',0)
cv2.imshow('flood fill',img)
cv2.waitKey()
cv2.imwrite('E:\MachineLearning\image\img10.jpg',rgb)
cv2.imwrite('E:\MachineLearning\image\img11.jpg',img)
```
* 泛洪图

![Image Text](https://raw.github.com/wangyufei1006/Java-Design-patterns/master/Image/img41.png)


# 提取图像的SURF(加速稳健特征)特征
```python
#读入图像
img = cv2.imread('E:\MachineLearning\image\img1.jpg')

#下采样
im_lowers = cv2.pyrDown(img)

#转化为灰度图像
gray = cv2.cvtColor(im_lowers,cv2.COLOR_BGR2GRAY)

#检测特征点
s = cv2.xfeatures2d.SURF_create()
mask = numpy.uint8(ones(gray.shape))
keypoints = s.detect(gray,mask)

#显示图像及特征点
vis = cv2.cvtColor(gray,cv2.COLOR_GRAY2BGR)
for k in keypoints[::10]:
    cv2.circle(vis,(int(k.pt[0]),int(k.pt[1])),2,(0,255,0),-1)
    cv2.circle(vis,(int(k.pt[0]),int(k.pt[1])),int(k.size),(0,255,0),2)
print(vis.shape)
print(img.shape)
imshow(vis)
show()
#cv2.namedWindow('local descriptors',0)
#cv2.imshow('local descriptors',vis)
#cv2.waitKey()
#用pyrDown下采样，得到的一幅尺寸是原图像尺寸一半的降采样图像，即im_lowres，然后将图像转换为灰度图像，并将它传递给SURF关键点检测对象
cv2.imwrite('E:\MachineLearning\image\img12.jpg',vis)
```
* 特征提取图

![Image Text](https://raw.github.com/wangyufei1006/Java-Design-patterns/master/Image/img42.png)

# 视频处理
```python
cap = cv2.VideoCapture(0)
while True:
    ret,img = cap.read()
    #blur = cv2.GaussianBlur(img,(0,0),10)#进行模糊处理
    cv2.imshow('video test',img)
    key = cv2.waitKey(10)
    if key == 27:
        break
    if key == ord(' '):
        cv2.imwrite('E:\MachineLearning\image\vid_result.jpg',img)
```
# 读取视频到numpy数组
```python
cap = cv2.VideoCapture(0)
frames = []

while True:
    ret,img = cap.read()
    cv2.imshow('video',img)
    frames.append(img)
    if cv2.waitKey(10) == 27:
        break
frames = array(frames)
print(img.shape)
print(frames.shape)#帧数，高度，宽度，3
```
