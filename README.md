# SSVM

## About this project
Hello guys, I feel honoured you starred/forked my project (yvm) before complete working well.
At the first [java impl version](https://github.com/racaljk/ssvm/tree/master), I hardly finished it,
but I realized it's inefficient and less thinking before coding, I have to use many redundant way to
do something.Now I consider rewriting it by cpp, and I have to say I am not sure whether previous 
version would stop developing.This time I want to make it possible to be used in a real working/industry
environment rather than a useless toy. In this version I have a good data structure design and
I found some traps in previous developing. I will avoid them and implemented with an efficient approach,
though it may take a long time. Anyway, to be expected.

## Top Modules Overview
+ `classfile` read `*.class` files from binary stream and do loading,linking,initializing sequentially
+ `performance` performance monitoring
+ `channel` provide a channel to interact with other processes
+ `gc` garbage collection
+ `runtime` runtime data structure representation
+ `infrastructure` as its name implies
+ `interpreter` code interpreter
+ `optimizer` if ssvm found some hot spot codes, the optimizer would transform them to machine-dependency codes
+ `test` test cases
+ `object` runtime generic object structure