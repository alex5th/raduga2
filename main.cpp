#include <iostream>
#include <QStack>
#include <QList>

using namespace std;

QStack<char> input()
{
    QStack<char> tempSt;
    char temp = ' ';
    while (temp != '\n')
    {
        cin.get(temp);
        tempSt.push(temp);
    }
    tempSt.pop_back();
    return tempSt;
}

QList<char> operator +(QStack<char> x, QStack<char> y)
{
    QList<char> tempL;
    bool unit = false;
    while (!x.isEmpty() || !y.isEmpty())
    {
        int temp = 0;
        if (!x.isEmpty()) temp += x.pop() - '0';
        if (!y.isEmpty()) temp += y.pop() - '0';
        if (unit)
        {
            temp += 1;
            unit = false;
        }
        if (temp > 9)
        {
            temp -= 10;
            unit = true;
        }
        tempL.push_front(temp + '0');
    }
    if (unit) tempL.push_front('1');
    return tempL;
}


int main()
{
    QStack<char> int1 = input();
    QStack<char> int2 = input();
    QList<char> z = int1 + int2;
    for (auto i: z)
        cout <<i;
    return 0;
}
