/* Protected Mode Hello World */
# .code16
# .global start
# start:
# cli #关闭中断
# #启动A20总线
# data32 addr32 lgdt gdtDesc #加载GDTR
# #启动保护模式
# #设置CR0的PE位（第0位）为1
# data32 ljmp $0x08, $start32 #⻓跳转切换至保护模式
# .code32
# start32:
# ... #初始化DS ES FS GS SS 初始化栈顶指针ESP
# pushl $13 # pushing the size to print into stack
# pushl $message # pushing the address of message into stack
# calll displayStr # calling the display function
# loop:
# jmp loop
# message:
# .string "Hello, World!\n\0"
# displayStr:
# movl 4(%esp), %ebx
# movl 8(%esp), %ecx
# movl $((80*5+0)*2), %edi
# movb $0x0c, %ah
# nextChar:
# movb (%ebx), %al
# movw %ax, %gs:(%edi)
# addl $2, %edi
# incl %ebx
# loopnz nextChar # loopnz decrease ecx by 1
# ret
# gdt:
# .word #GDT第一个表项必须为空
# .byte
# .word #代码段描述符
# .byte
# .word #数据段描述符
# .byte
# .word #视频段描述符
# .byte
# ...
# gdtDesc:
# .word (gdtDesc - gdt -1)
# .long gdt
