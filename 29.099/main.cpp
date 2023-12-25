#include <iostream>
#include <fstream>
using namespace std;

bool validHTML(const char* kod) {
    ifstream proverka(kod);
    if (!proverka.is_open()) {
        cout << "Error opening file!" << endl;
        return false;
    }
    int openTag = 0;
    int closeTag = 0;
    char tags;
    bool twoTags = false;

    while (proverka.get(tags)) {
        if (tags == '<') {
            twoTags = true;
            openTag++;
        }
        else if (tags == '>') {
            if (twoTags) {
                closeTag++;
                twoTags = false;
            }
        }
    }
    proverka.close();
    return openTag == closeTag;
}

int main()
{
    cout << "Enter the path to the HTML file: ";
    string path;
    cin >> path;

    if (validHTML(path.c_str())) {
        cout << "The file is valid!" << endl;
    }
    else {
        cout << "File not valid! Try Again!!!" << endl;
    }
}