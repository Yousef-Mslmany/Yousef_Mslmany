#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

enum enGameChoice { Stone = 1, Paper = 2, Scissors = 3 };
enum enWinner { Player = 1, Computer = 2, Draw = 3 };

struct stRoundInfo 
{
    short RoundNumber;
    enGameChoice PlayerChoice;
    enGameChoice ComputerChoice;
    enWinner Winner;
    string WinnerName;
};

struct stGameResults 
{
    short GameRounds = 0;
    short PlayerWinTimes = 0;
    short ComputerWinTimes = 0;
    short DrawTimes = 0;
    enWinner GameWinner;
    string GameWinnerName;
};

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

string WinnerName(enWinner Winner)
{
    string arrWinnerName[3] = { "Player", "Computer", "Draw" };
    return arrWinnerName[Winner - 1];
}

enWinner WhoWonTheRound(stRoundInfo RoundInfo)
{
    if (RoundInfo.PlayerChoice == RoundInfo.ComputerChoice)
    {
        return enWinner::Draw;
    }

    switch (RoundInfo.PlayerChoice) 
    {
    case enGameChoice::Stone:
        if (RoundInfo.ComputerChoice == enGameChoice::Paper) 
        {
            return enWinner::Computer;
        }
        break;
    case enGameChoice::Paper:
        if (RoundInfo.ComputerChoice == enGameChoice::Scissors) 
        {
            return enWinner::Computer;
        }
        break;
    case enGameChoice::Scissors:
        if (RoundInfo.ComputerChoice == enGameChoice::Stone)
        {
            return enWinner::Computer;
        }
        break;
    }

    return enWinner::Player;
}

string ChoiceName(enGameChoice Choice) 
{
    string arrGameChoices[3] = { "Stone", "Paper", "Scissors" };
    return arrGameChoices[Choice - 1];
}

void SetWinnerScreenColor(enWinner Winner) 
{
    switch (Winner) 
    {
    case enWinner::Player:
        system("color 2F"); // Green
        break;
    case enWinner::Computer:
        system("color 4F"); // Red
        cout << "\a"; // Beep sound
        break;
    case enWinner::Draw:
        system("color 6F"); // Yellow
        break;
    }
}

void PrintRoundResult(stRoundInfo RoundInfo) 
{
    cout << "\n____________Round [" << RoundInfo.RoundNumber << "]____________\n\n";
    cout << "Player Choice  : " << ChoiceName(RoundInfo.PlayerChoice) << endl;
    cout << "Computer Choice: " << ChoiceName(RoundInfo.ComputerChoice) << endl;
    cout << "Round Winner   : [" << RoundInfo.WinnerName << "]\n";
    cout << "__________________________________\n" << endl;

    SetWinnerScreenColor(RoundInfo.Winner);
}

enWinner WhoWonTheGame(short PlayerWinTimes, short ComputerWinTimes) 
{
    if (PlayerWinTimes > ComputerWinTimes)
        return enWinner::Player;
    else if (ComputerWinTimes > PlayerWinTimes)
        return enWinner::Computer;
    else
        return enWinner::Draw;
}

stGameResults FillGameResults(int GameRounds, int PlayerWinTimes, int ComputerWinTimes, int DrawTimes) 
{
    stGameResults GameResults;
    GameResults.GameRounds = GameRounds;
    GameResults.PlayerWinTimes = PlayerWinTimes;
    GameResults.ComputerWinTimes = ComputerWinTimes;
    GameResults.DrawTimes = DrawTimes;
    GameResults.GameWinner = WhoWonTheGame(PlayerWinTimes, ComputerWinTimes);
    GameResults.GameWinnerName = WinnerName(GameResults.GameWinner);

    return GameResults;
}

enGameChoice ReadPlayerChoice()
{
    short Choice = 0;
    do 
    {
        cout << "\nYour Choice: [1]Stone, [2]Paper, [3]Scissors? ";
        cin >> Choice;
    } while (Choice < 1 || Choice > 3);

    return (enGameChoice)Choice;
}

enGameChoice GetComputerChoice()
{
    return (enGameChoice)RandomNumber(1, 3);
}

stGameResults PlayGame(short HowManyRounds)
{
    stRoundInfo RoundInfo;
    short PlayerWinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;

    for (short i = 1; i <= HowManyRounds; i++)
    {
        cout << "\nRound [" << i << "] begins:\n";
        RoundInfo.RoundNumber = i;
        RoundInfo.PlayerChoice = ReadPlayerChoice();
        RoundInfo.ComputerChoice = GetComputerChoice();
        RoundInfo.Winner = WhoWonTheRound(RoundInfo);
        RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);

        if (RoundInfo.Winner == enWinner::Player)
            PlayerWinTimes++;
        else if (RoundInfo.Winner == enWinner::Computer)
            ComputerWinTimes++;
        else
            DrawTimes++;

        PrintRoundResult(RoundInfo);
    }

    return FillGameResults(HowManyRounds, PlayerWinTimes, ComputerWinTimes, DrawTimes);
}

string Tabs(short NumberOfTabs)
{
    string t;
    for (int i = 0; i < NumberOfTabs; i++)
        t += "\t";
    return t;
}

void ShowGameOverScreen()
{
    cout << Tabs(2) << "__________________________________________________________\n";
    cout << Tabs(2) << "                 +++ G a m e  O v e r +++\n";
    cout << Tabs(2) << "__________________________________________________________\n";
}

void ShowFinalGameResults(stGameResults GameResults) 
{
    cout << Tabs(2) << "_____________________[Game Results]_____________________\n\n";
    cout << Tabs(2) << "Game Rounds        : " << GameResults.GameRounds << endl;
    cout << Tabs(2) << "Player won times   : " << GameResults.PlayerWinTimes << endl;
    cout << Tabs(2) << "Computer won times : " << GameResults.ComputerWinTimes << endl;
    cout << Tabs(2) << "Draw times         : " << GameResults.DrawTimes << endl;
    cout << Tabs(2) << "Final Winner       : " << GameResults.GameWinnerName << endl;
    cout << Tabs(2) << "________________________________________________________\n\n";
}

short ReadHowManyRounds() 
{
    short Rounds;
    do
    {
        cout << "How Many Rounds (1 to 10)? ";
        cin >> Rounds;
    } while (Rounds < 1 || Rounds > 10);

    return Rounds;
}

void ResetScreen()
{
    system("cls");
    system("color 0F");
}

void StartGame() 
{
    char PlayAgain;
    do 
    {
        ResetScreen();
        stGameResults GameResults = PlayGame(ReadHowManyRounds());
        ShowGameOverScreen();
        ShowFinalGameResults(GameResults);

        cout << endl << Tabs(3) << "Do you want to play again? Y/N? ";
        cin >> PlayAgain;
    } while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main() 
{
    srand((unsigned)time(NULL));
    StartGame();
    return 0;
}