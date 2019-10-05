
# **1、GDB 堆栈**

*：frmae=f backtrace=bt

命令                        |        解释
----------------------------|:-----------------------
bt                          | backtrace 显示堆栈
bt full                     | 显示每一帧的完整信息，包括了全局变量
set backtrace past-main on/off| 在main函数之后是否还用解析
f  n                        | frame f 1 选择栈帧
up                          | 上一帧
down                        | 下一帧
info f                      | 显示当前栈帧的信息
info locals                 | 显示局部变量
info args                   | 显示函数参数

# **2、工具使用**

反汇编 objdump -D -S test.elf