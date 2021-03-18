#include <iostream>
#include <fstream>
#include <string>

int main()
{
    using namespace std;
    ifstream in("file.txt");

    if (!in)
    {
        cerr << "Can't open \"file.txt\"!" << endl;
        exit(1);
    }
    int n;
    cout<<"Enter the number of line you want to read\n";
    cin>>n;
    in.seekg((n-1)*21, ios::beg);
    string line;
    getline(in, line);
    cout<<line<<endl;
    return 0;
