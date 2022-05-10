#ifndef MYJSON_H
#define MYJSON_H

#include <vector>
#include <memory>
#include <string>



class json
{
private:


public:
    json();
    explicit json(std::string& str);
    json(class json& js);
    json(class json&& js);
    ~json();
};

#endif // MYJSON_H
