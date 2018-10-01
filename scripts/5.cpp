#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <string>
#include <sstream>
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

/* Driver program to test above function */
int main(void) 
{ 

	string broken_hashes[] = 
	{ 
		"C:\\Users\\Swastik\\Desktop\\MastersDegree_CS\\Semester_1\\ScalableComputing\\Stefen\\Assignments\\hashes.broken",
		// "C:\\Users\\Swastik\\Desktop\\MastersDegree_CS\\Semester_1\\ScalableComputing\\Stefen\\Assignments\\john180j1w8\\run",
		// "C:\\Users\\Swastik\\Desktop\\MastersDegree_CS\\Semester_1\\ScalableComputing\\Stefen\\Assignments\\john180j1w8\\run",
	};
	string all_hashes[] = 
	{ 
		"C:\\Users\\Swastik\\Desktop\\MastersDegree_CS\\Semester_1\\ScalableComputing\\Stefen\\Assignments\\hashes_all.pot",
		// "C:\\Users\\Swastik\\Desktop\\MastersDegree_CS\\Semester_1\\ScalableComputing\\Stefen\\Assignments\\john180j1w8\\run",
		// "C:\\Users\\Swastik\\Desktop\\MastersDegree_CS\\Semester_1\\ScalableComputing\\Stefen\\Assignments\\john180j1w8\\run",
	};
    // std::ifstream file("C:\\Users\\Swastik\\Desktop\\MastersDegree_CS\\Semester_1\\ScalableComputing\\Stefen\\Assignments\\passdb.txt");
	string unbroken_hashes = "C:\\Users\\Swastik\\Desktop\\MastersDegree_CS\\Semester_1\\ScalableComputing\\Stefen\\Assignments\\hashes_unbroken";
	std::string str; 
	string uncrackedHashes = "";
	int len = sizeof(broken_hashes)/sizeof(*broken_hashes);
	for(int i = 0; i< len; i++)
	{
		fstream file(broken_hashes[i]);
	    int row_counter;
		int filenumber = 1;
	    row_counter = 0;
		vector<string> cracked_hashes =  vector<string>();
	    while(std::getline(file, str))
	    {
	    	cracked_hashes.push_back(split(str, ' ')[0]);
	            row_counter++; 
	    }

		string name = all_hashes[i];
		fstream file2(name);
		while(std::getline(file2, str))
	    {
	    	    string hash = str;
	    		bool found = (std::find(cracked_hashes.begin(), cracked_hashes.end(), hash) != cracked_hashes.end());
	    		if(!found)
	    			uncrackedHashes += hash + "\n";
	            row_counter++; 
	    }
	}

	   	std::ofstream out(unbroken_hashes);
	    out << uncrackedHashes;
		out.close();
   return 0; 
} 
