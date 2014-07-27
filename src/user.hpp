#ifndef USER_H
#define USER_H

include <iostream>
include <string>

class User {
friend std:istream& operator>>(std::istream&, User&);
friend std:ostream& operator<<(std::ostream&, User&);

operator==(const User&, const User&);
public:
    User() = default;
    User(const std:string name): name(name) { }
    User(std::istream &is) { is >> *this}
public:
    User& operator+=(const User&);
    std::string name() const { return name; }
private:
    std::string name;
    
};
