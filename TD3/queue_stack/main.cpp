#include <iostream>
#include <queue>
#include <stack>
#include <cctype>

using namespace std;

bool isPalindrome(const string &input)
{
    queue<char> charQueue;
    stack<char> charStack;

    for (char ch : input){
        if (isalnum(ch)){
            char lowerCh = tolower(ch);
            charQueue.push(lowerCh);
            charStack.push(lowerCh);
        }
    }

    while (!charQueue.empty()){
        if (charQueue.front() != charStack.top()){
            return false;
        }
        charQueue.pop();
        charStack.pop();
    }
    return true;
}

int main()
{
    cout << boolalpha;

    cout << "Is 'radar' a palindrome? - "
    << isPalindrome("radar") << endl;

    cout << "Is 'hello' a palindrome? "
    << isPalindrome("hello") << endl;

    return 0;
}