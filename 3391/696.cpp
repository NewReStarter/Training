#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;

ll gcd_euclidean(ll a, ll &x, ll b, ll &y) 
{
  if(b == 0) 
  {
    x = 1;
    y = 0;
    return a; 
  } 
  else 
  {
    ll c = gcd_euclidean(b, x, a%b, y);
    int q = x;
    x = y;
    y = q - (a/b)*y;
    return c;
  }
}

int main() 
{
  ll x, y, xstep, ystep, L;
  while(scanf("%lld%lld%lld%lld%lld", &x, &y, &xstep, &ystep, &L) != EOF) 
  {

    ll r, r1, r2;
    ll a = ystep - xstep, c;

    if(a > 0) 
    {
      a = ystep - xstep;
      c = x - y;
    } 
    else 
    {
      a = xstep - ystep;
      c = y - x;
    }

    ll gcd = gcd_euclidean(a,r1,L,r2);

    if( c % gcd == 0) 
    {
      r1 = r1*(c/gcd);
      r = L/gcd;

      printf("%lld\n", ( (r1 % r) + r) % r);
    } 
    else 
    {
      printf("Impossible\n");
    }
  }
  return 0;
}