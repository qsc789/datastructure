#include<iostream>
#include<string>
#include"string.h"
using namespace std;
int main()
{
    String a,b;
    cin >> a.data;
    cin >> a.length;
    cin >> b.data;
    cin >> b.length;
    cout<<KMPMatch(a, b);
}