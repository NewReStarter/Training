# 题解

最开始的想法是暴力一个一个枚举检查是否满足条件，本地跑了之后发现TLE。

然后看了下题解，是用[1,2,3,4,5,6,7,8,9]一位数的第一层做初始节点BFS打表。此处需要证明这样的枚举不会打乱顺序。很显然衍生的1 -> [10,12,13,14,15,16,17,18,19] 和 2 -> [20,21,23,24,25,26,27,28,29]依次append在答案数组最后很显然不会打乱顺序。

----------

因此明显的想法是构造vaule和bool has_digit[10]的node

``` c++
struct node{
    int v;
    bool h[10];
}
```

-----------

题解利用的是位运算的性质来判是否有某一位数重复。
对于二进制的性质

& 当都是1时等于1

| 有一个是1时就等于1

因此初始化为

``` c++
 for(r=1;r<10;r++)
    po[r]=data(r,1<<r);
```
用一个int 记录 9位数是否存在。

当满足条件   （！s&(1<<i)） 即不存在重复数

append 对应数到末尾 对应的 二进制记录数据更新为 s|1<<i

