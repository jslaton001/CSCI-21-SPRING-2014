/*
 * Programming Challenge 7
 */
#include <cassert>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
using namespace std;

/*
 * Open and read the contents of a text file. Each line of the
 * file will contain a single integer of possible values 10, 20, 
 * 30, 40, or 50. Perform the following operations on the input values:
 * <ul>
 * <li>10 -- invoke the function onTen</li>
 * <li>20 -- invoke the function onTwenty</li>
 * <li>30 -- invoke the function onThirty</li>
 * <li>40 -- invoke the function onForty</li>
 * <li>50 -- invoke the function onFifty</li>
 * <li>any other value -- invoke the function onError</li>
 * </ul>
 * @param filename a string containing the name of the file to 
 *        be processed
 * @return true if filename was successfully opened and processed, else false
 */
bool processFile (string filename);

/* for unit testing -- do not alter */
map<int,int> counters;
void onTen ();
void onTwenty ();
void onThirty ();
void onForty ();
void onFifty ();
void onError ();

template <typename X, typename A>
void btassert(A assertion);
void unittest ();

int main ()
{
	unittest();
	
	return 0;
}

// CODE HERE -- FUNCTION DEFINITIONS

/*
 * Unit testing functions. Do not alter.
 */

bool processFile(string filename)
{
    ifstream fin(filename.c_str());
    string fileInput;
    stringstream strToInt;
    int fileNum = 0;
    
    if (!fin.good())
        return false;
    
    while (getline(fin, fileInput))
    {
        strToInt << fileInput;
        strToInt >> fileNum;
        switch (fileNum)
        {
            case 10:
                onTen();
                break;
            case 20:
                onTwenty();
                break;
            case 30:
                onThirty();
                break;
            case 40:
                onForty();
                break;
            case 50:
                onFifty();
                break;
            default:
                onError();
                break;
        }
    }

    fin.close();
    
    return true;
}

void unittest ()
{
	cout << "\nSTARTING UNIT TEST\n\n";
	
	counters[10] = 0, counters[20] = 0, counters[20] = 0, counters[40] = 0, counters[50] = 0;
	counters[99] = 0; // errors
	
	processFile("challenge-7-input.txt");
	
	try {
		btassert<bool>(counters[10] == 15);
		cout << "Passed TEST 1: counters[10]\n";
	} catch (bool b) {
		cout << "# FAILED TEST 1 counters[10] #\n";
	}
	
	try {
		btassert<bool>(counters[20] == 14);
		cout << "Passed TEST 2: counters[20]\n";
	} catch (bool b) {
		cout << "# FAILED TEST 2 counters[20] #\n";
	}
	
	try {
		btassert<bool>(counters[30] == 13);
		cout << "Passed TEST 3: counters[30]\n";
	} catch (bool b) {
		cout << "# FAILED TEST 3 counters[30] #\n";
	}
	
	try {
		btassert<bool>(counters[40] == 12);
		cout << "Passed TEST 4: counters[40]\n";
	} catch (bool b) {
		cout << "# FAILED TEST 4 counters[40] #\n";
	}
	
	try {
		btassert<bool>(counters[50] == 11);
		cout << "Passed TEST 5: counters[50]\n";
	} catch (bool b) {
		cout << "# FAILED TEST 5 counters[50] #\n";
	}
	
	try {
		btassert<bool>(counters[99] == 35);
		cout << "Passed TEST 6: counters[99]\n";
	} catch (bool b) {
		cout << "# FAILED TEST 6 counters[99] #\n";
	}
	
	try {
		btassert<bool>(processFile("non-existent-file.txt") == false);
		cout << "Passed TEST 7: processFile(\"non-existent-file.txt\")\n";
	} catch (bool b) {
		cout << "# FAILED TEST 7 processFile(\"non-existent-file.txt\") #\n";
	}
	
	cout << "\nUNIT TEST COMPLETE\n\n";
}

void onTen ()
{
	counters[10]++;
}

void onTwenty ()
{
	counters[20]++;
}

void onThirty ()
{
	counters[30]++;
}

void onForty ()
{
	counters[40]++;
}

void onFifty ()
{
	counters[50]++;
}

void onError ()
{
	counters[99]++;
}

template <typename X, typename A>
void btassert (A assertion)
{
    if (!assertion)
		throw X();
}