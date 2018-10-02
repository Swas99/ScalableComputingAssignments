#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;


template<typename Out>

void split(const std::string &s, char delim, Out result) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        *(result++) = item;
    }
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}

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
	string data = "";
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
	    	if(str.length() <4 )
	    		continue;
	    	if(str.length() >17 )
	    		continue;
	    	
    		replaceAll( str, "\n", "");
    		replaceAll( str, "\r", "");
	    	if(str.length() <4 )
	    		continue;
	    	if(str.length() >15 )
	    		continue;

	    		data += str + "\n";
	            row_counter++; 
	            count++;
				if(count%10000000 == 0)
				{
					string outputfile = 
					"C:\\Users\\Swastik\\Desktop\\MastersDegree_CS\\Semester_1\\ScalableComputing\\Stefen\\Assignments\\refined_wordlist.lst";
					ofstream outfile;
				  	outfile.open(outputfile, std::ios_base::app);
				  	outfile << data;
				  	outfile.close();
				  	data = ""; 
				  	cout<<"progress = "<<count<<endl;
				}
	    }
	long count = 0;
	if(data.length()>0)
	{
		string outputfile = "C:\\Users\\Swastik\\Desktop\\MastersDegree_CS\\Semester_1\\ScalableComputing\\Stefen\\Assignments\\refined_wordlist.lst";
		ofstream outfile;
		outfile.open(outputfile, std::ios_base::app);
		outfile << data;
		outfile.close();
		cout<<"Progress = 100%"<<endl;
	}
   return 0; 
}
