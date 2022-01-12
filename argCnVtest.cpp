#include <iostream>
//#include <string>
#include <string.h>
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
int i;

ofstream myfile(argv[1],ios::out);
if(myfile.is_open())
cout<<"file is created\n"; 

//cout<<"Total Number of arguments in the Command line:"<<argc<<endl;
printf("Total Number of arguments in the Command line: %d\n",argc );

   
for(i =0; i<argc ; i++)
	{
 		printf("argument number:%d" " argument value passed : %s\n",i+1,argv[i]);
 		//cout<< "argument number:"<<i+1<< "  argument value passed :"<<argv[i]<<endl;

     myfile<< "argument number:"<<i+1<< "  argument value passed :"<<argv[i]<<endl;
   	}


myfile.close();

return 0;

}