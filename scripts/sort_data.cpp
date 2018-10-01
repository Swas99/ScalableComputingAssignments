#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

template<typename Out>

void split(const std::string &s, char delim, Out result) {
    std::stringstream ss(s);
    std::string item;
    while (getline(ss, item, delim)) {
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

	string files[] = 
	{ 
		"C:\\Users\\Swastik\\Desktop\\99"
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
    		// replaceAll( str, ":", " ");
    		// cracked_hashes.push_back(str); 
    		cracked_hashes.push_back((split(str, ':')[1])); 
            row_counter++;  
	    }
	}

    sort(cracked_hashes.begin(), cracked_hashes.end()); 
	for(int i = 0; i< cracked_hashes.size(); i++)
		data +=  cracked_hashes[i] + "\n";

	string name = "C:\\Users\\Swastik\\Desktop\\mySortedFile";
   	std::ofstream out(name);
    out << data;
	out.close();
	cout<<data<<endl<<row_counter<<endl;
   return 0; 
} 
