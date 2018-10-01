#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;



void replaceAll(std::string& source, const std::string& from, const std::string& to)
{
    std::string newString;
    newString.reserve(source.length());  // avoids a few memory allocations

    std::string::size_type lastPos = 0;
    std::string::size_type findPos;

    while(std::string::npos != (findPos = source.find(from, lastPos)))
    {
        newString.append(source, lastPos, findPos - lastPos);
        newString += to;
        lastPos = findPos + from.length();
    }

    // Care for the rest after last occurrence
    newString += source.substr(lastPos);

    source.swap(newString);
}

/* Driver program to test above function */
int main(void) 
{ 

	string files[] = 
	{ 
		"C:\\Users\\Swastik\\Desktop\\MastersDegree_CS\\Semester_1\\ScalableComputing\\Stefen\\Assignments\\john180j1w\\run\\john.pot",
		"C:\\Users\\Swastik\\Desktop\\MastersDegree_CS\\Semester_1\\ScalableComputing\\Stefen\\Assignments\\john180j1w2\\run\\john.pot",
		"C:\\Users\\Swastik\\Desktop\\MastersDegree_CS\\Semester_1\\ScalableComputing\\Stefen\\Assignments\\john180j1w3\\run\\john.pot",
		"C:\\Users\\Swastik\\Desktop\\MastersDegree_CS\\Semester_1\\ScalableComputing\\Stefen\\Assignments\\john180j1w4\\run\\john.pot",
		"C:\\Users\\Swastik\\Desktop\\MastersDegree_CS\\Semester_1\\ScalableComputing\\Stefen\\Assignments\\john180j1w5\\run\\john.pot",
		"C:\\Users\\Swastik\\Desktop\\MastersDegree_CS\\Semester_1\\ScalableComputing\\Stefen\\Assignments\\john180j1w6\\run\\john.pot",
		"C:\\Users\\Swastik\\Desktop\\MastersDegree_CS\\Semester_1\\ScalableComputing\\Stefen\\Assignments\\john180j1w7\\run\\john.pot",
		"C:\\Users\\Swastik\\Desktop\\MastersDegree_CS\\Semester_1\\ScalableComputing\\Stefen\\Assignments\\john180j1w8\\run\\john.pot",
		"C:\\Users\\Swastik\\Desktop\\MastersDegree_CS\\Semester_1\\ScalableComputing\\Stefen\\Assignments\\john180j1w9\\run\\john.pot",
		"C:\\Users\\Swastik\\Desktop\\MastersDegree_CS\\Semester_1\\ScalableComputing\\Stefen\\Assignments\\john180j1w10\\run\\john.pot",
		"C:\\Users\\Swastik\\Desktop\\MastersDegree_CS\\Semester_1\\ScalableComputing\\Stefen\\Assignments\\john180j1w11\\run\\john.pot",
		"C:\\Users\\Swastik\\Desktop\\MastersDegree_CS\\Semester_1\\ScalableComputing\\Stefen\\Assignments\\john180j1w12\\run\\john.pot"
		
	};
    // std::ifstream file("C:\\Users\\Swastik\\Desktop\\MastersDegree_CS\\Semester_1\\ScalableComputing\\Stefen\\Assignments\\passdb.txt");

	std::string str = "";
	string data = "";
	vector<string> cracked_hashes =  vector<string>();
	int len = sizeof(files)/sizeof(*files);
	int row_counter = 0;
	for(int i = 0; i< len; i++)
	{
		fstream file(files[i]);
		int filenumber = 1;
	    while(std::getline(file, str))
	    {
	    	if(str.length() == 0)
	    		continue;
	    	
    		bool found = (std::find(cracked_hashes.begin(), cracked_hashes.end(), str) != cracked_hashes.end());
    		if(found)
    			continue;

    		cracked_hashes.push_back(str);
    		replaceAll( str, ":", " ");
            data +=  str + "\n";
    		// data += str + "\n";
            row_counter++; 
        //     if (row_counter > 100000) 
        //     {   
        //        		row_counter = 0;
        //        		string name = "C:\\cygwin64\\home\\Swastik\\data\\file_" + to_string(filenumber);
        //            	std::ofstream out(name);
        //             out << data;
					// out.close();
					// data = "";
					// cout<<filenumber++<<endl;
        //     }
	    }
	}    
	string name = "C:\\Users\\Swastik\\Desktop\\MastersDegree_CS\\Semester_1\\ScalableComputing\\Stefen\\Assignments\\hashes.broken";
   	std::ofstream out(name);
    out << data;
	out.close();
	cout<<data<<endl<<row_counter<<endl;
   return 0; 
} 
