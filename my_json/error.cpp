#include "error.h"

error::error():
    erMessage(""),
    erPlace(""),
    erCode(0)
{};

error::error(class error& er):
    erMessage(er.erMessage),
    erPlace(er.erPlace),
    erCode(er.erCode)
{};

error::error(class error&& er):
    erMessage(er.erMessage),
    erPlace(er.erPlace),
    erCode(er.erCode)
{};

error::error(std::string msg, std::string plc, size_t code):
    erMessage(msg),
    erPlace(plc),
    erCode(code)
{};

void myTerminate()
{
    std::cout << "Неперехваченное исключение!/n" << std::endl;
    exit(TERMINATE);
}

void myUnexpect()
{
    std::cout << "Непредвиденное исключение!/n" << std::endl;
    exit(UNEXPECT);
}
