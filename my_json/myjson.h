#ifndef MYJSON_H
#define MYJSON_H

#include <vector>
#include <memory>

class json
{
private:


public:
    json();
    json(class json& js);
    json(class json&& js);
    ~json();
};

#endif // MYJSON_H
