#include"Person.h"

    void Person:: FinalAv() {
        Finalgrade = std::accumulate(Homework.begin(), Homework.end(), 0.0) / Homework.size() * 0.4 + exam * 0.6;
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
        Finalgrade = med() * 0.4 + exam * 0.6;
    };

    //default constructor
    Person::Person ()
    {
        firstname = "Test";
        surname= "Test";
        Homework = {9,9,9,9,9,9};
        exam = 9;
        Finalgrade = 0;

    };
//parametrized constructor
    Person :: Person (string A, string B, vector<int> C, int D)
    {
        firstname = A;
        surname =B;
        Homework = C;
        exam = D;
        Finalgrade = 0;
    };
   //copy constructor
    Person::Person(const Person& other) {
    firstname = other.firstname;
    surname = other.surname;
    Homework = other.Homework;
    exam = other.exam;
    Finalgrade = other.Finalgrade;
}

   //destructor
    Person::~Person() {
        firstname.clear();
        surname.clear();
        Homework.clear();
        exam = 0;
        Finalgrade = 0;
    };

    //assignment copy operator
  Person& Person::operator=(const Person& other) {
    if (this != &other) {
        firstname = other.firstname;
        surname = other.surname;
        Homework = other.Homework;
        exam = other.exam;
        Finalgrade = other.Finalgrade;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Person& p) {


    os << left << setw(15) << p.firstname << setw(15) << p.surname
             << fixed << setprecision(2) << setw(20) << p.Finalgrade << endl;
}

std::istream& operator>>(std::istream& is, Person& p) {
    cout << "Enter firstname: ";
    is >> p.firstname;
    std::cout << "Enter surname: ";
    is >> p.surname;


p.Homework.clear();
cout<<"1. Enter 'R' to use Random homework & exam grades \n2. Enter 'S' to use your input grades" << endl;
string t;
is>>t;

if(t == "R" || t == "r")
{

    srand(time(0));
    vector <int> grades (5);
    for ( int i=0; i <5; ++i )
    {
        grades[i] = rand() % 10;
        p.Homework.push_back(i);
    }

    int rexam;
    rexam = rand() % 10;
    p.exam = rexam;


}

else if (t == "S" || t == "s")
{
   cout << "Enter the Homework grades (To stop enter a negative number): " << std::endl;
int temp;
while (true) {
    is >> temp;
    if (temp < 0) break;
    p.Homework.push_back(temp);
}
   cout << "Enter exam grade: ";
    is >> p.exam;
}

else{
    cout << "choose the correct option" << endl;
}
    cout << "choose the method of Final grade calculation ( M = Median , A = Average) : ";
    string choose;
    cin>> choose;
    if  (choose == "A" || choose == "a") {
         p.FinalAv();
    }
    if(choose == "m" || choose == "M")
    {
         p.FinalMed ();
    }

    return is;
}
