#ifndef ERROR_H
#define ERROR_H

#include <string>
#include <exception>
#include <iostream>

enum
{
    None = 0,
};

class error //: public std::exception
{
private:
    std::string erMessage = "";
    std::string erPlace = "";
    size_t erCode = None;

public:
    //virtual const char* what() const noexcept override{};
    error();
    error(std::string msg, std::string plc, size_t code);
    error(class error& er);
    error(class error&& er);
    ~error() = default;

    std::string getMessage(class error er){return er.erMessage;}
    std::string getPlace(class error er){return er.erPlace;}
    size_t getCode(class error er){return er.erCode;}

    friend std::ostream& operator<< (std::ostream& out, class error er) {
        out << "Error!" << er.erMessage << std::endl;
        out << er.erPlace << '\t' << er.erCode <<std::endl;
        return out;
    }

};

#endif // ERROR_H
