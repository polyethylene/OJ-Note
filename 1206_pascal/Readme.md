# pascal

总体来说就是建两个栈，一个用来存储 begin 和 if
如果有 then 将 if 取出并压入另一个栈，
如果有 else 就将第二个栈中 if 取出，
如果有 end 就将 begin 取出
最后检查栈空即可