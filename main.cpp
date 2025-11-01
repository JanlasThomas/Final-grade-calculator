#include"Person.h"
#include"Lib.h"

int main()
{
    ifstream file("Students.txt");
    if (!file)
    {
        cerr << "Failed to open Students.txt ";
    }


    string header;
    getline(file, header);

    vector <Person> students;
    Person temp;

    while (file >> temp)

    {
        students.push_back(temp);
    }
    // sorting by firstname
    std::sort(students.begin(), students.end(), [](const Person& a, const Person& b) {
        return a.firstname < b.firstname;

    });



    // Output
    cout << left << setw(15) << "Name" << setw(15) << "Surname" << setw(20) << "Final (Avg.)" << setw(5) << "|" << "Final (Med.)" << endl;
    cout << "--------------------------------------------------------------------" << endl;
    for (const auto &s : students) {cout << s << endl;
    }

    return 0;
}

