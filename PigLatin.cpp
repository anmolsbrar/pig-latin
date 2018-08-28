#include<iostream>
#include<sstream>
#include<string>
#include<limits>

using namespace std;

bool isWordVowel(string);
bool isVowel(char);
string rotateString(string);
string plString(string);
string reversePL(string);
string reverseRotate(string);
void engToPig(string);
void PigToEng(string);

int main()
{
    string inputString;
    int input;
    cout << "Enter 1 to convert English to Pig-Latin" << endl;
    cout << "Enter 2 to convert Pig-Latin to English" << endl;
    cin >> input;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //cin.ignore(1024, '\n');
    cout << "Enter a string: ";
    getline(cin, inputString);

    switch(input)
    {
    case 1:
        engToPig(inputString);
        break;
    case 2:
        PigToEng(inputString);
        break;
    default:
        cout << "Invalid input!" << endl;
    }
    return 0;
}

bool isVowel(char str)
{
    switch(str)
    {
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        return true;
    default:
        return false;
    }
}

string rotateString(string str)
{
    string rString;
    string::size_type length = str.length();
    rString = str.substr(1, length) + str[0];
    return rString;
}

string plString(string str)
{
    string::size_type length;
    bool vowel;
    int counter;

    if(isVowel(str[0]))
    {
        str = str + "-ay";
    }
    else
    {
        str = str + "-";
        str = rotateString(str);
        length = str.length();
        vowel = false;
        for(counter = 1; counter < length; counter++)
        {
            if(isVowel(str[0]))
            {
                vowel = true;
                break;
            }
            else
            {
                str = rotateString(str);
            }
        }
        if(!vowel)
        {
            str = rotateString(str) + "ay";
        }
        else
            str = str + "ay";
    }
    return str;
}

bool isWordVowel(string str)
{
    if(str.find("-ay") != string::npos)
    {
        return true;
    }
    else
    {
        return false;
    }
}

string reversePL(string str)
{
    string::size_type length;
    bool hyphenFound = false;
    if(isWordVowel(str))
    {
        length = str.rfind("-ay");
        str = str.substr(0, length);
    }
    else
    {
        length = str.rfind("ay");
        str = str.substr(0, length);
        while(!hyphenFound)
        {
            if(str[length] = '-')
            {
                hyphenFound = true;
            }
            str = reverseRotate(str);
        }
        length = str.find("-");
        str = str.substr(0, length);
    }
    return str;
}

string reverseRotate(string str)
{
    string::size_type length;
    length = str.length();
    str = str[length - 1] + str.substr(0, length - 1);
    return str;
}

void engToPig(string str)
{
    istringstream stream(str);
    while(stream >> str)
        cout << plString(str) << " ";
}

void PigToEng(string str)
{
    istringstream stream(str);
    while(stream >> str)
        cout << reversePL(str) << " ";
}
