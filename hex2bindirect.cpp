/*  
first I have to convert these things.
this is script to convert the hex value into the binary values.
getting the VFAT hit values in each channel in hexadecimal format. it will convert the hex value in the binary values.
*/

#include <bitset>
//#include "stdafx.h"
#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
//#include<bintohex_command.h>
using namespace std;

int main()
{
 
    string  l1;
    ifstream myfile("daqhex7dec_test.txt");
    ofstream myfilew1("daqbin7dec_test.txt",ios::out|ios::trunc);

  if(myfile.is_open())
    {
       //while(!myfile.eof())
        int count = 0;
 	while(getline(myfile, l1))
        {
		count = count+1;
           //getline(myfile, l1);
	   int MAXnum_char = l1.length();
      //cout<<"string length line by line: "<< count  <<"th :"<<maxnum_char<<endl;
      

  for(int i = 0; i<MAXnum_char; i++)
    {

     switch(l1[i])

        {
        case '0': myfilew1 << "0000"; break;
        case '1': myfilew1 << "0001"; break;
        case '2': myfilew1 << "0010"; break;
        case '3': myfilew1 << "0011"; break;
        case '4': myfilew1 << "0100"; break;
        case '5': myfilew1 << "0101"; break;
        case '6': myfilew1 << "0110"; break;
        case '7': myfilew1 << "0111"; break;
        case '8': myfilew1 << "1000"; break;
        case '9': myfilew1 << "1001"; break;
        case 'a': myfilew1 << "1010"; break; 
        case 'b': myfilew1 << "1011"; break;
        case 'c': myfilew1 << "1100"; break;
        case 'd': myfilew1 << "1101"; break;
        case 'e': myfilew1 << "1110"; break;
        case 'f': myfilew1 << "1111"; break;
        //case '\0': myfilew1 <<  " " ; break;
/* here in switch statement: a,b,c,d,e,f is taken small because these letters are small
  in the converted hex file(which is converted from binary DAQ to hex file directly by given command:).
  The command: od -An -vtx1 DAQ_20211207_153430.bin > myfilelllll.txt
*/
        }

    }

    myfilew1 << "\n";
        } 
         
    }
  else
      cout << "unable"<<endl;

  myfile.close();
  myfilew1.close();

 return 0;
}
