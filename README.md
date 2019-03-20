# iHx

Love Hx.

2019.03.19

配置c编译 生成exe路径
tasks.json
"args": ["-g","${file}","-o","${fileDirname}/${fileBasenameNoExtension}.exe"]
最后一个参数对应生成exe路径，与launch.json的program项对应
"${fileDirname}/${fileBasenameNoExtension}.exe"与"${fileDirname}\\${fileBasenameNoExtension}.exe"作用相同

${workspaceFolder} :表示当前workspace文件夹路径，也即C:\Users\admin\Desktop\test
${workspaceRootFolderName}:表示workspace的文件夹名，也即test
${file}:文件自身的绝对路径，也即C:\Users\admin\Desktop\test\.vscode\launch.json
${relativeFile}:文件在workspace中的路径，也即.vscode\launch.json
${fileBasenameNoExtension}:当前文件的文件名，不带后缀，也即launch
${fileBasename}:当前文件的文件名，launch.json
${fileDirname}:文件所在的文件夹路径，也即C:\Users\admin\Desktop\test\.vscode
${fileExtname}:当前文件的后缀，也即.json
${lineNumber}:当前文件光标所在的行号
${env:PATH}:系统中的环境变量
${workspaceRoot} 当前打开的文件夹的绝对路径+文件夹的名字

launch.json
"program": "${workspaceRoot}\\a.exe",   // 将要进行调试的程序的路径
"args": [],                             // 程序调试时传递给程序的命令行参数，一般设为空即可
"cwd": "${workspaceRoot}",              // 调试程序时的工作目录，一般为${workspaceRoot}即代码所在目录

//去除linklist中的重复项两种方法，不知道哪种是对的
//第一个有bug 明天有空弄懂
linklist p = head;
while (p != NULL)
{
    linklist q = p->next;
    while (q != NULL)
    {
        if (q->data == p->data)
        {
            p->next = q->next;
            free(q);
        }
        else
        {
            q = q->next;
        }
    }
    p = p->next;
}
//这个正常 while条件没懂
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

python同时import两个包的时候可能会导致输出两次
import pandas
import numpy