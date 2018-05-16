// 求解匹配
#include <iostream>  
#include <cstring>  
#include <cstddef>  
#include <cstdio>  
#include <string>  
#include <algorithm>   
  
using namespace std;  
const int MAXN = 10001;  
int n,k;  
int rank[MAXN+1],tmp[MAXN+1];  
  
bool comp_sa(int i, int j)  
{  
    if(rank[i] != rank[j])   
        return rank[i] < rank[j];  
    int ri = i+k <= n? rank[i+k] : -1;  
    int rj = j+k <= n? rank[j+k] : -1;  
    return ri < rj;   
}  
  
void calc_sa(string &S, int *sa) //计算字符串S的后缀数组   
{  
    n = S.size();  
      
    //初始长度为1   
    for(int i = 0; i <= n; i++)  
    {  
        sa[i] = i;  
        rank[i] = i < n ? S[i] : -1;  
    }  
      
    for( k =1; k <= n; k *= 2)  
    {  
        sort(sa,sa+n+1,comp_sa);  
          
        //先在tmp中临时存储新计算的rank，再转存回rank中   
        tmp[sa[0]] = 0;  
        for(int i = 1; i <= n; i++)  
        {  
            tmp[sa[i]] = tmp[sa[i-1]] + (comp_sa(sa[i-1],sa[i]) ? 1: 0);  
        }  
        for(int i = 0; i <= n; i++)  
        {  
            rank[i] = tmp[i];  
        }  
    }  
}  
  
void SuffixArrayMatch(string &S, int *sa, string T)  
{  
    calc_sa(S,sa);  
    int lhs = 0, rhs = S.size();  
      
    //使用二分查找   
    while(rhs - lhs > 1)  
    {  
        int mid = (lhs + rhs)>>1;  
        int res = S.compare(sa[mid],T.size(),T);   
        if(res < 0)  
            lhs = mid;  
        else if(res == 0)   
        {  
            cout<<"match at: "<<sa[mid]<<endl;  
            lhs = mid;  
        }  
        else rhs = mid;  
    }  
}  
int main()  
{  
    string S = "abracadabra";  
    string T = "ab";  
    int *sa = new int[S.size()+1];  
    SuffixArrayMatch(S,sa,T);  
    delete [] sa;  
    sa = NULL;  
}  