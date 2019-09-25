/*
 * functionstocomplete.cpp
 *
 *  Created on: Sep 10, 2017
 *      Author: keith
 */

//============================================================================
//	TODO add necessary includes here
//============================================================================

//============================================================================
//	stuff you will need
//============================================================================

#ifndef ARRAY_FUNCTIONS_H_
#define ARRAY_FUNCTIONS_H_
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "constants.h"
#include "utilities.h"
//#include "ALL OTHER.H FILES"
void clearArray();
//TODO define a structure to track words and number of times they occur

//TODO add a global array of entry structs (global to this file)

//TODO add variable to keep track of next available slot in array

//TODO define all functions in header file

//TODO look in utilities.h for useful functions, particularly strip_unwanted_chars!


//zero out array that tracks words and their occurrences
//void clearArray();
clearArray()
{
}

//how many unique words are in array
//int getArraySize();

 getArraySize()
 {
   
 return 1;
 }
//get data at a particular location
//std::string getArrayWordAt(int i);

std::string getArrayWordAt(int i)
{
//TODO this
  
//this one looks strange, no return or void??
}

//int getArrayWord_NumbOccur_At(int i);
getArrayWord_NumbOccur_At(int i)
{
//TODO this
  
  
return 1;
}

/*loop through whole file, one line at a time
 * call processLine on each line
 * returns false: myfstream is not open
 *         true: otherwise*/
//bool processFile(std::fstream &myfstream);
processFile(std::fstream &myfstream)
{
//TODO this
  
return true;
}

/*take 1 line and extract all the tokens from it
feed each token to processToken for recording*/
//void processLine(std::string &myString);
processLine(std::string &myString)
{
//TODO this
  
  
//NO return bc void
}

/*Keep track of how many times each token seen*/
//void processToken(std::string &token);
processToken(std::string &token)
{
//TODO this
  
  
//No return bc void
}


/*if you are debugging the file must be in the project parent directory
 *in this case Project2 with the .project and .cProject files
 *
 *  
 * bool openFile(std::fstream& myfile, const std::string& myFileName,
 * 	std::ios_base::openmode mode = std::ios_base::in);
 */
openFile(std::fstream& myfile, const std::string& myFileName,
         std::ios_base::openmode mode = std::ios_base::in)
{
  //TODO this
  
  return true;//just to compile
}


/*iff myfile is open then close it
 *
 * void closeFile(std::fstream& myfile);
 */
closeFile(std::fstream& myfile)
{
//TODO this
  
//No return bc void
}



/* serializes all content in myEntryArray to file outputfilename
 * returns  FAIL_FILE_DID_NOT_OPEN if cannot open outputfilename
 * 			FAIL_NO_ARRAY_DATA if there are 0 entries in myEntryArray
 * 			SUCCESS if all data is written and outputfilename closes OK
 * 
 * int writeArraytoFile(const std::string &outputfilename);
 */
writeArraytoFile(const std::string &outputfilename)
{
//TODO
  
  
  return 1;
}


/*
 * Sort myEntryArray based on so enum value.
 * You must provide a solution that handles alphabetic sorting (A-Z)
 * The presence of the enum implies a switch statement based on its value
 *
 * void sortArray(constants::sortOrder so);
 */
sortArray(constants::sortOrder so)
{
 //TODO This 
  
  
  //no Return bc void
}

/*
 * std::string func(); makes
 *
 *std::string func()
 *{
 *	return "hello";
 *}
 */
