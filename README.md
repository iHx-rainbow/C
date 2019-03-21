# iHx

## Love Hx.

### 2019.03.20

#### Markdown

#### 标题
>\# 一级标题  
>\## 二级标题  
>\### 三级标题  
>\#### 四级标题  
>\##### 五级标题  
>\###### 六级标题  
>
>一级标题  
>\===  
>二级标题  
>\---

#### 列表
>- 无序列表
>* 无序列表
>+ 无序列表
>1. 有序列表
>2. 数字后面的点只能是英文点
>5. 有序列表的序号是根据第一行列表的数字顺序来的

#### 引用
>这是一段引用文字
>>二级引用
>
#### 分割线
>***
>---
>___

#### 链接
>[Baidu](www.baidu.com '百度一下，你就知道')

>[link]:www.baidu.com "百度一下，你就知道"

>[Baidu][link]

>链接 [link]

><http://example.com/>

#### 图片
>![图片前面要写一个！](https://www.baidu.com/img/baidu_jgylogo3.gif)

>[pic]:https://www.baidu.com/img/baidu_jgylogo3.gif

>这是一张图![pic]

#### 代码段
>`这是一行代码`
>```java
>//这是一段代码
>int a;
>```

#### 文本样式
>*字体倾斜*
>_字体倾斜_  
>**字体加粗**
>__字体加粗__  
>~~字体删除~~

#### 表格
>| 商品 | 价格 | 数量 |
>| --- | ---: | :--: |
>| 手机 | \$460 | 5   |
>| 插头 |  \$10 | 12  |
>| 铅笔 |   \$1 | 234 |
>: 是对齐方向

#### 转义符
>\\  
>\---

### 2019.03.19

tasks.json  
配置gcc编译 控制生成exe路径  
`"args": ["-g","${file}","-o","${fileDirname}/${fileBasenameNoExtension}.exe"]`  
最后一个参数对应生成exe路径，与launch.json的program项对应  
`"${fileDirname}/${fileBasenameNoExtension}.exe"`  
与`"${fileDirname}\\${fileBasenameNoExtension}.exe"`作用相同  

>${workspaceFolder}:表示当前workspace文件夹路径，也即C:\Users\admin\Desktop\test  
>${workspaceRootFolderName}:表示workspace的文件夹名，也即test  
>${file}:文件自身的绝对路径，也即C:\Users\admin\Desktop\test\.vscode\launch.json  
>${relativeFile}:文件在workspace中的路径，也即.vscode\launch.json  
>${fileBasenameNoExtension}:当前文件的文件名，不带后缀，也即launch  
>${fileBasename}:当前文件的文件名，launch.json  
>${fileDirname}:文件所在的文件夹路径，也即C:\Users\admin\Desktop\test\.vscode  
>${fileExtname}:当前文件的后缀，也即.json  
>${lineNumber}:当前文件光标所在的行号  
>${env:PATH}:系统中的环境变量  
>${workspaceRoot}:当前打开的文件夹的绝对路径+文件夹的名字  

launch.json
```json
"program": "${workspaceRoot}\\a.exe",   // 将要进行调试的程序的路径
"args": [],                             // 程序调试时传递给程序的命令行参数，一般设为空即可 
"cwd": "${workspaceRoot}",              // 调试程序时的工作目录，一般为${workspaceRoot}即代码所在目录
```

```c
//去除linklist中的重复项方法
//第一种调试出错 有空找bug
linklist p = head;
while (p != NULL)
{
    linklist q = p->next;
    while (q != NULL)
    {
        if (q->data == p->data)
        {
            p->next = q->next;
            free(q);    //free的问题
        }
        else
        {
            q = q->next;
        }
    }
    p = p->next;
}

//第二种调试正常 while条件还没懂
linklist p = head;
while (p != NULL)
{
    linklist q = head;
    while (q->next != p && q->next != NULL)
    {
        if (q->next->data == p->data)
        {
            q->next = q->next->next;
        }
        else
        {
            q = q->next;
        }
    }
    p = p->next;
}
```

python同时import两个包的时候可能会导致输出两次
```python
import pandas
import numpy
```