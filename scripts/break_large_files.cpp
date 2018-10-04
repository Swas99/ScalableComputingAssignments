#include <iostream>
#include <fstream>
#include <string>
using namespace std;



/* Driver program to test above function */
int main(void) 
{ 

	string files[] = 
	{ 
		"D:\\cygwin64\\home\\sahus\\5d_words"
	}; 
	string source[] = { "!", "$", "&", "(", ".", "/", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "?", "@", "A", "B", "C", "E", "G", "H", "K", "L", "M", "N", "O", "P", "R", "S", "T", "U", "V", "Y", "_", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z" };
	int len = sizeof(source)/sizeof(*source);
	
	std::string str; 
	string data = "";
	long filenumber = 1;
	long row_counter = 0;
	long row_lim = 80999999;
	long long totalCombo = len * len * len * len * len;
	long long batchSize = totalCombo/200;
	len = sizeof(files)/sizeof(*files);
	for(int i = 0; i< len; i++)
	{
		fstream file(files[i]);
	    while(std::getline(file, str))
	    { 
	    		data += str + "\n";
	            row_counter++; 
	            if (row_counter % row_lim == 0) 
	            {   
	               		string name = "D:\\cygwin64\\home\\sahus\\5d_words_set_" + to_string(filenumber);
	                   	std::ofstream out(name);
	                    out << data;
    					out.close();
    					data = "";
    					cout<<filenumber++<<endl;
	            }
				
				if(row_counter%batchSize == 0)
				{							
					double progress = row_counter * 100.0 / totalCombo;
					cout<<"Progress = "<<progress<<"%"<<"\tCurrent file:"<<filenumber<<endl;
				}
				
	    }
	}
	if (data.length() > 0) 
	{    
			string name = "D:\\cygwin64\\home\\sahus\\5d_words_set_" + to_string(filenumber);
			std::ofstream out(name);
			out << data;
			out.close();
			data = "";
			cout<<filenumber++<<endl<<"Total rows = "<<row_counter;
	}
   return 0; 
}
