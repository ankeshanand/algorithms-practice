#include<iostream>
#include<string>
#include<sstream>
#include<cstdlib>
#include<cstdio>
using namespace std;
int main()
{
    int i;
    string str;
    
    /*Method 1 - Convert string to Int using sprintf (Fast) */
    char buffer[10];
    sprintf(buffer,"%d",i);
    str = string(buffer);
    cout << str << endl;
    
    /*Method 2 - Convert string to Int using stringstream (Slow) */
    stringstream ss;
    ss << i;
    str = ss.str();
    cout << str << endl;
    
    /* Covert string to int using atoi */
    i = atoi(str.c_str());
}
