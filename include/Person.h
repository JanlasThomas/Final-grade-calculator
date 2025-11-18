

#include "Lib.h"
class Timer{
public:
 using clock = std::chrono::high_resolution_clock;

std::chrono::time_point<clock> start, temp;
   std::chrono::duration <double> executiontime;

void timestart( ) ;
void timetaken();
};
void outputtemplate ();
void filegenerator (const string& filename, size_t n);
class Person
{
    public:
    string firstname, surname;
    vector <int> Homework;
    int exam;
    double FinalgradeAvg;
    double FinalgradeMed;


    void FinalAv();

     double med();
    void FinalMed();
    Person ();


    Person (string A, string B, vector<int> C, int D);

    ~Person() ;
    Person(const Person& other) ;
    Person& operator=(const Person& other);
   friend std::ostream& operator<<(std::ostream& os, const Person& p);
    friend std::istream& operator>>(std::istream& is, Person& p);

};
