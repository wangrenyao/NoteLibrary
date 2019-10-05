# <B><Center> Shell脚本学习总结 </Center></B>      


1. if等需要条件判断的地方：  
    1.1  [] :是test命令的等价，因此<,>,=,==是按照字符串来比较的，数字的比较使用lt,ge等  
    1.2 [[]]：是[]的增强，可以使用正则表达式  
    1.3  (()) 其中可以使用逻辑运算符，>, <等

2. `if` 语句
    ```bash
    if [ $Index -eq 0 ]
    then
        #
    else
        #
    fi
    ```

3. `for` 语句
   ```bash
   for Index in (1...10)
   do
        #
   done

   for Index in (seq 1 10)
    do
        #
   done

   for ((i=1;i<10;i++))
    do
        #
   done

   for Item in `ls`
    do
        #
   done

   for Item in /proc/*
    do
        #
   done
   ```

4. `while` 语句
   ```bash
    while true
    do
        #
    done

    while [$Index -lo 5]
    do
        #
    done

    while read line
    do
        #
    done <<xx.log
   ```

5. `case` 语句
   ```bash
    case $Index in
    1)
    ;; #如果没有;;那么就是fall-through
    2)
    ;;
    *)
    ;;
    esac
   ```
6. `其他` 语句
   ```bash
   function TestFunc()
   {
       ###
   }

   break
   continue
   return
   ```

### grep匹配多个条件
    grep -E "fail|error"

### 查看文件，跟随变化
    tail -f xx.log

### 创建父目录
    mkdir -p xx/xxx

### shell变量运算
    num=$(($num + 4))

### 










