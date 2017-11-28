# Git简单操作
## 上传代码
* 1.git clone + ssh地址
* 2.git add .
* 3.git commit -m "first commit"
* 4.git push origin master

## 续传代码
* 1.git status    
#### 查看所在分支和修改的文件：若所在分支不在要上传代码的分支，则使用 git checkout+分支名，切换到该分支再进行操作，红色处表明已经被修改的文件，也为将要上传的文件。
* 2.git add -A
#### 添加所有要上传的文件(代码)，git status,此时4个文件变绿，表明将要上传到本地库
* 3.git commit -m  "随便写"
####  此时上传到本地repository
* 4.git push
####  此时提交到远程分支
* 5.git merge + 分支
#### 将分支上的代码合并到主分支上，首先要切换到主分支上
* 6.git branch -d + 分支 
####  删除分支

## 分支
* 1.git branch    
#### 查看项目目前的分支
* 2.git branch  + 分支
#### 创建分支
* 3.git checkout + 分支    
#### 将项目代码切换到新的分支上
