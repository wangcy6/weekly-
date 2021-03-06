###  git 教程
- https://www.atlassian.com/git/tutorials/learn-git-with-bitbucket-cloud
- https://backlog.com/git-tutorial/cn/
- https://happygitwithr.com/big-picture.html
- https://www.youtube.com/watch?v=Qw-DD7-Xk98&list=PLliocbKHJNwvDp464ktZCsj8h7rXFBE8r&index=2
## 协作
### 创建工程
- fork别的项目
  https://github.com/azl397985856/leetcode
- 下载fork之后的自己的项目：
  git clone https://github.com/wangcy6/leetcode-1.git

说明：
> azl397985856/leetcode项目更新，wangcy6/leetcode-1.git 代码不会自动更新。

### 同步更新 


git remote -v

git remote add upstream https://github.com/azl397985856/leetcode.git

git remote add upstream https://github.com/pingcap-incubator/tidb-in-action.git

git fetch upstream



master分支一般用来发布稳定版本，dev分支（开发分支）用来发布开发版本。



git merge upstream/master   // 稳定版本分支

git merge upstream/daily-branch //开发版本分支

git merge upstream/wangcy







https://backlog.com/git-tutorial/cn/stepup/stepup2_7.html
https://happygitwithr.com/pull-tricky.html



### 提交代码
https://www.atlassian.com/git/tutorials/making-a-pull-request#how-it-works

Pull Request 是什么

>Pull Request 是一种通知机制。你修改了他人的代码，将你的修改通知原来的作者，希望他合并你的修
>Pull requests let you tell others about changes you've pushed to a branch in a repository on GitHub.

Pull Request 的流程:

- 切换分支
  git checkout -b daily-branch
  git branch
  
  ​	
  
- 添加代码 
  git add 2019-06-14.md 
  git commit  -am "#add"
  
- 提交代码

  git checkout daily-branch

  git push --set-upstream origin daily-branch

  git push --set-upstream origin wangcy6

  

​       git push origin daily-branch //分支提交到主干



- 重新登录GitHub并切换到work分支，点击compare&Pull Request



### 合并代码

#### 合并自己创建的工程



$ git checkout master
$ git merge hotfix

https://www.liaoxuefeng.com/wiki/896043488029600/900003767775424

### 查看提交状态

- git status 可以用来查看仓库的状态。
  撤销本地修改
   有三个状态，三个出来方案
   git checkout  --2019-06-14.md
   git reset HEAD 2019-06-14.md

```
git checkout -- filepathname    //  放弃某个文件
git checkout .                  // 放弃所有文件
```

Git用`<<<<<<<`，`=======`，`>>>>>>>`标记出不同分支的内容，我们修改如下后保存：





### 常见错误

#### git push  失败

fatal: The current branch daily-branch has no upstream branch.**
To push the current branch and set the remote as upstream, use

 git push --set-upstream origin daily-branch
 git push origin some-branch

### git pull --冲突

#### F1

- 描述

error: Your local changes to the following files would be overwritten by merge:
        promise/scheduling.go
        promise/work_balck_hole.go
Please, commit your changes or stash them before you can merge.





git pull
error: Pull is not possible because you have unmerged files.
hint: Fix them up in the work tree, and then use 'git add/rm <file>'
hint: as appropriate to mark resolution and make a commit.
fatal: Exiting because of an unresolved conflict.



Automatic merge failed; fix conflicts and then commit the result



- 强制覆盖本地文件

```
git status

git reset --hard
git reset --hard origin/master
git pull
git rm -rf xxx
```

- 临时修复 (stash)



```
git stash

git status
git commit 

git pull 
git stash pop

git log --oneline --graph
git log --graph
```

