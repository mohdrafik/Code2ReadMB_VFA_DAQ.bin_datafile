/*  
getting the VFAT hit values in each channel in hexadecimal format. it will convert the hex value in the binary values.
/* here in switch statement: a,b,c,d,e,f is taken small because these letters are small
in the converted hex file(which is converted from binary DAQ to hex file directly by given command:).
The command: od -An -vtx1 DAQ_20211207_153430.bin > myfilelllll.txt
*/

#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include <bits/stdc++.h>
#define col 128

using namespace std;

class hex2hitdata  
{
string  l1;

public:
   void hex2hitbitwise(char* inHexfilename,char* outfilename); // outfilename is binary hit information file after processing the hex file.
   int no_rowsdatafile(char* inHexfilename);   // this function return total no of lines in inHexfilename(filename) 
   void outstreamhitfile2decichwse(char* outfilename,char* inHexfilename);


};

int hex2hitdata::no_rowsdatafile(char* inHexfilename)
    {

     //ifstream myfile("daqhex7dec_test.txt");
     ifstream myfile(inHexfilename);

        int count = 0;

        while(getline(myfile,l1))
        {
            count = count + 1;

        }

        myfile.close();
     return count;
    }

void hex2hitdata::hex2hitbitwise(char* inHexfilename , char* outfilename)
 {

  ifstream myfile(inHexfilename);
  ofstream myfilew1(outfilename,ios::out|ios::trunc);

  if(myfile.is_open())
    {
       //while(!myfile.eof())
    int count = 0;
    while(getline(myfile, l1))
        {
        count = count+1;
           
       int MAXnum_char = l1.length();
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
        
    }

    }
    myfilew1 << "\n";
        } 
         
    }
  else
  cout << "unable"<<endl;
  myfile.close();
  myfilew1.close();
}

void hex2hitdata::  outstreamhitfile2decichwse(char* outfilename,char* inHexfilename)
{
  int row = no_rowsdatafile(inHexfilename ) - 1;  
 
  /*    arr_data[row][col] = {0};  // for me creating problem of segementation solved by using file instead of array.  
  --->  Always Avoid huge size array 
  ---> generate segemntation error core dumped because of large memory at the run time.
  ---> instead of Array use file :save data in the file  for further processing use the file. 
*/
  int a_data;
   int channelwse_totalCount[col] = {0};

ofstream myarr_data("arr_data.csv",ios::out|ios::trunc);
ifstream myread(outfilename,ios::in); // give the argument file name :: ./a.out daqbin7dec_test.txt :: just like that in command terminal after compiling.
  //if ((myread.is_open())&(myarr_data.is_open()))
  if (myread.is_open())
   {
      int line_num = 0;
      while(getline(myread,l1)) 
          {          
          line_num = line_num + 1;
             if(line_num == 1)
                {
                  for(int i=0;i<col;i++) 
                    {
                      myarr_data<<"ch_"<<i<<",";
                    }
                  myarr_data<<"\n";
                }

              // cout<<"line no: "<<line_num<<endl;
            for (int i = 0; i < col; i++)
              { 
                //int j = line_num -1;
                stringstream ss;
                ss << l1[i];
                ss >> a_data;

                channelwse_totalCount[i] = channelwse_totalCount[i]+ a_data;
                myarr_data << a_data<<",";
              }
              myarr_data <<"\n";
             //cout<<"line no: and Total Rows:"<<line_num<<" "<<row<<endl;        
           if(line_num ==row)
             { break; } 
           }
   }
 else
  {
    cout<<"file unable to open inside main\n";
  }

ofstream mytotalCount("TotalcntChn_1row.txt",ios::out);
cout<<"//printing the total hit information channelwise://"<<endl;

for(int j1 =0; j1 < col; j1++)
  {
   cout<<channelwse_totalCount[j1]<<",";
   mytotalCount<<channelwse_totalCount[j1]<<" ";
  }
  cout<<endl;

  mytotalCount.close();
  myarr_data.close();
  myread.close();
   
  }



int main(int argc, char *argv[])  // argv[1] for input hexfilename // argv[2] for output binary hexfilename
{

hex2hitdata h2;
h2.hex2hitbitwise(argv[1],argv[2]);
cout<<"no of rows:"<<h2.no_rowsdatafile(argv[1])<<endl;
h2.outstreamhitfile2decichwse(argv[2],argv[1]);

return 0;
}
