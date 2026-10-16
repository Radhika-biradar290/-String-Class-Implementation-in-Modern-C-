#include <iostream>
#include "String.h"

using namespace std;

int main()
{
    String s1;
    String s2("Embedded");
    String s3(s2);

    s1 = s2;

    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;

    String a("Hello ");
    String b("World");
    String c = a + b;

    cout << "a+b = " << c << endl;
    cout << "c[0] = " << c[0] << endl;

    cout << "s2 == s3 : " << (s2 == s3) << endl;
    cout << "s2 != s3 : " << (s2 != s3) << endl;
    cout << "s2 < s3  : " << (s2 < s3) << endl;
    cout << "s2 > s3  : " << (s2 > s3) << endl;
    cout << "s2 <= s3 : " << (s2 <= s3) << endl;
    cout << "s2 >= s3 : " << (s2 >= s3) << endl;

    String x;

    cout << "Enter a word: ";
    cin >> x;
    cout << "You entered: " << x << endl;

    strcpy(s1, s2);
    cout << "strcpy  : " << s1 << endl;

    strncpy(s1, s2, 3);
    cout << "strncpy : " << s1 << endl;

    cout << "strcmp  : " << strcmp(s2, s3) << endl;
    cout << "strncmp : " << strncmp(s2, s3, 3) << endl;

    String p("Hello ");
    String q("World");

    strcat(p, q);
    cout << "strcat  : " << p << endl;

    String r("Micro");
    String t("controller");

    strncat(r, t, 4);
    cout << "strncat : " << r << endl;

    strrev(s2);
    cout << "strrev  : " << s2 << endl;

    strupr(s2);
    cout << "strupr  : " << s2 << endl;

    strlwr(s2);
    cout << "strlwr  : " << s2 << endl;

    cout << "strchr  : " << strchr(s2, 'e') << endl;
    cout << "strrchr : " << strrchr(s2, 'e') << endl;

    cout << "strstr  : " << strstr(s2, "bed") << endl;
    cout << "strlen  : " << strlen(s2) << endl;

    return 0;
}
