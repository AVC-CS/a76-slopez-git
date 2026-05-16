#ifndef MAIN_HPP
#define MAIN_HPP

// Construct an array-of-records from a multi-column data file (babyname.txt)
// and search for matching names by state and starting character.

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
using namespace std;

const int N = 5000;

int makeNameRecord(string[], string[], int[], string[], int[]);
void printoutallrecords(int, string[], string[], int[], string[], int[]);
int findNames(int, string[], string[], int[], string[], int[], char, string);
void printoutcontents(string, string, int, string, int);

int makeNameRecord(string state[], string gender[], int year[], string name[], int count[])
{
    ifstream inputfile("babyname.txt");
    if (!inputfile)
    {
        cerr << "Error opening babyname.txt" << endl;
        exit(EXIT_FAILURE);
    }

    int cnt = 0;
    while (cnt < N && inputfile >> state[cnt] >> gender[cnt] >> year[cnt] >> name[cnt] >> count[cnt])
    {
        cnt++;
    }

    inputfile.close();
    return cnt;
}

int findNames(int cnt, string state[], string gender[], int year[], string name[], int count[], char starting, string stname)
{
    int matches = 0;
    cout << "The list of names in " << stname << " and starting with " << starting << endl;
    for (int i = 0; i < cnt; i++)
    {
        if (state[i] == stname && name[i].rfind(string(1, starting), 0) == 0)
        {
            printoutcontents(state[i], gender[i], year[i], name[i], count[i]);
            matches++;
        }
    }
    cout << "total lines: " << matches << endl;
    return matches;
}

void printoutallrecords(int cnt, string state[], string gender[], int year[], string name[], int count[])
{
    for (int i = 0; i < cnt; i++)
        printoutcontents(state[i], gender[i], year[i], name[i], count[i]);
    cout << "total lines: " << cnt << endl;
}

void printoutcontents(string statename, string sex, int year, string name, int count)
{
    cout << setw(5) << statename << "\t";
    cout << setw(3) << sex << "\t";
    cout << setw(5) << year << "\t";
    cout << setw(10) << name << "\t\t";
    cout << setw(5) << count << endl;
}

#endif
