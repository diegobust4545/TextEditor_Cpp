// Diego Bustamante
// Section A
// Partners: Shane Chamberlain
// Sources:
// - http://www.cplusplus.com/reference/string/string/


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ios>
using namespace std;

void readFile();
void printCommands();


int main(){
	readFile();
	return 0;
};

void printCommands(){
	cout << "The Editing commands are: \n";
	cout << "L      :Determine the length of the current line\n";
	cout << "P str  :Find the position (from 0) of the string str\n";
	cout << "I str  :Insert string str\n";
	cout << "D p n  :Delete n characters beginning at position p\n";
	cout << "R str  :Replace substring str with another string\n";
	cout << "N      :Get the next line of text\n";
	cout << "Q      :quit editing\n";
	cout << " Enter an editing command following each prompt >\n\n";
}


void readFile(){
	int count = 0;
	string file;
	string line;
	string lineTemp;
	string command;
	vector<string> vec(4);
	cout << "Please enter the input file: " << endl;
	cin >> file;
	cin.ignore();
	ifstream myfile(file);
	string word = file + ".out";
	const char *reFile = word.c_str();
	std::remove(reFile);
	bool quit = true;
	try{
		if (myfile){
			printCommands();
			while (getline(myfile,line)){
				lineTemp = line;
	     	 	if (quit == true){
		     	 	cout << line << '\n';
		     	 	


		     	 	cout  <<"> ";
		     	 	getline(cin,command);
		     	 }

				
	     	 	while(command[0]!='N' && quit){

	     	 		if (command[0] == 'L')
	     	 		{
	  
	     	 			cout << "String length is: " << lineTemp.size() << endl;
	     	 		}
	     	 		else if(command[0] == 'P'){
	     	 			string sub = command.substr(2);
	     	 			int pos;
	     	 			pos = lineTemp.find(sub);
	     	 			pos = pos + 1;
	     	 			cout << "Position: "<< pos << endl;
	     	 		}
	     	 		else if(command[0] == 'I'){
	     	 			string firSpl;
	     	 			string secSpl;
	     	 			string sub = command.substr(2);
	     	 			int index;
	     	 			cout << "Insert Where?: " << endl;
	     	 			cin>>index;
	     	 			cin.ignore();						index = index - 1;
						if(index>lineTemp.size()||index<0){
	     	 				cout << "Index Out Of Bounds" << endl;
	     	 			}
	     	 			else if(index == lineTemp.size()){
	     	 				lineTemp = lineTemp+sub;
	     	 				cout << lineTemp << endl;
	     	 			}
	     	 			else{
	     	 				firSpl = lineTemp.substr(0,index);
	     	 				secSpl = lineTemp.substr(index);
	     	 				lineTemp = firSpl+sub+secSpl;
	     	 				cout << lineTemp << endl;
	     	 			}
					
	  
						//cout << endl;
	     	 		}
	     	 		else if(command[0] == 'D'){
	     	 			string firSpl;
	     	 			string secSpl;
	     	 			int pos1 = command[2];
	     	 			pos1 = pos1 - 48;
	     	 			int shift = command[4];
	     	 			shift = shift - 48;
	     	 			int temp;
	     	 			if(pos1>lineTemp.size()||pos1<1){
	     	 				cout << "Index Out Of Bounds" << endl;
	     	 			}
	     	 			else if(pos1 == 1){
	     	 				temp = (pos1+shift-1);
	     	 				if(temp>lineTemp.size()){
	     	 					temp = lineTemp.size();
	     	 				}
	     	 				lineTemp = lineTemp.substr(temp);
	     	 			}
	     	 			else{
	     	 				firSpl = lineTemp.substr(0, pos1-1);
	     	 				secSpl = lineTemp.substr((pos1-1)+shift);
	     	 				lineTemp = firSpl + secSpl;
	     	 			}
	     	 			cout << lineTemp << endl;
	     	 		}
	     	 		else if(command[0] == 'R'){
	     	 			string replaceStr;
	     	 			string sub = command.substr(2);
	     	 			line = lineTemp;
	     	 			int c1 = line.find(sub);
	     	 			int c2 = sub.size();
	     	 			cout<<"With What?" << endl;
	     	 			cin >> replaceStr;
	     	 			cin.ignore();
	     	 			if(c1 > line.size()){
	     	 				cout << "Not found" << endl;
	     	 			}
	     	 			else if (c1 == 0){
	     	 				line = replaceStr+line.substr(c2);
	     	 			}
	     	 			else{
	     	 				string str1 = line.substr(0, c1);
	     	 				string str2 = line.substr(c1 + c2);
	     	 				line = str1 + replaceStr + str2;
	     	 			}
	     	 			lineTemp = line;
	     	 			cout << line << endl;
	     	 			
	     	 		}
	     	 		else if (command[0] == 'Q'){
	     	 			quit = false;
	     	 			break;
	     	 		}
	     	 		
	     	 		else{	
	     	 			cout << "Please insert valid command.\n"; 
	     	 		}
	     	 		if(quit == true){
	     	 			cout <<"> ";
		     	 		getline(cin,command);
	     	 		}
	     	 		
	     	 	}
	     	 	if (command[0] == 'N' || command == "Q"){
					ofstream myfile;
					myfile.open (file+".out",ios_base::app);
					myfile << lineTemp;
					myfile << "\r\n";
	     	 	}

	     	 	vec[count] = lineTemp;
	     	 	count++;
	    	}
	    	cout << "********** Editing is Complete ************\n";
	    }
	    else{
	    	cout << "No File Detected.\n"; 
	    }
	}
	catch(int e){
		cout << "Catch";
	}
}