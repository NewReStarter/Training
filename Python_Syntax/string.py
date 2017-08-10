str = 'Monty Carlo'

str[0:5]  #'Monty'
str[6:11] #'Carlo'

#str[x:y] = for(i=x;i<y;i++)
#str[:y] = for(i=0;i<y;i++)
#str[x:] = for(int i=x; i<=len; i++)

>>> word = 'banana'
>>> index = word.find('a')
>>> print index
1

>>> word.find('na')
2

>>> word.find('na', 3)
4

>>> name = 'bob'
>>> name.find('b', 1, 2)
-1

>>> fruit = 'banana'
>>> fruit[0:5:2]
'bnn'
#A step size of -1 goes through the word backwards, so the slice [::-1] generates a reversed string.
