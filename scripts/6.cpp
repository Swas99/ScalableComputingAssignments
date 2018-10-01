#include <iostream>
#include <fstream>
#include <string>
using namespace std;



/* Driver program to test above function */
int main(void) 
{ 

	string files[] = 
	{ 
		"C:\\Users\\Swastik\\Desktop\\MastersDegree_CS\\Semester_1\\ScalableComputing\\Stefen\\Assignments\\2_cracked"
	};
    // std::ifstream file("C:\\Users\\Swastik\\Desktop\\MastersDegree_CS\\Semester_1\\ScalableComputing\\Stefen\\Assignments\\passdb.txt");

	std::string str; 
	string data = "";
	int len = sizeof(files)/sizeof(*files);
	for(int i = 0; i< len; i++)
	{
		fstream file(files[i]);
	    int row_counter;
		int filenumber = 1;
	    row_counter = 0;
	    while(std::getline(file, str))
	    {
	    	if(str.length() <2 )
	    		continue;
	    	
	    		data += str + "\n";
	            row_counter++; 
	            if (row_counter > 45) 
	            {   
	               		row_counter = 0;
	               		string name = "C:\\cygwin64\\home\\Swastik\\data\\h" + to_string(filenumber);
	                   	std::ofstream out(name);
	                    out << data;
    					out.close();
    					data = "";
    					cout<<filenumber++<<endl;
	            }
	    }
	}
   return 0; 
}
