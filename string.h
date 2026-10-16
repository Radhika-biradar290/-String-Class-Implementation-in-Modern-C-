#ifndef STRING_H
#define STRING_H

#include <iostream>
using namespace std;

class String
{
    char *data;
    int length;

public:
    String();
    String(const char *);
    String(const String &);
    ~String();

    String& operator=(const String &);
    String operator+(const String &);
    char& operator[](int);

    bool operator==(const String &);
    bool operator!=(const String &);
    bool operator<(const String &);
    bool operator>(const String &);
    bool operator<=(const String &);
    bool operator>=(const String &);

    friend ostream& operator<<(ostream &, const String &);
    friend istream& operator>>(istream &, String &);

    friend void strcpy(String &, const String &);
    friend void strncpy(String &, const String &, int);
    friend int strcmp(const String &, const String &);
    friend int strncmp(const String &, const String &, int);
    friend void strcat(String &, const String &);
    friend void strncat(String &, const String &, int);
    friend void strrev(String &);
    friend void strupr(String &);
    friend void strlwr(String &);
    friend int strchr(const String &, char);
    friend int strrchr(const String &, char);
    friend int strstr(const String &, const char *);
    friend int strlen(const String &);
};

#endif
