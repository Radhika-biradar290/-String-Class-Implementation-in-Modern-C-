#include "String.h"

String::String()
{
    length = 0;
    data = new char[1];
    data[0] = '\0';
}

String::String(const char *s)
{
    length = 0;

    while (s[length] != '\0')
        length++;

    data = new char[length + 1];

    for (int i = 0; i < length; i++)
        data[i] = s[i];

    data[length] = '\0';
}

String::String(const String &s)
{
    length = s.length;
    data = new char[length + 1];

    for (int i = 0; i < length; i++)
        data[i] = s.data[i];

    data[length] = '\0';
}

String::~String()
{
    delete[] data;
}

String& String::operator=(const String &s)
{
    if (this != &s)
    {
        delete[] data;

        length = s.length;
        data = new char[length + 1];

        for (int i = 0; i < length; i++)
            data[i] = s.data[i];

        data[length] = '\0';
    }

    return *this;
}

String String::operator+(const String &s)
{
    String temp;
    delete[] temp.data;

    temp.length = length + s.length;
    temp.data = new char[temp.length + 1];

    int i = 0;

    for (int j = 0; j < length; j++)
        temp.data[i++] = data[j];

    for (int j = 0; j < s.length; j++)
        temp.data[i++] = s.data[j];

    temp.data[i] = '\0';

    return temp;
}

char& String::operator[](int index)
{
    return data[index];
}

bool String::operator==(const String &s)
{
    if (length != s.length)
        return false;

    for (int i = 0; i < length; i++)
        if (data[i] != s.data[i])
            return false;

    return true;
}

bool String::operator!=(const String &s)
{
    return !(*this == s);
}

bool String::operator<(const String &s)
{
    int i = 0;

    while (data[i] && s.data[i])
    {
        if (data[i] < s.data[i]) return true;
        if (data[i] > s.data[i]) return false;
        i++;
    }

    return length < s.length;
}

bool String::operator>(const String &s)
{
    int i = 0;

    while (data[i] && s.data[i])
    {
        if (data[i] > s.data[i]) return true;
        if (data[i] < s.data[i]) return false;
        i++;
    }

    return length > s.length;
}

bool String::operator<=(const String &s)
{
    return (*this < s || *this == s);
}

bool String::operator>=(const String &s)
{
    return (*this > s || *this == s);
}

ostream& operator<<(ostream &out, const String &s)
{
    out << s.data;
    return out;
}

istream& operator>>(istream &in, String &s)
{
    char temp[100];

    in >> temp;

    delete[] s.data;

    s.length = 0;

    while (temp[s.length] != '\0')
        s.length++;

    s.data = new char[s.length + 1];

    for (int i = 0; i < s.length; i++)
        s.data[i] = temp[i];

    s.data[s.length] = '\0';

    return in;
}

void strcpy(String &s2, const String &s1)
{
    delete[] s2.data;

    s2.length = s1.length;
    s2.data = new char[s2.length + 1];

    for (int i = 0; i < s2.length; i++)
        s2.data[i] = s1.data[i];

    s2.data[s2.length] = '\0';
}

void strncpy(String &s2, const String &s1, int n)
{
    int count = 0;

    while (count < n && s1.data[count])
        count++;

    delete[] s2.data;

    s2.length = count;
    s2.data = new char[count + 1];

    for (int i = 0; i < count; i++)
        s2.data[i] = s1.data[i];

    s2.data[count] = '\0';
}

int strcmp(const String &s1, const String &s2)
{
    int i = 0;

    while (s1.data[i] && s2.data[i])
    {
        if (s1.data[i] > s2.data[i]) return 1;
        if (s1.data[i] < s2.data[i]) return -1;
        i++;
    }

    if (s1.data[i] == s2.data[i]) return 0;
    return (s1.data[i] > s2.data[i]) ? 1 : -1;
}

int strncmp(const String &s1, const String &s2, int n)
{
    int i = 0;

    while (i < n)
    {
        if (!s1.data[i] && !s2.data[i]) return 0;
        if (!s1.data[i]) return -1;
        if (!s2.data[i]) return 1;

        if (s1.data[i] > s2.data[i]) return 1;
        if (s1.data[i] < s2.data[i]) return -1;

        i++;
    }

    return 0;
}

void strcat(String &s2, const String &s1)
{
    int old = s2.length;
    int total = old + s1.length;

    char *temp = new char[total + 1];

    for (int i = 0; i < old; i++)
        temp[i] = s2.data[i];

    for (int i = 0; i < s1.length; i++)
        temp[old + i] = s1.data[i];

    temp[total] = '\0';

    delete[] s2.data;

    s2.data = temp;
    s2.length = total;
}

void strncat(String &s2, const String &s1, int n)
{
    int count = 0;

    while (count < n && s1.data[count])
        count++;

    int old = s2.length;
    int total = old + count;

    char *temp = new char[total + 1];

    for (int i = 0; i < old; i++)
        temp[i] = s2.data[i];

    for (int i = 0; i < count; i++)
        temp[old + i] = s1.data[i];

    temp[total] = '\0';

    delete[] s2.data;

    s2.data = temp;
    s2.length = total;
}

void strrev(String &s)
{
    int i = 0, j = s.length - 1;

    while (i < j)
    {
        char temp = s.data[i];
        s.data[i] = s.data[j];
        s.data[j] = temp;

        i++;
        j--;
    }
}

void strupr(String &s)
{
    for (int i = 0; i < s.length; i++)
        if (s.data[i] >= 'a' && s.data[i] <= 'z')
            s.data[i] -= 32;
}

void strlwr(String &s)
{
    for (int i = 0; i < s.length; i++)
        if (s.data[i] >= 'A' && s.data[i] <= 'Z')
            s.data[i] += 32;
}

int strchr(const String &s, char ch)
{
    for (int i = 0; i < s.length; i++)
        if (s.data[i] == ch)
            return i;

    return -1;
}

int strrchr(const String &s, char ch)
{
    for (int i = s.length - 1; i >= 0; i--)
        if (s.data[i] == ch)
            return i;

    return -1;
}

int strstr(const String &s, const char *sub)
{
    int n = 0;

    while (sub[n])
        n++;

    for (int i = 0; i <= s.length - n; i++)
    {
        int j = 0;

        while (j < n && s.data[i + j] == sub[j])
            j++;

        if (j == n)
            return i;
    }

    return -1;
}

int strlen(const String &s)
{
    return s.length;
}
