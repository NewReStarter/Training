#include <iostream>
#include <stdio.h>
using namespace std;
char str[200];          //字符串
int sign[5];            //p,q,r,s,t中的数值
bool ans;               //最后的结果
int p;                  //字符串中的指针
void solve (int k);     //枚举p,q,r,s,t的值
bool cul (void);        //递归求表达式的真假
int main ()
{
    while (scanf ("%s",str)!=EOF)
    {
          if (str[0] == '0')
              break;
          ans = 1;
          solve (0);
          if (ans)
              printf ("tautology\n");
          else
              printf ("not\n");     
    }
    return 0;
}
void solve (int k)
{
     for (sign[k] = 0 ;sign[k] < 2 ;sign[k]++)
         if (k == 4)
         {
             p = -1;
             ans = ans && cul ();
             if (!ans)
                 return ;
         }
         else
             solve (k+1);
     return ;
}
bool cul (void)
{
     p++;
     if (str[p] == '\0')
          return false;
     else if (str[p] > 96)     //str[p]为小写字符
          return sign[str[p] - 112];
     else
     {
         switch (str[p])
         {
                case 'K':
                     return (cul () & cul ());
                case 'A':
                     return (cul () | cul ());
                case 'N':
                     return (!cul ());
                case 'C':
                     return (cul () <= cul ());
                case 'E':
                     return (cul () == cul ());
         }
     }
     return false;
}