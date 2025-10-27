#include"Person.h"

    void Person:: FinalAv() {
        Finalgrade = std::accumulate(Homework.begin(), Homework.end(), 0.0) / Homework.size() * 0.4 + exam * 0.6;
    };



    //default constructor
    Person::Person ()
    {
        firstname = "Test";
        surname= "Test";
        Homework = {9,9,9,9,9,9};
        exam = 9;
        FinalAv();

    };
//parametrized constructor
    Person :: Person (string A, string B, vector<int> C, int D)
    {
        firstname = A;
        surname =B;
        Homework = C;
        exam = D;
        FinalAv();
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
    os << p.firstname << " " << p.surname << " Homework: ";
    for (size_t i = 0; i < p.Homework.size(); ++i) {
        os << p.Homework[i];
        if (i != p.Homework.size() - 1) os << ",";
    }
    os << " Exam: " << p.exam << " Final: " << p.Finalgrade;
    return os;
}

std::istream& operator>>(std::istream& is, Person& p) {
    std::cout << "Enter firstname: ";
    is >> p.firstname;
    std::cout << "Enter surname: ";
    is >> p.surname;
    std::cout << "Enter number of homework grades: ";
    size_t n;
    is >> n;
    p.Homework.resize(n);
    std::cout << "Enter homework grades: ";
    for (size_t i = 0; i < n; ++i)
        is >> p.Homework[i];
    std::cout << "Enter exam grade: ";
    is >> p.exam;
    p.FinalAv();  // recalculate final grade
    return is;
}

