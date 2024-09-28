// Problem Statement
    
#include <iostream>
#include <string>
using namespace std;

class StudData; 

class Student {
    string name;
    int roll_no;
    string cls;
    string division; 
    string dob;
    string bloodgroup; 
    static int count;

public:
    Student() {
        name = "";
        roll_no = 0;
        cls = "";
        division = "dd/mm/yyyy"; 
        bloodgroup = ""; 
    }
    
    ~Student() {
    }
    
    static int getCount() {
        return count;
    }
    
    void getData(StudData*);
    void dispData(StudData*);
};

class StudData {
    string caddress;
    long* telno;
    long* dlno;  
    friend class Student;

public:
    StudData() {
        caddress = "";
        telno = new long; 
        dlno = new long;  
    }
    
    ~StudData() {
        delete telno; 
        delete dlno;  
    }
    
    void getStudData() {
        cout << "Enter Contact Address: ";
        cin.ignore(); 
        getline(cin, caddress); 
        cout << "Enter Telephone Number: ";
        cin >> *telno; 
        cout << "Enter Driving License Number: ";
        cin >> *dlno;
    }
    
    void dispStudData() {
        cout << "Contact Address: " << caddress << endl;
        cout << "Telephone Number: " << *telno << endl;
        cout << "Driving License Number: " << *dlno << endl;
    }
};

inline void Student::getData(StudData* st) {
    cout << "Enter Student Name: ";
    getline(cin, name);
    cout << "Enter Roll Number: ";
    cin >> roll_no;
    cout << "Enter Class: ";
    cin.ignore();
    getline(cin, cls);
    cout << "Enter Division: ";
    cin >> division;
    cout << "Enter Date of Birth: ";
    cin.ignore();
    getline(cin, dob);
    cout << "Enter Blood Group: ";
    cin >> bloodgroup;
    st->getStudData();
    count++;
}

inline void Student::dispData(StudData* st1) {
    cout << "Student Name: " << name << endl;
    cout << "Class: " << cls << endl;
    cout << "Roll Number: " << roll_no << endl;
    cout << "Division: " << division << endl;
    cout << "Date of Birth: " << dob << endl;
    cout << "Blood Group: " << bloodgroup << endl;
    st1->dispStudData(); 
}

int Student::count = 0; 

int main() {
    Student* stud1[100]; 
    StudData* stud2[100]; 
    int n = 0;
    char ch;

    do {
        stud1[n] = new Student;
        stud2[n] = new StudData;
        stud1[n]->getData(stud2[n]); 
        n++;
        cout << "Do you want to add another student (y/n): ";
        cin >> ch;
        cin.ignore(); 
    } while (ch == 'y' || ch == 'Y');

    for (int i = 0; i < n; i++) {
        cout << "--------------" << endl;
        stud1[i]->dispData(stud2[i]); 
    }

    cout << "-------------------------------" << endl;
    cout << "Total Students: " << Student::getCount() << endl; 
    cout << "-------------------------------" << endl;

    for (int i = 0; i < n; i++) {
        delete stud1[i]; 
        delete stud2[i]; 
    }
    
    return 0;
}

