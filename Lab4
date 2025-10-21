//
//  main.cpp
//  DSA_4
//
//  Created by Aiman Moufid on 10/21/25.
//

/*#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
using namespace std;
struct StudentAddress{
    int emplid;
    string name;
    int number;
    int zip;
    
    bool operator<(const StudentAddress& other)const{
        return zip < other.zip;
    }
};

int main()
{
    unordered_map<int, StudentAddress> records;
    records[123456] =  StudentAddress{12356, "Victory", 25, 10203};
    records[123459] =  StudentAddress{12356, "Manor", 54, 10203};
    records[123455] =  StudentAddress{12356, "Jewet", 31, 10203};
    
    StudentAddress& student1 = records[123458];// get record, if not there, it will be inserted.
    student1.name = "Hylan";
    student1.number = 123;
    student1.zip = 10320;
    student1.emplid = 123458;
    
    
    //get ther record, will not insert
    //will crash if not in the table, check first
    if(records.find(123451) != records.end())
    {
        StudentAddress& student2 = records.at(123451);
    }
    
    for (auto& data: records){
        int id = data.first;
        StudentAddress& student3 = data.second;
    }
    for (auto& [id, address]: records)
    {
        cout << "Student ID " << id << endl;
        cout << "Address: " << address.number<< " " << address.name << " " << address.zip << endl;
    }
    
    
 }*/
#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;
struct Countries{
    string name;
    int pop;
    
};

int main()
{
    unordered_map<string, Countries> population;
    population["Canada"] = Countries{"Canada", 3};
    population["Latvia"] = Countries{"Latvia", 2};
    population["Macedonia"] = Countries{"Macedonia", 4};
    population["Antarctica"] = Countries{"Antarctica", 0};
    population["Mongolia"] = Countries{"Mongolia", 1};
    
    for (auto& [country_name, full_struct]: population)
    {
        cout << "country name key:  " << country_name << endl;
        cout << "within the key: " << full_struct.name<< " " << full_struct.pop << endl;
    }
    string country_name;
    cout << "Type Country Name\n>";
    cin >>country_name;
    if(population.find(country_name) != population.end())
    {
        Countries& searching = population.at(country_name);
        cout << searching.name << " " << searching.pop;
    }
    
    cout << endl<< "PART 2, this is Part 2, because Part 2 is yessir\n\ntype a sentence\n>";
    cin>>country_name;
    stringstream ss(country_name);
    string word;
    unordered_map<string, int> sentence;
    while(ss >> word)
    {
        sentence[word]++;
    }
    
    for (auto& [id, address] : sentence)
    {
        string stringtemp = id;
        int temp = address;
        cout << stringtemp << " " << temp+1 << endl;
    }
    
}

