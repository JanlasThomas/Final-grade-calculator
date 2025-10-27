// Temp2025en.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include"Person.h"
#include"Lib.h"

int main()
{
 int num_students;
    cout << "Enter number of students: ";
    cin >> num_students;
    vector<Person> students(num_students);

    for (int i = 0; i < num_students; ++i) {
        cout << "\nEnter data for student #" << i + 1 << ":\n";
        cin >> students[i];
    }


    // Output
    cout << left << setw(15) << "Name" << setw(15) << "Surname" << setw(20) << "Final_Point" << endl;
    cout << "------------------------------------------------------" << endl;
    for (const auto &s : students) {
        cout << left << setw(15) << s.firstname << setw(15) << s.surname
             << fixed << setprecision(2) << setw(20) << s.Finalgrade << endl;
    }

    return 0;
}
