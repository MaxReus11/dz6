#include<fstream>
#include<string>
#include<iostream>
#include<regex>
int main()
{
    using namespace std;

    ifstream in("test.txt");
    if(!in.is_open()){
        cerr<<"Can't open \"test.txt\"!";
        exit(EXIT_FAILURE);
    }

    string file, tmp;
    while(getline(in, tmp))
    {
        file+=tmp;
        file+="\n";
    }
    regex pattern(R"(([\/][\/]([[:alnum:]]|[,._();"'{}[\]\/\*\\ ]){0,}\n|\r)|([\/][\*]([[:alnum:]]|[,._();"'{}[\]\/\\ ]|\n|\r|\t){0,}[\*][\/]))");
    file = regex_replace(file, pattern, "\n");
    regex pattern1(R"([\n]{1,})");
    file = regex_replace(file, pattern1, "\n");

    in.close();
    ofstream out("test.txt");
    out<<file;
    out.close();
    return 0;
}
