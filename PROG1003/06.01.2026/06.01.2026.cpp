#include <iostream>
#include <iomanip>
using namespace std; //Dont need std::cout /std::cin
void getnums(int& input1, int& input2);


int main()
{

    /*
    int totalSeconds = 125, minutes, seconds;
    minutes = totalSeconds / 60;
    seconds = totalSeconds % 60;
    cout << totalSeconds << " seconds is equivalent to " << minutes << " minutes and " << seconds << " seconds \n"; 
    
    return 0;*/ 

    /*

    int length, width, area;
    
    cout << "Wnat is the length of the rectangle? "; 
    cin >> length;

    cout << " \n" << length;
    */
    /*
    int value, value2; 
    value = 50;
    value2 = 59;
    float value3;
    value3 = static_cast <float> (value) / (value2); 
    */

    /*
    * requires included iomanip
    cout << setw(6) << 10 << setw(6) << 900 << setw(6);
    

    char tegn;
    char string[100];
    */


    /* some string bullshit */

    string test = "blah blah blah"; 
    string test2(10, '!'); /*10 characters of "!" */
    string test3; /*blank sting*/

    /*single chars
    cout << "enter single char";
    cin >> test3; 
    cin.ignore();
    cout << "test + '" << test3 << "'";
    */

    /*multiple chars
    cout << "enter multiple chars ";
    getline(cin, test3); 
    cout << test3; */

    /*compare text
    if(test == test2){} //both are equal
    if(test < test2){} // test smaller than test2 aplhabetically
    */

    /*get text length
    cout << test.length(); */



	/*Overloading*/
	// Function overloading allows multiple functions to have the same name, as long as their parameters are different in type or number:
	//float somefunctionname(const int hours, const float days); 

	/*variable references*/
	/*
	int input1, input2; 
	getnums(input1, input2);
	cout << "Numbers are '" << input1 << " and " << input2 << "'"; 
	*/



}


void getnums(int& input1, int& input2) {
	/*variable references*/
	/*input 1 and 2 are updated from wherever this function is run. NOT COPIED*/
	cout << "enter an integer";
	cin >> input1;
	cout << "enter a second integer";
	cin >> input2;
}