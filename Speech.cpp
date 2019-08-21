#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include "Matrix.h"

#include "Line.h"


using namespace std;

void main ()
{
	char file_name[10];	//Variable for data file name
	double temp = 0.0; //Variable for temporary storage
	int count2=0; //Counter
	
	int origin=400;

	cout << "Maximise console window before continuing\n\n";
	cout << "Enter file name: ";
	cin >> file_name;//Input file name from console

	ifstream infile(file_name, ios::in); //Selects file using name input from console
 
	while(infile >> temp){ //Count number of values in file
		count2++;
	}

	infile.clear(); 
	infile.seekg(0, ios::beg);// Move back to beginning of file

	matrix sample_array(count2); // Create vector matrix

	infile >> sample_array; // Place values in matrix

	infile.close(); //Closes file

	cout << "\n";
	sample_array.calc_mean();
	sample_array.calc_variance();
	sample_array.calc_standard_dev();
	sample_array.calc_av_power();
	sample_array.calc_av_mag();

	cout << "Mean: " << sample_array.get_mean() << endl;
	cout << "Variance: " << sample_array.get_variance() << endl;
	cout << "Standard Deviation: " << sample_array.get_standard_dev() << endl;
	cout << "Average Power: " << sample_array.get_av_power() << endl;
	cout << "Average Magnitude: " << sample_array.get_av_mag() << endl;

	sample_array.transpose(200);

	HWND hWnd=GetForegroundWindow();
	HDC hDC=GetDC(hWnd);

	line testline(0, origin, 255,255,255, 800, origin);
	testline.draw(hDC);
	
	line* theline[500];

	int c=0;
		
	for (int i=0; i<499; i++){
			theline[i]=new line(i, origin - sample_array.get_matrix(c), 255, 255, 255, i+1, origin - sample_array.get_matrix(c+2));
			theline[i]->draw(hDC);
			c=c+2;
		}
		
}