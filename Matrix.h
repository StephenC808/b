#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
int count=0;

class matrix{
		std::vector<double> matrix_data; //Vector to hold data
		friend ostream& operator << (ostream&,  matrix&); // Grant friendship to operators
		friend istream& operator >> (istream&, matrix&); // Grant friendship to operators
		double mean;
		double variance;
		double standard_deviation;
		double average_power;
		double average_magnitude;

	public:
		matrix(){								//Constructor
			int i;
			for (i=0; i < 2; i++)		
					matrix_data [i] = 0;
			}
		matrix(int count1){	//Constructor

			count = count1;
			mean=0.0;
			variance=0.0;
			standard_deviation=0.0;
			average_power=0.0;
			average_magnitude=0.0;
			matrix_data.resize(count1); 
			int i;
			for (i=0; i < count1; i++)		
					matrix_data [i] = 0; //Initialise
			}
		void set_matrix (int r, int data);
		void transpose (int factor);
		double get_matrix(int r);
		void calc_mean(void);
		void calc_variance(void);
		void calc_standard_dev(void);
		void calc_av_power(void);
		void calc_av_mag(void);
		double get_mean(void);
		double get_variance(void);
		double get_standard_dev(void);
		double get_av_power(void);
		double get_av_mag(void);
};

//---------------------------------------------------

ostream& operator << (ostream &os, matrix& temp)	//Overloading ostream opperator
{
	int i;
	for (i=0; i < count; i++){	//Counter
			os  << temp.matrix_data[i]; cout << "\n";}	//Outputs grid data
	return os;
}

istream& operator >> (istream &is, matrix& temp)	//Overloading istream operator
{
	int i;
	for (i=0; i < count; i++){
			is >> temp.matrix_data[i];
		
	}
	return is;
}


double matrix::get_matrix(int r){
	

	return matrix_data[r];
	
}

void matrix::set_matrix(int r, int data){

	matrix_data[r] = data;
}

void matrix::transpose(int factor){

	for (int i=0; i < count; i++){
			matrix_data[i] = matrix_data[i] *factor;
	}
}

void matrix::calc_mean(void){
	double temp = 0.0;
	for(int i=0; i<count; i++){ //Calculate mean
			temp=matrix_data[i];
			mean=mean+temp;
		}
		mean= mean/count;
}

void matrix::calc_variance(void){
	double temp = 0.0;
	for(int i=0; i<count; i++){ // Calculate variance
			temp=matrix_data[i];
			variance=variance+(temp-mean)*(temp-mean);
		}
		variance=variance/count;
}

void matrix::calc_standard_dev(void){

	standard_deviation= sqrt(variance);

}

void matrix::calc_av_power(void){
	double temp = 0.0;
	for(int i=0; i<count; i++){ //Calculate Average power
			temp=matrix_data[i];
			average_power=average_power+(temp)*(temp);
		}
		average_power = average_power/count;

}

void matrix::calc_av_mag(void){
	double temp = 0.0;
	for(int i=0; i<count; i++){ //Calculate average magnitude
			temp=matrix_data[i];
			if (temp < 0){
				temp = temp*(-1);
			}
			average_magnitude=average_magnitude+temp;
		}
		average_magnitude=average_magnitude/count;

}

double matrix::get_mean(void){return mean;}
double matrix::get_variance(void){return variance;}
double matrix::get_standard_dev(void){return standard_deviation;}
double matrix::get_av_power(void){return average_power;}
double matrix::get_av_mag(void){return average_magnitude;}


		