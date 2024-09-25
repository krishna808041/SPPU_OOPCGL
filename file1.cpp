#include<fstream>
#include<iostream>
using namespace std;

class person{
private:
    char name[80];
    int age;
public:
    void getData(){
        cout<<"Enter Name :"; cin>>name;
        cout<<"Enter the age:"; cin>>age;
    }

    void showData (){
        cout<<"Name:"<<name<<endl;
        cout<<"Age :"<<age<<endl;
    }
};

int main(){
    char ch;
    person obj;
    fstream file; // corrected typo: fstrteam -> fstream
    file.open("INFO.txt", ios::app | ios::out | ios::in | ios::binary );
    
    do{
        cout<<"Enter the person Info :"<<endl;
        obj.getData(); // corrected: cin>>obj.getData(); -> obj.getData();
        file.write(reinterpret_cast<char*>(&obj), sizeof(obj));
        
        cout<<"Want to insert the next Info (y,n) : ";
        cin>>ch;
    }while(ch=='y');
    
    file.seekg(0);
    file.read(reinterpret_cast<char*>(&obj), sizeof(obj));
    while(!file.eof() ){
        cout<<"Person";
        obj.showData();
        file.read(reinterpret_cast<char*>(&obj), sizeof(obj));
    }
    cout<<endl;
    return 0;
}
