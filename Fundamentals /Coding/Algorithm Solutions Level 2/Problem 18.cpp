//This is a soultion to the Problem #18.
#include <iostream>
#include <string>
using namespace std;
string Read_Text()
{
    string Text;
    cout << "Please enter Text: " << endl;
    cin >> Text;

    return Text;
};
string Encrypt_Text(string Text, short Encryption_Key)
{
    for (int i = 0; i < Text.length(); i++)
    {
        Text[i] = char((int)Text[i] + Encryption_Key);
    }
    return Text;
};
string Decrypt_Text(string Text, short Encryption_Key)
{
    for (int i = 0; i < Text.length(); i++)
    {
        Text[i] = char((int)Text[i] - Encryption_Key);
    }
    return Text;
};
int main()
{
    const short Encryption_Key = 2;

    string Text = Read_Text();
    string Text_After_Encryption = Encrypt_Text(Text, Encryption_Key);
    string Text_After_Decryption = Decrypt_Text(Text_After_Encryption, Encryption_Key);

    cout << "Text Before Encryption : " << Text << endl;
    cout << "Text After Encryption : " << Text_After_Encryption << endl;
    cout << "Text After Decryption : " << Text_After_Decryption << endl;
}
