
#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <vector>

using namespace std;

struct stDate
{
    short Year;
    short Month;
    short Day;
};

string ReadStringDate(string Message)
{
    string DateString;

    cout << Message;
    getline(cin >> ws, DateString);

    return DateString;
};

vector <string> SplitString(string S1, string delim)
{
    vector <string> vString;
    short Pos = 0;
    string sWord;
    while ((Pos = S1.find(delim)) != std::string::npos)
    {
        sWord = S1.substr(0, Pos);
        if (sWord != " ")
        {
            vString.push_back(sWord);
        }
        S1.erase(0, Pos + delim.length());
    }
    if (S1 != " ")
    {
        vString.push_back(S1);
    }
    return vString;
};

stDate StringToDateStructure(string DateString)
{
    stDate Date;
    vector <string> vDate;

    vDate = SplitString(DateString, "/");
    Date.Day = stoi(vDate[0]);
    Date.Month = stoi(vDate[1]);
    Date.Year = stoi(vDate[2]);

    return Date;
};

string DateToString(stDate Date, string separator = "/")
{
    string stringDate = "";
    
    stringDate += to_string(Date.Day) + separator;
    stringDate += to_string(Date.Month) + separator;
    stringDate += to_string(Date.Year);

    return stringDate;
}

int main()
{
    
    string stringDate = ReadStringDate("Please Enter Date dd/mm/yyyy?  ");

    stDate Date = StringToDateStructure(stringDate);

    cout << "\nDay: " << Date.Day << "\nMonth: " << Date.Month << "\nYear: " << Date.Year;

    cout << "\n\nYou Entered: " << DateToString(Date, "/");
    system("pause>0");
    return 0;
}
