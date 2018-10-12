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
	long long row_counter = 0;
	long long totalHashes = 0;
	vector<string> only_hashes =  vector<string>();
	vector<string> words =  vector<string>();
	long long wordsInRealUnix = 1212356397;
	string rawFilesPath = "C:\\Users\\Swastik\\Desktop\\MastersDegree_CS\\Semester_1\\ScalableComputing\\Stefen\\Assignments\\wordlist\\realuniq.lst";
	string outputFile = "C:\\Users\\Swastik\\Desktop\\MastersDegree_CS\\Semester_1\\ScalableComputing\\Stefen\\Assignments\\wordlist\\_realuniq_9d";
	// string rawFilesPath = "C:\\Users\\Swastik\\Desktop\\MastersDegree_CS\\Semester_1\\ScalableComputing\\Stefen\\Assignments\\wordlist\\passdb.txt"; 
	// string outputFile = "C:\\Users\\Swastik\\Desktop\\MastersDegree_CS\\Semester_1\\ScalableComputing\\Stefen\\Assignments\\wordlist\\_passdb_7d"; 
    // string chars[] = {
    // 	"!", "#", "$", "&", "(", ".", "/", "?", "@", "_", " ",
    //     "0", "1", "2", "3", "4", "5", "6", "7", "8", "9",
    //     "A", "B", "C", "E", "G", "H", "I", "K", "L", "M", "N", "O", "P", "R", "S", "T", "U", "V", "Y", 
    //     "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z" };
	char special[] = {
		'B', 'E', 'G', 'H', 'I', 'K', 'M', 'N', 'P', 'R', 'S', 'T', 'U', 'V', 'Y', 
		'!', '#', '$', '&', '(', '.', '/',  '?', '@', '_', ' ' 
	};

	char chars[] = { 
		'!', '#', '$', '&', '(', '.', '/',  '?', '@', '_', ' ',
		'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
		'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'K', 'L', 'M', 'N', 'O', 'P', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
		'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
	}; 

	int charHash[299];
	for(int i =0; i<299; i++)
		charHash[i] = 0;
	for(char x : chars)
		charHash[x] = 99;

	string fPath = rawFilesPath;
	fstream file(fPath);
	long lineNumber = 0;
	long prevCheckPoint = 1;
    while(std::getline(file, str))
    {
    	if(str.length() == 0)
    		continue;
    	lineNumber++;

    	replaceAll( str, "\n", "");
		replaceAll( str, "\r", "");

		bool found = (std::find(words.begin(), words.end(), str) != words.end());
		bool invalid = false;
		int charCount[299];
		for(int i =0; i<299; i++)
			charCount[i] = 0;
		for(int i = 0; i<str.length(); i++)
		{
			if(charHash[str[i]] != 99)
			{
				invalid = true;
				break;
			}
			charCount[str[i]]++;
		}
		if(invalid)
			continue;

		charCount['a'] = 0;
		for(char x : special)
		{
			// if(count(str.begin(), str.end(), x)>2)
			if(charCount[x]>2)
			{
				invalid = true;
				break;
			}
			charCount['a'] += charCount[x];
		}
		if(charCount['a']>3)
			invalid = true;



		if(found || invalid || str.length()!=9) 
			continue;

		totalHashes++;
		data += str + "\n";
		if(totalHashes%99999 == 0)
		{  
			ofstream outfile;
			outfile.open(outputFile, std::ios_base::app);
			outfile << data;
			outfile.close(); 
			data = "";
			cout<<"CheckPoint: "<<totalHashes<< "/" <<lineNumber<<endl;
		}
    } 
	if(data.length()>0)
	{  
		ofstream outfile;
		outfile.open(outputFile, std::ios_base::app);
		outfile << data;
		outfile.close(); 
	}
	cout<<"lineNumbers = "<<lineNumber<<endl;
	cout<<"totalHashes = "<<totalHashes;
	 
	 
	
   return 0; 
} 
