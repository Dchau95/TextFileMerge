/*
	Name: Homework 2 Problem 2
	Copyright: 
	Author: David Chau
	Student ID: 913319828
	Student email: dtchau@mail.sfsu.edu
	Date: 19/02/15 07:35
	Description: File I/Os and merging text files.
*/

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

/** @param Takes in a reference of file1 and file2
  * @return Nothing, since I'm just making a new third file for the merging part.
 */

void merge_file(fstream &file1, fstream &file2){
	string temp;
	string temp2;
	ofstream file3("mergednumbers.txt");
	
	getline(file1, temp);
	getline(file2, temp2);
	
	while(!file1.fail() && !file2.fail()){
		/* 
	  * This if else if statement is needed to get the length of the strings to be equivalent to each other.
	  * If the length of the strings were unequal, then it would, imaginarily, append a 0 to the end
	  * of the smaller string length to make the strings equivalent, however that would make the comparison off.
	  * For example, take a string of 9 and 10. The number 9 is intuitively smaller than the number 10, however
	  * their lengths are different, so C++ would append a 0 to 9, making it 90 and then 90 would be greater than 10
	  * throwing off the comparison. This may or may not be true, I figured this out through trial and error.
	  */
		
		if(temp.length()<temp2.length()){
			temp = "0"+temp;
		}else if(temp2.length()<temp.length()){
			temp2 = "0"+temp2;
		}
		if(temp<temp2){
			file3<<temp<<endl;
			getline(file1, temp);
		}
		else{
			file3<<temp2<<endl;
			getline(file2, temp2);
		}
	}
	
	//This block takes care of the rest of the numbers that didn't get added during the upper while loop.
	while(!file1.fail()){
		file3<<temp<<endl;
		getline(file1, temp);
	}
	while(!file2.fail()){
		file3<<temp2<<endl;
		getline(file2, temp2);
	}
	
	file3.close();
}


int main(){
	
	string file1, file2;
	cout<<"Please enter the names of the files you wish to merge: "<<endl;
	cin>>file1>>file2;
	fstream readFile1, readFile2;
	
	readFile1.open(file1);
	readFile2.open(file2);
	if(readFile1.fail() || readFile2.fail()){
		cerr<<"This did not open correctly. Ending program now."<<endl;
		return 1;
	}
	
	merge_file(readFile1, readFile2);
	cout<<"Your merged file is under the name of mergednumbers.txt."<<endl;
	readFile1.close();
	readFile2.close();
	
	return 0;
}
