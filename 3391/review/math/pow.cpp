#include<iostream>
using namespace std;

int pow2(int a,int b){
    int r=1,base=a;
    while(b!=0){
    if(b%2) r*=base;
    base*=base;
    b/=2;
    }
    return r;
}

int pow4(int a,int b){
  int r=1,base=a;
  while(b){
    if(b&1) r*=base;
    base*=base;
    b>>=1;
  }
  return r;
}

int main()
{
	cout<<pow2(2,4)<<endl;
	cout<<pow4(2,4)<<endl;
	return 0;
}