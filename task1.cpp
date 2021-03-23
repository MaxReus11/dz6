#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>

int main()
{
    using namespace std;
    fstream fin("test.txt", ios::in);
    if(!fin.is_open()){
        cerr<<"Can't open \"test.txt\"!";
        exit(EXIT_FAILURE);
    }
    string text{
            istreambuf_iterator<char>(fin), istreambuf_iterator<char>() };
    string result;
    string::iterator count=text.begin(), first=text.begin(), last=text.begin();
    fin.close();
    while (count < text.end()-2) {
        if (*count == '"' && *(count-1)!='\\') {
            bool i = false;
            while (!i) {
                count = find(count + 1, text.end(), '"');
                if (*(count-1 ) == '\\') {
                }
                else
                    i = true;
            }
            count++;
        }

        if (*count == '/' && *(count + 1) == '/') {
            last = count;
            result.append(first, last);
            first = find(count, text.end(), '\n');
            count = first;
        }
        if (*count == '/' && *(count + 1) == '*') {
            last = count;
            result.append(first, last);
            count += 2;
            {
                bool i = false;
                while (!i && count<text.end()-1) {
                    count = find(count, text.end(), '*');
                    if (*(count + 1) == '/') {
                        first = count+2;
                        i = true;
                    }
                    else count++;
                }
            }

        }
        else  count++;
    }
    fstream fout("test.txt", ios::out);
    fout<< result;
}
