/*
 * functionstocomplete.cpp
 *
 *  Created on: September 26, 2019
 *      Author: Tyler Warburton
 */



#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ostream>


#include "constants.h"
#include "utilities.h"

using namespace std;



//define a structure to track words and number of times they occur
struct entry{
	string word;
	int numberOfOccurences;
};
//add a global array of entry structs (global to this file)
entry entryarray[100] = {};
//add variable to keep track of next available slot in array
int currentpos = 0;
//TODO define all functions in header file




//zero out array that tracks words and their occurrences
//void clearArray();
void clearArray()
{
	currentpos = 0;
}

//how many unique words are in array
//int getArraySize();
 int getArraySize()
 {
	 //maybe plus or minus one here
 return currentpos;
 }

//get data at a particular location
//std::string getArrayWordAt(int i);
std::string getArrayWordAt(int i)
{
  return entryarray[i].word;
}

//int getArrayWord_NumbOccur_At(int i);
int getArrayWord_NumbOccur_At(int i)
{
return entryarray[i].numberOfOccurences;
}

/*Keep track of how many times each token seen*/
//void processToken(std::string &token);
void processToken(std::string &token)
{
	bool inlist = false;
	strip_unwanted_chars(token);
	if(token != ""){
		for(int x = 0; x < currentpos; x++){
			string tokenHolder = token;
			string entryarrayHolder = entryarray[x].word;
			toUpper(tokenHolder);
			toUpper(entryarrayHolder);
			 if((tokenHolder.compare(entryarrayHolder)) == 0){
				 entryarray[x].numberOfOccurences = entryarray[x].numberOfOccurences + 1;
				 //cout << "Increased (" + entryarray[x].word + ") By one \n";
				 inlist = true;
			 }

		}
		if (!inlist)
					 {
						entryarray[currentpos].word = token;
						entryarray[currentpos].numberOfOccurences = 1;
						//cout << "Added (" + entryarray[currentpos].word + ") TO list \n";
						currentpos ++;
					 }
	}
//No return bc void
}

/*take 1 line and extract all the tokens from it
feed each token to processToken for recording*/
//void processLine(std::string &myString);
void processLine(std::string &myString)
{
	stringstream ss(myString);
	string word;
	while (getline(ss, word, ' ')){
		processToken(word);
	}
//NO return bc void
}

/*loop through whole file, one line at a time
 * call processLine on each line
 * returns false: myfstream is not open
 *         true: otherwise*/
//bool processFile(std::fstream &myfstream);
bool processFile(std::fstream &myfstream)
{
//TODO this
	string line;
	if(myfstream.is_open()){
		while(getline(myfstream, line))
		{
			string  line;
			if(getline(myfstream, line)){
				//probably right
				processLine(line);
			}
		}

		return true;
	}else
	{
		return false;
	}
  

}

/*if you are debugging the file must be in the project parent directory
 *in this case Project2 with the .project and .cProject files
 *
 *  
 * bool openFile(std::fstream& myfile, const std::string& myFileName,
 * 	std::ios_base::openmode mode = std::ios_base::in);
 */
bool openFile(std::fstream& myfile, const std::string& myFileName,
		std::ios_base::openmode mode = std::ios_base::in)
{
	//This maybe works not sure what the third variable being passed in is for
	  myfile.open(myFileName, mode);
	  bool isopen = true;
	  if(!myfile.is_open() || myfile.fail())
	  {
		  isopen = false;
	  }
return isopen;
  
}


/*iff myfile is open then close it
 *
 * void closeFile(std::fstream& myfile);
 */
void closeFile(std::fstream& myfile)
{
	if(myfile.is_open()){
		myfile.close();
	}
}



/* serializes all content in myEntryArray to file outputfilename
 * returns  FAIL_FILE_DID_NOT_OPEN if cannot open outputfilename
 * 			FAIL_NO_ARRAY_DATA if there are 0 entries in myEntryArray
 * 			SUCCESS if all data is written and outputfilename closes OK
 * 
 * int writeArraytoFile(const std::string &outputfilename);
 */
int writeArraytoFile(const std::string &outputfilename)
{

	if (currentpos == 0){
		return constants::FAIL_NO_ARRAY_DATA;
	}

	ofstream arrayofEnts;
	arrayofEnts.open(outputfilename.c_str());

	if(arrayofEnts.is_open()){
		arrayofEnts << entryarray;
		arrayofEnts.close();
		return constants::SUCCESS;
	}
	return constants::FAIL_FILE_DID_NOT_OPEN;


//TODO maybe works??
//	  fstream myfile;
//	  myfile.open (outputfilename);
//
//	  if(myfile.is_open())
//	  {
//		  if(currentpos == 0)
//		  {
//			  //Print this?
//			  //cout<<"FAIL_NO_ARRAY_DATA";
//			  return constants::FAIL_NO_ARRAY_DATA;
//		  }else
//		  {
//		  for(int x = 0; x < currentpos; x++){
//			  myfile << entryarray[x].word + " " + std::to_string(entryarray[x].numberOfOccurences) + "\n";
//			  //cout   << entryarray[x].word + " " + std::to_string(entryarray[x].numberOfOccurences) + "\n";
//		  }
//		  closeFile(myfile);
//		  //Print this?
//		  //cout<<"SUCCESS";
//		  return constants::SUCCESS;
//		  }
//	  }else
//	  {
//		  //Print this?
//		  //cout<<"FAIL_FILE_DID_NOT_OPEN";
//		  return constants::FAIL_FILE_DID_NOT_OPEN;
//	  }
//  return 1;
}

bool checkSorted(int j,constants::sortOrder so){
		string str1 = entryarray[j].word;
		string str2 = entryarray[j + 1].word;
		toUpper(str1);
		toUpper(str2);
		switch (so) {
		case constants::ASCENDING:
			return str1>str2;
		case constants::DESCENDING:
			return str1<str2;
		case constants::NONE:
			return true;
		case constants::NUMBER_OCCURRENCES:
			return entryarray[j + 1].numberOfOccurences < entryarray[j].numberOfOccurences;
		default:
			cout << "this should never happen pls dont give me a fake sort order"<< std::endl;
			throw 404;
		}
}


/*
 * Sort myEntryArray based on so enum value.
 * You must provide a solution that handles alphabetic sorting (A-Z)
 * The presence of the enum implies a switch statement based on its value
 *
 * void sortArray(constants::sortOrder so);
 */
void sortArray(constants::sortOrder so){
//	if(so == constants::ASCENDING){
//		for(int i = 0; i < currentpos; i++){
//			string minWord = entryarray[i].word;
//			string tempMinWord = minWord;
//			toUpper(tempMinWord);
//			int minIndex = i;
//			for(int j = i; j < currentpos; j++){
//				string tempWord = entryarray[j].word;
//				toUpper(tempWord);
//				if(tempWord < tempMinWord){
//					minIndex = j;
//					minWord = entryarray[j].word;
//					tempMinWord = entryarray[j].word;
//					toUpper(tempMinWord);
//				}
//			}
//			if(minWord != entryarray[i].word){
//				entry swap = entryarray[i];
//				entryarray[i] = entryarray[minIndex];
//				entryarray[minIndex] = swap;
//			}
//		}
//
//	}
//	else if(so == constants::DESCENDING){
//		for(int i = 0; i < currentpos; i++){
//			string maxWord = entryarray[i].word;
//			string tempMaxWord = maxWord;
//			toUpper(tempMaxWord);
//			int maxIndex = i;
//			for(int j = i; j < currentpos; j++){
//				string tempWord = entryarray[j].word;
//				toUpper(tempWord);
//				if(entryarray[j].word > maxWord){
//					maxIndex = j;
//					maxWord = entryarray[j].word;
//					tempMaxWord = entryarray[j].word;
//					toUpper(tempMaxWord);
//				}
//			}
//			if(maxWord != entryarray[i].word){
//				entry swap = entryarray[i];
//				entryarray[i] = entryarray[maxIndex];
//				entryarray[maxIndex] = swap;
//			}
//		}
//	}
//	else if(so == constants::NUMBER_OCCURRENCES){
//		for(int i = 0; i < currentpos; i++){
//			int minOccur = entryarray[i].numberOfOccurences;
//			int minIndex = i;
//			for(int j = i; j < currentpos; j++){
//				if(entryarray[j].numberOfOccurences < minOccur){
//					minIndex = j;
//					minOccur = entryarray[j].numberOfOccurences;
//				}
//			}
//			if(minOccur != entryarray[i].numberOfOccurences){
//				entry swap = entryarray[i];
//				entryarray[i] = entryarray[minIndex];
//				entryarray[minIndex] = swap;
//			}
//		}
//	}
	cout<<"---------------------"<<std::endl;
	for(int i=0;i <= currentpos;i++){
		cout << entryarray[i].word<<" : "<<entryarray[i].numberOfOccurences<<std::endl;
	}
	bool swapped = true;
	for (int i = 1; (i <= currentpos) && swapped; i++) {
		swapped = false;
		for (int j = 0; j < (currentpos - 1); j++) {
			if (checkSorted(j,so)){//checks if j and j+1 are in order based on so
				entryarray[j+1].word.swap(entryarray[j].word);
				std::swap(entryarray[j+1].numberOfOccurences,entryarray[j].numberOfOccurences);
				swapped = true;
			}
		}
	}
	cout<<"+++++++++++++++++++++++++++++"<<std::endl;
	for(int i=0;i <= currentpos;i++){
			cout << entryarray[i].word<<" : "<<entryarray[i].numberOfOccurences<<std::endl;
	}
}

//TODO look in utilities.h for useful functions, particularly strip_unwanted_chars!

