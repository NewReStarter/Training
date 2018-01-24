#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

struct person{
	string name;
	int dd;
	int mm;
	int yy;
};

person young;
person old;

bool cmp(person p1, person p2);

int main()
{
	int n;
	cin>>n;
	string str;
	int dd,mm,yy;
	cin>>young.name>>young.dd>>young.mm>>young.yy;
	old = young;
	for(int i = 2; i <= n; i++)
	{
		person tmp;
		cin>>tmp.name>>tmp.dd>>tmp.mm>>tmp.yy;
		old = cmp(old,tmp) ? old : tmp;
		young = cmp(tmp,young) ? young : tmp;
	}
	cout<<old.name<<endl;
	cout<<young.name<<endl;
	return 0;
}

bool cmp(person p1, person p2)
{
	if(p1.yy!=p2.yy)
		return p1.yy>p2.yy;
	else if(p1.mm!=p2.mm)
		return p1.mm>p2.mm;
	else
		return p1.dd>p2.dd;
}