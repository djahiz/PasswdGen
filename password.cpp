#include "password.h"

Password::Password(){
    generator.seed(time(0));
    password = "";
}

void Password::setLength(int l){
    length = l;
}

void Password::setLowerCase(bool val){
    lower_case = val;
}

void Password::setUpperCase(bool val){
    upper_case = val;
}

void Password::setNumber(bool val){
    number = val;
}

void Password::setLetter(bool val){
    letter = val;
}

void Password::setSpecialChar(bool val){
    special_char = val;
}

void Password::generatePassword(){
    std::uniform_real_distribution<double> distribution(0, 1);
    QString dict = "";
    if(!letter && !number && !special_char)
        letter = true;
    if(!lower_case && !upper_case)
        lower_case = true;
    if(letter && lower_case)
        dict.append("abcdefghijklmnopqrstuvwxyz");
    if(letter && upper_case)
        dict.append("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    if(number)
        dict.append("0123456789");
    if(special_char)
        dict.append("?!#{}()[]@+=-_*/&:;.,");
    for(int i = 0; i < length; i++)
        password.append(dict[(int)round(distribution(generator)*(dict.size()-1))]);
}

void Password::resetPassword(){
    password = "";
}

QString Password::getPassword() const{
    return password;
}
