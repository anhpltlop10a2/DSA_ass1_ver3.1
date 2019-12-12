/* Created by Nguyen Duc Dung on 2019-09-03.
 * =========================================================================================
 * Name        : processData.cpp
 * Author      : Duc Dung Nguyen
 * Email       : nddung@hcmut.edu.vn
 * Copyright   : Faculty of Computer Science and Engineering - HCMUT
 * Description : Implementation of main features in the assignment
 * Course      : Data Structure and Algorithms - Fall 2019
 * =========================================================================================
 */

#include "processData.h"

/* TODO: You can implement methods, functions that support your data structures here.
 * */
#include "dbLib.h"
using namespace std;

void Initialization() {
    // If you use global variables, please initialize them explicitly in this function.
}
void Finalization() {
    // Release your data before exiting
}
bool cityNameTocityId(TCity&City, string cityName) {
	if (City.name == cityName) return true;
	else return false;
}
bool findcityid(TLine& Line, int cityid) {
	if (Line.city_id == cityid) return true;
	return false;
}
bool findstationid(TStation& Station, int cityid) {
	if (Station.city_id == cityid) return true;
	return false;
}
bool findlineid(TLine& Line, int cityid) {
	if (Line.city_id == cityid) return true;
	return false;
}
bool findstationid(TStation_Line& Stationline, int lineID) {
	if (Stationline.line_id == lineID) return true; 
	return false; 
}
bool findstationid(TStation& Station, string stationName) {
	if (Station.name == stationName) return true;
	return false;
}




void ProcessRequest(const char* pRequest, void* pData, void* &pOutput, int &N) {
	// TODO: Implement this function for processing a request
	// NOTE: You can add other functions to support this main process.
	//       pData is a pointer to a data structure that manages the dataset
	//       pOutput is a pointer reference. It is set to nullptr and student must allocate data for it in order to save the required output
	//       N is the size of output, must be a non-negative number
	TDataset* myData = new TDataset();
	myData = (TDataset*)pData;
	string str1, str2, str3;
	stringstream ss;
	ss << pRequest;
	ss >> str1 >> str2 >> str3;
	// Implement Request............................................................................................
	//REQUEST1: 
	if (str1 == "CL" && str2 == "")
	{
		pOutput = new int*();
		*((int*)pOutput) = myData->get_SizeOFLine();
		N = 1;
	}
	//Request2:
	else if (str1 == "CL" && str2 != "")
	{
		string cityName = "";
		if (str3 != "") cityName = str2 + " " + str3;
		else cityName = str2;
	int cityid = myData->citiesList->traverse(cityNameTocityId, cityName).id;
	L1List <TLine> *regLine = new L1List<TLine>;
	myData->linesList->traverse(findcityid, cityid, regLine); 
	//cout << regLine->at(2).name; 
	pOutput = new int(regLine->getSize()); 
	N = 1;
	}
	//Request3:
	else if (str1 == "LSC")
	{
		string cityName = "";
		///////////////////////////////////////
		if (str3 != "") cityName = str2 + " " + str3;
		else cityName = str2;
		int cityid = myData->citiesList->traverse(cityNameTocityId, cityName).id;
		L1List <TStation> *regStationid = new L1List<TStation>;
		myData->stationList->traverse(findstationid, cityid, regStationid);
		int length = regStationid->getSize();
		int * arr = new int[length];
		for (int i = 0; i < length; i++) {
			arr[i] = regStationid->at(i + 1).id;
		}
		pOutput = arr;
		N = length;
	}
	//Request4:
	else if (str1 == "LLC")
	{
		string cityName = "";
		if (str3 != "") cityName = str2 + " " + str3;
		else cityName = str2;
		int cityid = myData->citiesList->traverse(cityNameTocityId, cityName).id;
		L1List <TLine> *regLineid = new L1List<TLine>;
		myData->linesList->traverse(findlineid, cityid, regLineid);
		int length = regLineid->getSize();
		int * arr = new int[length];
		for (int i = 0; i < length; i++) {
			arr[i] = regLineid->at(i + 1).id;
		}
		pOutput = arr;
		N = length;
	}
	//Request5: 
	else if (str1 == "LSL")
	{
		int line_ID = stoi(str2);
		L1List <TStation_Line> *regstationid = new L1List<TStation_Line>;
		myData->station_lineList->traverse(findstationid, line_ID, regstationid);
		int length = regstationid->getSize();
		int * arr = new int[length];
		for (int i = 0; i < length; i++) {
			arr[i] = regstationid->at(i + 1).id;
		}
		pOutput = arr;
		N = length;
	}
	//Request6: 
	else if (str1 == "FC")
	{
		string cityName = ""; 
		if (str3 != "") cityName = str2 + " " + str3;
		else cityName = str2;
		int cityid = myData->citiesList->traverse(cityNameTocityId, cityName).id;
		pOutput = new int(cityid);
		N = 1;
	}
	//Request7: 
	else if (str1 == "FS")
	{
		string stationName = "";
		string input = pRequest + 3;
		stringstream stst(input);
		string tmp = "";
		if (stst.peek() == '"') {
			getline(stst, stationName, '"');
			getline(stst, stationName, '"');
			getline(stst, tmp, ',');
		}
		else  getline(stst, stationName, ',');

		int stationid = myData->stationList->traverse(findstationid, stationName).id;
		pOutput = new int(stationid);
		N = 1;
	}




		
}
	



		


	

	


