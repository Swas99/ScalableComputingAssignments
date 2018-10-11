#include <string.h>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <dirent.h>
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

struct mySorter
{
    inline bool operator() (const string& s1, const string& s2)
    {
    	// if(s1.length() == s2.length())
    	// 	return s1.compare(s2);
    	return s1.length() < s2.length();
    }
};

/* Driver program to test above function */
int main(void) 
{ 

	string str = "";
	string data = "";
	int row_counter = 0;
	int totalHashes = 0;
	vector<string> only_hashes =  vector<string>();
	vector<string> cracked_hashes =  vector<string>();
	string rawFilesPath = "C:\\Users\\Swastik\\Desktop\\MastersDegree_CS\\Semester_1\\ScalableComputing\\Stefen\\Assignments\\2_cracked_raw";
	string uncrackedPath = "C:\\Users\\Swastik\\Desktop\\MastersDegree_CS\\Semester_1\\ScalableComputing\\Stefen\\Assignments\\2_uncracked_hashes";
    string singleFilePath = "C:\\Users\\Swastik\\Desktop\\MastersDegree_CS\\Semester_1\\ScalableComputing\\Stefen\\Assignments\\2_cracked_single_file\\2.broken";
    string onlyPassFilePath = "C:\\Users\\Swastik\\Desktop\\MastersDegree_CS\\Semester_1\\ScalableComputing\\Stefen\\Assignments\\2_cracked_single_file\\onlyPass";
    string allCharInPassFile = "C:\\Users\\Swastik\\Desktop\\MastersDegree_CS\\Semester_1\\ScalableComputing\\Stefen\\Assignments\\2_cracked_single_file\\allChars";

	DIR *dir;
	struct dirent *ent; 
	dir = opendir (rawFilesPath.c_str());
   	while ((ent = readdir (dir)) != NULL)
    {
    	string fPath = rawFilesPath + "\\" + ent->d_name;
		fstream file(fPath);
		int lineNumber = 0;
	    while(std::getline(file, str))
	    {
	    	if(str.length() == 0)
	    		continue;
    		
	    	lineNumber++;
	    	replaceAll( str, "\n", "");
    		replaceAll( str, "\r", "");
    		replaceAll( str, ":", " ");
			bool found = (std::find(cracked_hashes.begin(), cracked_hashes.end(), str) != cracked_hashes.end());
			if(found)
				continue;
			totalHashes++;
			only_hashes.push_back(str.substr(0, str.find(" ")));
            cracked_hashes.push_back(str);
	    }
	    // cout<<"\nFile: "<<ent->d_name<<"\n#lines="<<lineNumber<<endl;
    }
  	closedir (dir);
	
	cout<<"\nTotal cracked= "<<cracked_hashes.size()<<" == "<<totalHashes<<endl<<endl;
	std::sort(cracked_hashes.begin(), cracked_hashes.end(),mySorter()); 
	std::sort(cracked_hashes.begin(), cracked_hashes.end());
	std::sort(cracked_hashes.begin(), cracked_hashes.end(),mySorter()); 
	for(string x : cracked_hashes)
		data += x + "\n";
   	std::ofstream out(singleFilePath);
    out << data;
	out.close();


	vector<string> passList  =  vector<string>();
	for(string x : cracked_hashes)
		passList.push_back(x.substr(x.find(" ")+1));
	std::sort(passList.begin(), passList.end(),mySorter()); 
	std::sort(passList.begin(), passList.end());
	std::sort(passList.begin(), passList.end(),mySorter()); 	
	data = "";
	for(string x : passList)
		data += x + "\n";
	std::ofstream out2(onlyPassFilePath);
    out2 << data;
	out2.close();

	char charMap[999];
	for(string x : passList)
		for(int i = 0; i<x.length(); i++)
			charMap[x[i]] = 99;
	string allChars = "";
	for(int i =0; i<999; i++)
		if(charMap[i] == 99)
		{
			char x = i;
			allChars += "\"" + string(1, x) + "\", "; 
		}
	std::ofstream out3(allCharInPassFile);
    out3 << allChars;
	out3.close();
	


	dir = opendir (uncrackedPath.c_str()); 
   	while ((ent = readdir (dir)) != NULL)
    {
		vector<string> raw_hashes =  vector<string>();
    	string fPath = uncrackedPath + "\\" + ent->d_name;
		fstream file(fPath);
		int hashCount = 0;
		int lineNumber = 0;
		data = "";
	    while(std::getline(file, str))
	    {
	    	if(str.length() == 0)
	    		continue;
    		
	    	lineNumber++;
	    	replaceAll( str, "\n", "");
    		replaceAll( str, "\r", "");
			bool found = (std::find(raw_hashes.begin(), raw_hashes.end(), str) != raw_hashes.end());
			bool found2 = (std::find(only_hashes.begin(), only_hashes.end(), str) != only_hashes.end());
			if(found || found2)
				continue;
			hashCount++; 
            raw_hashes.push_back(str);
	    }

	    if(lineNumber == 0)
	    	continue;
		std::sort(raw_hashes.begin(), raw_hashes.end(),mySorter()); 
		std::sort(raw_hashes.begin(), raw_hashes.end());
		std::sort(raw_hashes.begin(), raw_hashes.end(),mySorter()); 
		for(string x : raw_hashes)
			data += x + "\n"; 
		// cout<<data<<endl;
	    cout<<"File: "<<ent->d_name<<endl;
	    cout<<"Current Count/Previous Count = "<<hashCount<<"/"<<lineNumber<<endl<<endl;
	    std::ofstream out(fPath);
	    out << data;
		out.close();
    }
  	closedir (dir);
	
   return 0; 
} 
