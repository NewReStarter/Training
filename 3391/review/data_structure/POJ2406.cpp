//给定一个字符串S，已知该串是由某串重复K次 连接得到的。
#include<cstdio>
#include<cstring>
const int N=1000000+5;
char s[N];
int next[N];
void get_next(char s[],int len)
{
    int i=0;
    int j=-1;
    next[0]=-1;
    while(i<=len)
    {
        if(j==-1||s[j]==s[i])
            next[++i]=++j;
        else
            j=next[j];
    }
}
int main()
{
    while(scanf("%s",s))
    {
        if(s[0]=='.')
            break;
        int len=strlen(s);
        get_next(s,len);
        int k=len-next[len];
        int ans;
        if(len%k==0)
            ans=len/k;
        else
            ans=1;
        printf("%d\n",ans);
    }
    return 0;
}