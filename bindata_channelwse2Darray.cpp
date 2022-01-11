#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include <bits/stdc++.h>
#define col 128

using namespace std;

int find_noRow(char *argv[1]);

int main(int argc, char *argv[])
{
 
  string line;  
  int row = find_noRow(argv); 
  row = row - 1;
  int arr_data[row][col] = {0};
  int channelwse_totalCount[col] = {0};

//ofstream myarr_data("arr_data.txt",ios::out|ios::trunc);
ifstream myread(argv[1],ios::in); // give the argument file name :: ./a.out daqbin7dec_test.txt :: just like that in command terminal after compiling.
  //if ((myread.is_open())&(myarr_data.is_open()))
  if (myread.is_open())
   {
      int line_num = 0;
      while(getline(myread,line)) 
          {          
          line_num = line_num + 1;
           // cout<<"line no: "<<line_num<<endl;

          	for (int i = 0; i < col; i++)
              { 
                int j = line_num -1;
                stringstream ss;
                ss << line[i];
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
 return 0;

}


int find_noRow(char *argv[1])
{
string line1; int row; 

//ifstream myread("daqbin7dec_test.txt",ios::in);
ifstream myread1(argv[1],ios::in); 

   if (myread1.is_open())
     {  row = 0;
       while(getline(myread1,line1))
          {
             row = row + 1;
          }
cout<<"total rows:"<<row<<endl;
    }
  else
    {
       cout<<"file unable to open for find_noRow\n";
    }
myread1.close();
return row;

}

