#include"Person.h"
#include"Lib.h"

int main()
{

    //filegenerator ("students10000.txt",10000);
    //filegenerator ("students100000.txt",100000);
    //filegenerator ("students1000000.txt",1000000);
    //filegenerator ("students10000000.txt",10000000);

    list <Person> pass;
    list <Person> fail;

    Timer timer;

    try {
        timer.timestart();

        ifstream file("students.txt");
cout<<"Time taken to read file : " << endl;
        timer.timetaken();

        if (!file) {
            throw runtime_error("Failed to open Students.txt");
        }

        string header;

       if (!getline(file, header)){ throw runtime_error ( " Failed to read the header row") ; }

        list<Person> students;
        Person temp;

        while (file >> temp) {
            students.push_back(temp);
        }
        timer.timestart();
        // sorting by firstname
        students.sort([](const Person& a, const Person& b) {
    return a.firstname < b.firstname;
});
cout<<"Time taken to sort file : " << endl;
       timer.timetaken();

        timer.timestart();
        for (const auto& s : students) {
            if( (s.FinalgradeAvg >= 5 )|| (s.FinalgradeMed >= 5)  )
            {
                pass.push_back(s);
            }
            else{ fail.push_back(s);}
       }

       cout<<"Time taken to split file : " << endl;
 timer.timetaken();

timer.timestart();
        // Output
        cout << "PASSED" << endl;
       outputtemplate();

       ofstream passout("passed.txt"), failedout ( "failed.txt");
       passout << left << setw(15) << "Name" << setw(15) << "Surname"
             << setw(20) << "Final (Avg.)" << setw(5) << "|" << "Final (Med.)" << endl;

             failedout<< left << setw(15) << "Name" << setw(15) << "Surname"
             << setw(20) << "Final (Avg.)" << setw(5) << "|" << "Final (Med.)" << endl;

       for (const auto& s : pass)
       {
           passout << s;
           cout<<s<<endl;
       }
       cout << "FAILED" << endl;
        outputtemplate();

       for (const auto& s : fail)
       {
           failedout << s;
           cout<<s<<endl;
       }

       cout<<"Time taken to output two new files : " << endl;
 timer.timetaken();

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}

