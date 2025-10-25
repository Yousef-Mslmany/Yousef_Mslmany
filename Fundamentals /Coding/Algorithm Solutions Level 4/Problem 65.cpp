
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

string ReplaceWordInString(string S1, string WordToReplace, string ToReplace)
{
    short Pos = S1.find(WordToReplace);
    while (Pos != std::string::npos)
    {
        S1.replace(Pos, WordToReplace.length(), ToReplace);
        Pos = S1.find(WordToReplace);
    }
    return S1;
};

string FormatDate(stDate Date, string Format = "dd/mm/yyyy")
{
    string FormattedDateString = "";

    FormattedDateString = ReplaceWordInString(Format, "dd", to_string(Date.Day));
    FormattedDateString = ReplaceWordInString(FormattedDateString, "mm", to_string(Date.Month));
    FormattedDateString = ReplaceWordInString(FormattedDateString, "yyyy", to_string(Date.Year));

    return FormattedDateString;
}

int main()
{

    string DateString = ReadStringDate("Please Enter Date dd/mm/yyyy?  ");

    stDate Date = StringToDateStructure(DateString);

    cout << "\n" << FormatDate(Date) << "\n";

    cout << "\n" << FormatDate(Date, "yyyy/mm/dd") << "\n";

    cout << "\n" << FormatDate(Date, "mm/dd/yyyy") << "\n";

    cout << "\n" << FormatDate(Date, "mm-dd-yyyy") << "\n";

    cout << "\n" << FormatDate(Date, "dd-mm-yyyy") << "\n";

    cout << "\n" << FormatDate(Date, "Day=dd, Month=mm, Year=yyyy") << "\n";

    system("pause>0");
    return 0;
}
