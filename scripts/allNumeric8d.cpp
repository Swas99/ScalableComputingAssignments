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
	string chars[] = { "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t",
						"u", "v", "w", "x", "y", "z"};

	int len = sizeof(chars)/sizeof(*chars);
	for(int i=0; i<len; i++)
		chars[i] = chars[i] - (32);


    for(char c1 = 0; c1<=9; c1++)
	{
		string x1 = to_string(c1);
		for(int c2 = 0;c2<=9; c2++)
		{
			string x2 = x1 + to_string(c2);
			for(int c3 = 0; c3<=9; c3++)
			{
				string x3 = x2 + to_string(c3);
				for(int c4 = 0; c4<=9; c4++)
				{
					string x4 = x3 + to_string(c4);
					for(int c5 = 0; c5<=9; c5++)
					{
						string x5 = x4 + to_string(c5);
						for(int c6 = 0; c6<=9; c6++)
						{
							string x6 = x5 + to_string(c6);
							for(int c7 = 0; c7<=9; c7++)
							{
								string x7 = x6 + to_string(c7);
								for(int c8 = 0; c8<=9; c8++)
								{
									string x8 = x7 + to_string(c8);
									data += x8 + "\n";
									count++;
									if(count%8000000 == 0)
									{
										string outputfile = 
										"C:\\Users\\Swastik\\Desktop\\MastersDegree_CS\\Semester_1\\ScalableComputing\\Stefen\\Assignments\\all_numeric_8d.lst";
										ofstream outfile;
									  	outfile.open(outputfile, std::ios_base::app);
									  	outfile << data;
									  	outfile.close();
									  	data = ""; 
									  	cout<<x8<<"              ";
									  	float progress = count/((double)27*27*27*27*27*27*27*27.0); 
									  	cout<<"progress = "<<progress<<endl;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if(data.length()>0)
	{
		string outputfile = "C:\\Users\\Swastik\\Desktop\\MastersDegree_CS\\Semester_1\\ScalableComputing\\Stefen\\Assignments\\all_numeric_8d.lst";
		ofstream outfile;
		outfile.open(outputfile, std::ios_base::app);
		outfile << data;
		outfile.close();
		cout<<"Progress = 100%"<<endl;
	}
	

   // string name = "C:\\Users\\Swastik\\Desktop\\MastersDegree_CS\\Semester_1\\ScalableComputing\\Stefen\\Assignments\\john180j1w\\run\\password.lst";
   // string name = "C:\\Users\\Swastik\\Desktop\\MastersDegree_CS\\Semester_1\\ScalableComputing\\Stefen\\Assignments\\all_lcase_8d";
	  //                  	std::ofstream out(name);
	  //                   out << data;
   //  					out.close();
   return 0; 
}
