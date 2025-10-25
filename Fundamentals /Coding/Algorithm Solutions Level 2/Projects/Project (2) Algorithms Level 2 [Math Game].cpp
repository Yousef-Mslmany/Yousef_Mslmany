#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

enum enQuestionLevel { Easy = 1, Med = 2, Hard = 3, Mix = 4 };
enum enOpeationType { Add = 1, Sub = 2, Mul = 3, Div = 4, MixOp = 5 };

struct stQuestion
{
    int Number1 = 0;
    int Number2 = 0;
    enQuestionLevel QuestionLevel;
    enOpeationType OpeationType;
    int CorrectAnswer = 0;
    int PlayerAnswer = 0;
    bool AnswerResult = false;
};

struct stQuizz
{
    stQuestion QuestionList[100];
    short NumberofQuestions;
    enQuestionLevel QuestionLevel;
    enOpeationType OpeationType;
    short NumberofRightAnswers = 0;
    short NumberofWrongAnswers = 0;
    bool isPass = false;
};

enQuestionLevel ReadQuestionsLevel()
{
    short Level;
    do
    {
        cout << "Enter Question Level [1] Easy, [2] Med, [3] Hard, [4] Mix? ";
        cin >> Level;
    } while (Level < 1 || Level > 4);

    return (enQuestionLevel)Level;
}

enOpeationType ReadOpeartionType()
{
    short Type;
    do
    {
        cout << "Enter Operation Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix? ";
        cin >> Type;
    } while (Type < 1 || Type > 5);

    return (enOpeationType)Type;
}

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

string GetOpeationTypeSymbol(enOpeationType OpeationType)
{
    switch (OpeationType)
    {
    case enOpeationType::Add:
        return "+";
    case enOpeationType::Sub:
        return "-";
    case enOpeationType::Mul:
        return "*";
    case enOpeationType::Div:
        return "/";
    default:
        return "Mix";
    }
}

string GetQuestionLevelText(enQuestionLevel Level)
{
    string arrGameLevels[4] = { "Easy", "Med", "Hard", "Mix" };
    return arrGameLevels[Level - 1];
}

void SetScreenColors(bool Right)
{
    if (Right)
    {
        system("color 2F");
    }
    else
    {
        system("color 4F");
        system("\a");
    }
}

int SimpleCalculator(int Number1, int Number2, enOpeationType OpeationType)
{
    switch (OpeationType)
    {
    case enOpeationType::Add:
        return Number1 + Number2;
    case enOpeationType::Sub:
        return Number1 - Number2;
    case enOpeationType::Mul:
        return Number1 * Number2;
    case enOpeationType::Div:
        return Number1 / Number2;
    default:
        return Number1 + Number2;
    }
}

enOpeationType GetRandomOpeationType()
{
    int Op = RandomNumber(1, 4);
    return (enOpeationType)Op;
}

stQuestion GenerateQuestion(enQuestionLevel QuestionLevel, enOpeationType OpeationType)
{
    stQuestion Question;

    if (QuestionLevel == enQuestionLevel::Mix)
    {
        QuestionLevel = (enQuestionLevel)RandomNumber(1, 3);
    }

    if (OpeationType == enOpeationType::MixOp)
    {
        OpeationType = GetRandomOpeationType();
    }

    Question.OpeationType = OpeationType;
    Question.QuestionLevel = QuestionLevel;

    switch (QuestionLevel)
    {
    case enQuestionLevel::Easy:
        Question.Number1 = RandomNumber(1, 10);
        Question.Number2 = RandomNumber(1, 10);
        break;
    case enQuestionLevel::Med:
        Question.Number1 = RandomNumber(10, 50);
        Question.Number2 = RandomNumber(10, 50);
        break;
    case enQuestionLevel::Hard:
        Question.Number1 = RandomNumber(50, 100);
        Question.Number2 = RandomNumber(50, 100);
        break;
    }

    Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OpeationType);
    return Question;
}

void GenerateQuizzQuestions(stQuizz& Quizz)
{
    for (short Question = 0; Question < Quizz.NumberofQuestions; Question++)
    {
        Quizz.QuestionList[Question] = GenerateQuestion(Quizz.QuestionLevel, Quizz.OpeationType);
    }
}

short ReadHowManyQuestions()
{
    short Rounds;
    do
    {
        cout << "How many Questions do you want to answer (1-10)? ";
        cin >> Rounds;
    } while (Rounds < 1 || Rounds > 10);

    return Rounds;
}

void PrintTheQuestion(stQuizz& Quizz, short QuestionNumber)
{
    cout << "\nQuestion[" << QuestionNumber + 1 << "/" << Quizz.NumberofQuestions << "]\n\n";
    cout << Quizz.QuestionList[QuestionNumber].Number1 << endl;
    cout << Quizz.QuestionList[QuestionNumber].Number2 << " ";
    cout << GetOpeationTypeSymbol(Quizz.QuestionList[QuestionNumber].OpeationType);
    cout << "\n_________" << endl;
}

void CorrectTheQuestionAnswer(stQuizz& Quizz, short QuestionNumber)
{
    if (Quizz.QuestionList[QuestionNumber].PlayerAnswer != Quizz.QuestionList[QuestionNumber].CorrectAnswer)
    {
        Quizz.QuestionList[QuestionNumber].AnswerResult = false;
        Quizz.NumberofWrongAnswers++;

        cout << "Wrong Answer :-(\n";
        cout << "The Right Answer is: ";
        cout << Quizz.QuestionList[QuestionNumber].CorrectAnswer << endl;
    }
    else
    {
        Quizz.QuestionList[QuestionNumber].AnswerResult = true;
        Quizz.NumberofRightAnswers++;

        cout << "Right Answer :-)\n";
    }
    cout << endl;

    SetScreenColors(Quizz.QuestionList[QuestionNumber].AnswerResult);
}

int ReadQuestionAnswer()
{
    int Answer = 0;
    cin >> Answer;
    return Answer;
}

void AskAndCorrectQuestionListAnswers(stQuizz& Quizz)
{
    for (short QuestionNumber = 0; QuestionNumber < Quizz.NumberofQuestions; QuestionNumber++)
    {
        PrintTheQuestion(Quizz, QuestionNumber);
        Quizz.QuestionList[QuestionNumber].PlayerAnswer = ReadQuestionAnswer();
        CorrectTheQuestionAnswer(Quizz, QuestionNumber);
    }
    Quizz.isPass = (Quizz.NumberofRightAnswers >= Quizz.NumberofWrongAnswers);
}

string GetFinalResultsText(bool Pass)
{
    if (Pass)
        return "PASS :-)";
    else
        return "Fail :-(";
}

void PrintQuizzResults(stQuizz Quizz)
{
    cout << "\n";
    cout << "______________________________\n\n";
    cout << "Final Results is " << GetFinalResultsText(Quizz.isPass);
    cout << "\n______________________________\n\n";
    cout << "Number of Questions: " << Quizz.NumberofQuestions << endl;
    cout << "Question Level     : " << GetQuestionLevelText(Quizz.QuestionLevel) << endl;
    cout << "Operation Type    : " << GetOpeationTypeSymbol(Quizz.OpeationType) << endl;
    cout << "Number of Right Answers: " << Quizz.NumberofRightAnswers << endl;
    cout << "Number of Wrong Answers: " << Quizz.NumberofWrongAnswers << endl;
    cout << "______________________________\n\n";
}

void PlayGame()
{
    stQuizz Quizz;
    Quizz.NumberofQuestions = ReadHowManyQuestions();
    Quizz.QuestionLevel = ReadQuestionsLevel();
    Quizz.OpeationType = ReadOpeartionType();

    GenerateQuizzQuestions(Quizz);
    AskAndCorrectQuestionListAnswers(Quizz);
    PrintQuizzResults(Quizz);
}

void ResetScreen()
{
    system("cls");
    system("color 0F");
}

void StartGame()
{
    char PlayAgain = 'Y';

    do
    {
        ResetScreen();
        PlayGame();

        cout << "Do you want to play again? (Y/N): ";
        cin >> PlayAgain;

    } while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main()
{
    srand((unsigned)time(NULL));
    StartGame();
    return 0;
}