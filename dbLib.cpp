/* Created by Nguyen Duc Dung on 2019-09-03.
 * =========================================================================================
 * Name        : dbLib.cpp
 * Author      : Duc Dung Nguyen
 * Email       : nddung@hcmut.edu.vn
 * Copyright   : Faculty of Computer Science and Engineering - HCMUT
 * Description : The data structure library for Assignment 1
 * Course      : Data Structure and Algorithms - Fall 2019
 * =========================================================================================
 */

#include "dbLib.h"

/* TODO: You can implement methods, functions that support your data structures here.
 * */


void LoadData(void* &pData) {

	pData = new void*;
	TDataset * Dataset = new TDataset;
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	ifstream myFile;
	string line;
	
	//READ cities.csv
	myFile.open("cities.csv");
	TCity City;
	
	getline(myFile,line);
	//seperate to a line
	while (getline(myFile, line)) {
		seperate_elment_cities(City, line);
		Dataset->get_cities(City);
	}
	myFile.close();
	//cout <<"Cityid:" << Dataset->citiesList->at(1).name << endl;


	//READ Lines.csv
	myFile.open("lines.csv");
	TLine Lines; 
	getline(myFile, line);
	//seperate to a line
	while (getline(myFile, line)) {
		seperate_elment_lines(Lines, line);
		Dataset->get_lines(Lines);
	}
	myFile.close();
	//cout << "Line:" << Dataset->linesList->getSize()<<endl; 

	//READ stationLines.csv
	myFile.open("station_lines.csv");
	TStation_Line Stationlines; 
	getline(myFile, line);
	//seperate to a line
	while (getline(myFile, line)) {
		seperate_elment_stationlines(Stationlines, line);
		Dataset->get_station_linesList(Stationlines);
	}
	myFile.close();
	//cout << "Station_Lines: " <<  Dataset->station_lineList->getSize() << endl;

	//READ stations.csv 
	myFile.open("stations.csv");
	TStation Stationcangetdata;
	getline(myFile, line);
	//seperate to a line
	while (getline(myFile, line)) {
		seperate_elment_stations(Stationcangetdata, line);
		Dataset->get_stationList(Stationcangetdata);
	}
	myFile.close(); 
	 //cout << Dataset->stationList->getSize() << "Station:" << endl;

	//Read track_lines.csv 
	myFile.open("track_lines.csv");
	TTrack_Line Track_lines;
	getline(myFile, line);
	//seperate to a line
	while (getline(myFile, line)) {
		seperate_elment_tracklines(Track_lines, line);
		Dataset->get_tracks_lineList(Track_lines);
	}
	myFile.close(); 
	//cout << "trackLine" << Dataset->track_lineList->getSize(); 


	//Read track_lines.csv 
	myFile.open("tracks.csv");
	TTrack Track;
	getline(myFile, line);
	//seperate to a line
	while (getline(myFile, line)) {
		seperate_elment_track(Track, line);
		Dataset->get_tracks(Track);
	}
	myFile.close();
	//cout << "track:" << Dataset->tracksList->getSize(); 
	pData = new TDataset*();
	pData = Dataset;
	Dataset = nullptr;
	delete Dataset;
	


}
	
void ReleaseData(void* &pData) {
	pData = nullptr;
}
//START TO READ cities.csv..........................................................
void seperate_elment_cities(TCity& City, string& line) {
	
	string element;
	stringstream ss;
	ss.str(line);
	getline(ss, element, ',');
	 City.id = atoi(element.c_str());  
	getline(ss, element, ',');
	City.name = element; 
	getline(ss, element, ',');
	City.coords = element;
	getline(ss, element, ',');
	City.start_year = atoi(element.c_str());
	getline(ss, element, ',');
	City.url_name = element;
	getline(ss, element, ',');
	City.country = element;
	getline(ss, element); 
	if (element != "") City.country_state = element; 
	else City.country_state = ""; 
	//cout << City.id << "," << City.name << "," << City.coords <<","<< City.start_year <<","<< City.url_name <<"," << City.country <<","<< City.country_state <<endl;
	
}
//START TO READ lines.csv..........................................................
void seperate_elment_lines(TLine& Lines, string& line) {
	string element;
	stringstream ss;
	ss.str(line);
	getline(ss, element, ',');
	if (element != "") Lines.id = atoi(element.c_str());
	getline(ss, element, ',');
	if (element != "") Lines.city_id = atoi(element.c_str());
	if (ss.peek() == '"') {
		getline(ss, Lines.name, '"');
		getline(ss, Lines.name, '"');
		getline(ss, element, ',');
	}
	else  getline(ss, Lines.name, ',');
	getline(ss, element, ',');
	if (element != "") Lines.url_name = element;
	getline(ss, element, ',');
	if (element != "") Lines.color = element;
	getline(ss, element, ',');
	if (element != "") Lines.system_id = atoi(element.c_str());
	getline(ss, element);
	if (element != "") Lines.transport_mode_id = atoi(element.c_str());
	//cout << Lines.id << "," << Lines.name << "," << Lines.url_name << "," << Lines.color << "," << Lines.system_id << "," << Lines.transport_mode_id <<endl; 
}
//START TO READ station lines.csv..........................................................
void seperate_elment_stationlines(TStation_Line& Stationlines, string&line) {
	string element;
	stringstream ss; 
	ss.str(line);	
	getline(ss, element, ',');
	if (element != "") Stationlines.id = atoi(element.c_str());
	getline(ss, element, ',');
	if (element != "") Stationlines.station_id = atoi(element.c_str());
	getline(ss, element, ',');
	if (element != "") Stationlines.line_id = atoi(element.c_str());
	getline(ss, element, ',');
	if (element != "") Stationlines.city_id = atoi(element.c_str());
	getline(ss, element, ',');
	if(element != "") Stationlines.created_at = element;
	getline(ss, element);
	if (element != "") Stationlines.updated_at = element;
	//cout << Stationlines.id << "," << Stationlines.station_id << "," << Stationlines.line_id << "," << Stationlines.city_id << "," << Stationlines.created_at << "," << Stationlines.updated_at << endl; 
}
//START TO READ STATIONS.CSV 
void seperate_elment_stations(TStation& Stationcangetdata, string &line) {
	string element;
	stringstream stst;
	stst.str(line);
	getline(stst, element, ',');
	if (element != "") Stationcangetdata.id = atoi(element.c_str());
	if (stst.peek() == '"') {
		getline(stst, Stationcangetdata.name, '"');
		getline(stst, Stationcangetdata.name, '"');
		getline(stst, element, ',');
	}
	else  getline(stst, Stationcangetdata.name, ',');
	getline(stst, element, ',');
	if (element != "") Stationcangetdata.geometry = element;
	getline(stst, element, ',');
	if (element != "") Stationcangetdata.buildstart = atoi(element.c_str());
	getline(stst, element, ',');
	if (element != "") Stationcangetdata.opening = atoi(element.c_str());
	getline(stst, element, ',');
	if (element != "") Stationcangetdata.closure = atoi(element.c_str());
	getline(stst, element);
	if (element != "")Stationcangetdata.city_id = atoi(element.c_str());
	//cout << Stationcangetdata.id << "," << Stationcangetdata.name << "," << Stationcangetdata.geometry << "," << Stationcangetdata.buildstart << "," << Stationcangetdata.opening << "," << Stationcangetdata.closure << "," << Stationcangetdata.city_id << endl; 
}
//Start to read track_lines.csv 
void seperate_elment_tracklines(TTrack_Line& Track_lines, string &line) {

	string element;
	stringstream ss;
	ss.str(line);
	getline(ss, element, ',');
	if (element != "") Track_lines.id = atoi(element.c_str());
	getline(ss, element, ',');
	if (element != "") Track_lines.section_id = atoi(element.c_str());
	getline(ss, element, ',');
	if (element != "") Track_lines.line_id = atoi(element.c_str());
	getline(ss, element, ',');
	if (element != "") Track_lines.created_at = element;
	getline(ss, element, ',');
	if (element != "") Track_lines.updated_at = element;
	getline(ss, element);
	if (element != "") Track_lines.city_id = atoi(element.c_str()); 
	//cout << Track_lines.id << "," << Track_lines.section_id << "," << Track_lines.line_id << "," << Track_lines.created_at << "," << Track_lines.updated_at << "," << Track_lines.city_id << endl; 
}
void seperate_elment_track(TTrack &Track, string &line) {
	string element; 
	stringstream ss; 
	ss.str(line); 
	getline(ss, element, ',');
	if (element != "") Track.id = atoi(element.c_str());
	getline(ss, element, '"');
	getline(ss, element, '"');
	if (element != "") Track.geometry = element;
	getline(ss, element, ',');
	getline(ss, element, ',');
	if (element != "") Track.buildstart = atoi(element.c_str());
	getline(ss, element, ',');
	if (element != "") Track.opening = atoi(element.c_str());
	getline(ss, element, ',');
	if (element != "") Track.closure = atoi(element.c_str());
	getline(ss, element, ',');
	if (element != "") Track.length = atoi(element.c_str());
	getline(ss, element);
	if (element != "") Track.city_id = atoi(element.c_str()); 
	//cout << Track.id << "," << Track.geometry << "," << Track.buildstart << "," << Track.opening << "," << Track.closure << "," << Track.length << "," << Track.city_id << endl; 
}