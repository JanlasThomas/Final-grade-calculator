#include"Person.h"

    void Person:: FinalAv() {
        FinalgradeAvg = std::accumulate(Homework.begin(), Homework.end(), 0.0) / Homework.size() * 0.4 + exam * 0.6;
    };

    // Calculates median of homework
double Person::med() {
    vector<int> temp = Homework;
    sort(temp.begin(), temp.end());
    size_t n = temp.size();
    if (n == 0) return 0.0;
    if (n % 2 == 0)
        return (temp[n/2 - 1] + temp[n/2]) / 2.0;
    else
        return temp[n/2];
}

void Person::FinalMed() {
        FinalgradeMed = med() * 0.4 + exam * 0.6;
    };

    //default constructor
    Person::Person ()
    {
        firstname = "Test";
        surname= "Test";
        Homework = {9,9,9,9,9,9};
        FinalgradeAvg = 0;
        FinalgradeMed = 0;

    };
//parametrized constructor
    Person :: Person (string A, string B, vector<int> C, int D)
    {
        firstname = A;
        surname =B;
        Homework = C;
        FinalgradeAvg = 0;
        FinalgradeMed = 0;
    };
   //copy constructor
    Person::Person(const Person& other) {
    firstname = other.firstname;
    surname = other.surname;
    Homework = other.Homework;
    FinalgradeAvg = other.FinalgradeAvg;
    FinalgradeMed = other.FinalgradeMed;
}

   //destructor
    Person::~Person() {
        firstname.clear();
        surname.clear();
        Homework.clear();
        FinalgradeAvg = 0;
        FinalgradeMed = 0;
    };

    //assignment copy operator
  Person& Person::operator=(const Person& other) {
    if (this != &other) {
        firstname = other.firstname;
        surname = other.surname;
        Homework = other.Homework;
        FinalgradeAvg = other.FinalgradeAvg;
        FinalgradeMed = other.FinalgradeMed;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Person& p) {


    os << left << setw(15) << p.firstname << setw(15) << p.surname
             << fixed << setprecision(2) << setw(20) << p.FinalgradeAvg  <<setw(5) << "|" << setprecision(2)<< p.FinalgradeMed << endl;
}

std::istream& operator>>(std::istream& is, Person& p)
{

  is >> p.firstname >> p.surname;
  p.Homework.clear();

p.Homework.clear();
    int grade;
    for (int i = 0; i < 5; ++i) {
        is >> grade;
        p.Homework.push_back(grade);
    }

    is >> p.exam;

    p.FinalAv();
    p.FinalMed();

    return is;


}
