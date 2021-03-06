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

	string source[] = { "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z" };
  
	int len = sizeof(source)/sizeof(*source);
	
	long long count = 0;
	long long totalCombo = len * len * len * len * len;
	long long batchSize = totalCombo/200;
	string data = "";
	for(int c1 = 0; c1<len; c1++)
	{
		string x1 = source[c1];
		for(int c2 = 0; c2<len; c2++)
		{
			string x2 = x1 + source[c2];
			for(int c3 = 0; c3<len; c3++)
			{
				string x3 = x2 + source[c3];
				for(int c4 = 0; c4<len; c4++)
				{
					string x4 = x3 + source[c4];
					for(int c5 = 0; c5<len; c5++)
					{
						string x5 = x4 + source[c5];
						data += x5 + "\n";
						count++;
						if(count%batchSize == 0)
						{
							double progress = count * 100.0 / totalCombo;
							cout<<"Progress = "<<progress<<"%"<<endl;
							string outputfile = 
							"D:\\cygwin64\\home\\sahus\\5d_words";
							ofstream outfile;
							outfile.open(outputfile, std::ios_base::app);
							outfile << data;
							outfile.close();
							data = "";
						}
					} 
				} 
			} 
		} 
	} 
	if(data.length()>0)
	{
		cout<<"Progress = "<<100<<"%"<<endl;
		string outputfile = 
		"D:\\cygwin64\\home\\sahus\\5d_words";
		ofstream outfile;
		outfile.open(outputfile, std::ios_base::app);
		outfile << data;
		outfile.close();
	}
   return 0; 
} 
 