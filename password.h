#ifndef PASSWORD_H
#define PASSWORD_H

#include <random>
#include <math.h>
#include <time.h>
#include <vector>
#include <QString>

class Password {

private:
    int length;
    bool upper_case;
    bool lower_case;
    bool letter;
    bool number;
    bool special_char;
    std::mt19937 generator;
    QString password;

public:
    Password();

    void setLength(int l);
    void setLowerCase(bool val);
    void setUpperCase(bool val);
    void setNumber(bool val);
    void setLetter(bool val);
    void setSpecialChar(bool val);

    void generatePassword();
    void resetPassword();
    QString getPassword() const;

};

#endif // PASSWORD_H
