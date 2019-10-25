/*
 * FileReader.cpp
 *
 *  Created on: Oct 8, 2017
 *      Author: keith
 */
#include <iostream>
#include <fstream>
#include "../327_proj3_test/includes/FileIO.h"
#include "../327_proj3_test/includes/constants.h"

using namespace std;

int KP_FileIO::getFileContents(const std::string &filename, std::string &contents)
{
	fstream myfile;
	string line;
	myfile.open(filename.c_str());

	if(!myfile.is_open()){
		contents.clear();
		return COULD_NOT_OPEN_FILE_TO_READ;
	}
	else{
		while(!myfile.eof()){
			getline(myfile,line);
			contents += line;
		}
		myfile.close();
		return SUCCESS;
	}
}

int KP_FileIO::writeVectortoFile(const std::string filename,std::vector<std::string> &myEntryVector)
{
	ofstream myfile;
	myfile.open(filename);

	if(!myfile.is_open()){
		return COULD_NOT_OPEN_FILE_TO_WRITE;
	}
	else{
		for (int i = 0; i < myEntryVector.size(); i++){
			myfile << myEntryVector[i] << endl;
		}
		myfile.close();
		return SUCCESS;
	}
}


