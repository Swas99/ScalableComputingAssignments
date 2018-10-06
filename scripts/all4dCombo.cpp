#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;



/* Driver program to test above function */
int main(void) 
{ 
	string data = "";

   //Numbers
   // for(int i = 0; i<=99999; i++)
   // {
   // 		string x = to_string(i);
   // 		while(x.length() < 5)
   // 			x = "0" + x;

   // 		data += x + "\n";
   // }

	long count = 0;
	string chars[] = { "!", "$", ".", "/", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "@", "A", "B", "C", "E", "H", "L", "O", "R", "S", "T", 
	"V", "Y", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};

	int len = sizeof(chars)/sizeof(*chars);

	long combinations = len * len * len * len;
	// cout<<"4:-> "<< combinations<<endl;
	// cout<<"5:-> "<<combinations * len<<endl;
	// cout<<"6:-> "<<combinations * len * len<<endl;

// 4:-> 7890481
// 5:-> 418195493
// 6:-> 22164361129
	long checkpoint = combinations/5;
    for(char c1 = 0; c1<len; c1++)
	{
		string x1 = chars[c1];
		for(int c2 = 0;c2<len; c2++)
		{
			string x2 = x1 + chars[c2];
			for(int c3 = 0; c3<len; c3++)
			{
				string x3 = x2 + chars[c3];
				for(int c4 = 0; c4<len; c4++)
				{
					count++;
					string x4 = x3 + chars[c4]; 
					data += x4 + "\n";

					if(count%checkpoint == 0)
					{					
						string outputfile = 
						"C:\\Users\\Swastik\\Desktop\\MastersDegree_CS\\Semester_1\\ScalableComputing\\Stefen\\Assignments\\all_4d_words";
						ofstream outfile;
					  	outfile.open(outputfile, std::ios_base::app);
					  	outfile << data;
					  	outfile.close();
					  	// cout<<data<<"              ";
					  	data = ""; 
					  	double progress = (double)count/((double)combinations) * 100; 
					  	cout<<"progress = "<<progress<<"%"<<endl;

					}

				}
			}
		}
	}
	if(data.length()>0)
	{
		string outputfile = "C:\\Users\\Swastik\\Desktop\\MastersDegree_CS\\Semester_1\\ScalableComputing\\Stefen\\Assignments\\all_4d_words";
		ofstream outfile;
		outfile.open(outputfile, std::ios_base::app);
		outfile << data;
		outfile.close();
		cout<<"Progress = 100%"<<endl<<"Count = "<<count<<endl;
	}
	

   // string name = "C:\\Users\\Swastik\\Desktop\\MastersDegree_CS\\Semester_1\\ScalableComputing\\Stefen\\Assignments\\john180j1w\\run\\password.lst";
   // string name = "C:\\Users\\Swastik\\Desktop\\MastersDegree_CS\\Semester_1\\ScalableComputing\\Stefen\\Assignments\\all_lcase_8d";
	  //                  	std::ofstream out(name);
	  //                   out << data;
   //  					out.close();
   return 0; 
}
