# 题解

hmmmmm 这道题属于能看出答案但不想写那种TAT。感觉没什么美感，试了下网上流传的位运算版本然后WA了。简单的来说就是求一个布尔表达式的值是否在几个未知数都不确定的情况下都为真。其实给的条件都是可以推到出得，在学离散的时候学过。给了以后不过更轻松。这种字符串表达式求值的题都是3391第二周讲的那种先压栈遇到符号pop出来算的思路

怎么模拟一个表达式在几个参数都可变化时的值呢。直接的想法是：对于一个表达式我们可以转化成一个我们已知的表达式再由这个表达式求出值。但这道题这样想就黑了，一方面离散不是很扎实，另一方面确实很难推全。又因为是真假值变化，2^5就能枚举完。

这样以后剩下的都是dirty work了，哪天闲下来可以锻炼下自己快速写完的能力。

Tautology 这个词很有年代感，促使我重新学下数学。

明天开始写学校oj作业了，两周没写了。