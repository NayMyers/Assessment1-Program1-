#pragma once //stops duplicate library includes
#include<iostream> //library for writing and reading from the command line
#include<string> //library to allow the creation of string objects
#include<fstream> //Library to allow the reading and writing to files
#include<vector>//library to allow the creation of vector objects

using namespace std;

#define SALESDATAFILE "salesData.txt"
#define BARCHARTFILE "barChart.txt"

class SalesData
{
private:
	ifstream inputfile;
	ofstream outputfile;
	vector<int> salesrecords;

public:
	void loadDataFromFile(string filename); //Puts the data in the text file into a vector.
	void saveBarChartToFile(string filename);
};

void SalesData::loadDataFromFile(string filename)
{
	inputfile.open(filename); //opens the text file using the file handle inputfile
	int placeholder = 0; //Creates a variable to load the integers into from the text file before they are placed into the vector to create a logical condition for the while loop
	while (inputfile >> placeholder)//When there is no more data to be retrieved from the input file stop the loop
	{
		salesrecords.push_back(placeholder); //Put the data from the placeholder into the back of the vector using the method push_back to be able to 
	}
}
void SalesData::saveBarChartToFile(string filename)
{
	outputfile.open(filename);
	int asterixnumber = 0;
	outputfile << "SALES BAR CHART" << endl << "(each * equals £100)" << endl;
	
	for (int x = 0; x<int(salesrecords.size()); x++)
	{
		asterixnumber = salesrecords[x] / 100;
		outputfile << "Store:" << x<<" ";
		for (int y = 0; y < asterixnumber; y++)
		{
			outputfile << "*";
		}
		outputfile << endl;
	}
	outputfile.close();

}
int main(void)
{
	SalesData Sales;
	Sales.loadDataFromFile(SALESDATAFILE);
	Sales.saveBarChartToFile(BARCHARTFILE);
	return 0;
}

