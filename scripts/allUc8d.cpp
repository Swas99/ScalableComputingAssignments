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


    for(char c1 = 'a'; c1<='z'; c1++)
	{
		string x1 = chars[c1-'a'];
		for(int c2 = 'a';c2<='z'; c2++)
		{
			string x2 = x1 + chars[c2-'a'];
			for(int c3 = 'a'; c3<='z'; c3++)
			{
				string x3 = x2 + chars[c3-'a'];
				for(int c4 = 'a'; c4<='z'; c4++)
				{
					string x4 = x3 + chars[c4-'a'];
					for(int c5 = 'a'; c5<='z'; c5++)
					{
						string x5 = x4 + chars[c5-'a'];
						for(int c6 = 'a'; c6<='z'; c6++)
						{
							string x6 = x5 + chars[c6-'a'];
							for(int c7 = 'a'; c7<='z'; c7++)
							{
								string x7 = x6 + chars[c7-'a'];
								for(int c8 = 'a'; c8<='z'; c8++)
								{
									string x8 = x7 + chars[c8-'a'];
									data += x8 + "\n";
									count++;
									if(count%8000000 == 0)
									{
										string outputfile = 
										"C:\\Users\\Swastik\\Desktop\\MastersDegree_CS\\Semester_1\\ScalableComputing\\Stefen\\Assignments\\all_ucase_8d.lst";
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
		string outputfile = "C:\\Users\\Swastik\\Desktop\\MastersDegree_CS\\Semester_1\\ScalableComputing\\Stefen\\Assignments\\all_ucase_8d.lst";
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
