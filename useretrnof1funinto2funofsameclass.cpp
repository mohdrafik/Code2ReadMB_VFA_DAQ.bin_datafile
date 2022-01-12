//#include<iostream>
#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include <bitset>
//#include<bintohex_command.h>
using namespace std;

/*
class sameclass{

int a,b,c;

public:
sameclass(){}
sameclass(int x1,int x2,int x3)
{ a=x1; 
	b=x2;
	c = x3;
}
*/

int fun1(int a, int b)
{ 
	return a+b;
}
int fun2(){ 
	int sum;
sum = fun1(1,2) + 5; //this->A::a();
return sum; 
}

//};

int main()
{

int x=1,y=2,z=3;

//sameclass sc(1,2,3);
//sameclass sc1;


//sc.fun1(x,y);
cout<<"result of fun1 3 :"<<fun1(x,y)<<endl;
//sc.fun2(z);
cout<<"result of fun1 6 :"<<fun2()<<endl;


return 0;
}