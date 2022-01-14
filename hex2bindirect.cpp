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
   int no_rowsdatafile(char* inHexfilename);  
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
   int arr_data[row][col] = {0};
   int channelwse_totalCount[col] = {0};

//ofstream myarr_data("arr_data.txt",ios::out|ios::trunc);
ifstream myread(outfilename,ios::in); // give the argument file name :: ./a.out daqbin7dec_test.txt :: just like that in command terminal after compiling.
  //if ((myread.is_open())&(myarr_data.is_open()))
  if (myread.is_open())
   {
      int line_num = 0;
      while(getline(myread,l1)) 
          {          
          line_num = line_num + 1;
           // cout<<"line no: "<<line_num<<endl;

            for (int i = 0; i < col; i++)
              { 
                int j = line_num -1;
                stringstream ss;
                ss << l1[i];
                ss >> arr_data[j][i];
                channelwse_totalCount[i] = channelwse_totalCount[i]+ arr_data[j][i];
                //myarr_data << arr_data[j][i];

               //cout<<arr_data[j][i];
              }
              //myarr_data <<"\n";
             //cout<<endl;
           //cout<<"line no: and Total Rows:"<<line_num<<" "<<row<<endl;        
           if(line_num ==row)
             { break; } 
           }
//cout<<"arr_data elements ::::::::: "<<arr_data[2][127]<<", "<<arr_data[3][127]<<endl;
   }
 else
  {
    cout<<"file unable to open inside main\n";
  }

//myarr_data << channelwse_totalCount;  
myread.close();
//myarr_data.close();

//ifstream myarr_dataRead("arr_data.txt",ios::in);

//cout<<"arr_data elements ::::::::: "<<arr_data[2][127]<<", "<<arr_data[3][127]<<endl;

/*just for checking the number of col and rows */
cout<<"//printing the total hit information channelwise://"<<endl;

for(int j1 =0; j1 < col; j1++)
  {
    cout/*<<j1<<"th:"*/<<channelwse_totalCount[j1]<<",";
      
   }
    
 //int rows = sizeof(arr_data)/sizeof(arr_data[0]);
   // int cols = sizeof(arr_data[0])/sizeof(arr_data[0][0]);
    //cout<<rows<<" "<<cols<<endl;


//myarr_dataRead.close();
//cout<<"channelwse_totalCount:"<<endl;

/*
for(int j1 =0; j1 < col; j1++)
  {
    // channelwse_totalCount[j1]  = 0;
    for(int i1=0; i1<row; i1++)
     {
      channelwse_totalCount[j1] = channelwse_totalCount[j1] + arr_data[j1][i1];

     }
    cout<<channelwse_totalCount[j1]<<" ";
  } 
*/
  cout<<endl; 
  }



int main(int argc, char *argv[])  // argv[1] for input hexfilename // argv[2] for output binary hexfilename
{

hex2hitdata h2;

h2.hex2hitbitwise(argv[1],argv[2]);
cout<<"no of rows:"<<h2.no_rowsdatafile(argv[1])<<endl;
h2.outstreamhitfile2decichwse(argv[2],argv[1]);

return 0;
}