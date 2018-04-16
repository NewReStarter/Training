/*
  dp [i ] [ j]    ->    dp [ i - 1] [ j  - 1]   // CHANGE
                  ->    dp [ i ] [ j - 1 ]       //  INSERT
                  ->    dp [ i - 1 ] [ j ]       //  DELETE
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
const int N = 25;
const int INF = (1<<23);

char a[100], b[100];
int dp[100][100], op[100][100];
void print(int i, int j) 
{
    if(i == 0 && j == 0)    return;
    
    if(op[i][j] == 1)
        print(i-1, j-1);
    else if(op[i][j] == 2) 
    {
        print(i-1, j);
        printf("D%c%02d", a[i-1], j+1);
    }
    else if(op[i][j] == 3) 
    {
        print(i, j-1);
        printf("I%c%02d", b[j-1], j);
    } 
    else 
    {
        print(i-1, j-1);
        printf("C%c%02d", b[j-1], j);
    }

}
int main() 
{
    int i, j;
    while(scanf("%s",a)) 
    {
        if(a[0]=='#') break;
        scanf("%s",b);
        memset(dp, 23, sizeof(dp));
        int len1 = strlen(a), len2 = strlen(b);
        dp[0][0] = 0;

        for(i = 0; i <= len1; i++) 
            for(j = 0; j <= len2; j++) {
                if(a[i] == b[j] && dp[i+1][j+1] > dp[i][j]) 
                    dp[i+1][j+1] = dp[i][j], op[i+1][j+1] = 1;
                if(dp[i+1][j] > dp[i][j]+1) 
                    dp[i+1][j] = dp[i][j]+1, op[i+1][j] = 2;
                if(dp[i][j+1] > dp[i][j]+1) 
                    dp[i][j+1] = dp[i][j]+1, op[i][j+1] = 3;
                if(dp[i+1][j+1] > dp[i][j]+1) 
                    dp[i+1][j+1] = dp[i][j]+1, op[i+1][j+1] = 4;
            }
        
        print(len1, len2);
        puts("E");
    }
    return 0;
}