#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str1;
    getline(cin, str1);
    int i;
    cin >> i;
    cin.ignore();
    string str2;
    int j;
    cin >> j;
    cin.ignore();
    getline(cin, str2);
    cout << str1 << " " << str2;
    return 0;
}