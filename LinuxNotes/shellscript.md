# <B><Center> Shell脚本学习总结 </Center></B>      


1. if等需要条件判断的地方：  
    1.1  [] :是test命令的等价，因此<,>,=,==是按照字符串来比较的，数字的比较使用lt,ge等  
    1.2 [[]]：是[]的增强，可以使用正则表达式  
    1.3  (()) 其中可以使用逻辑运算符，>, <等

2. 

### grep匹配多个条件
    grep -E "fail|error"

### 查看文件，跟随变化
    tail -f xx.log

### 创建父目录
    mkdir -p xx/xxx

### shell变量运算
    num=$(($num + 4))










