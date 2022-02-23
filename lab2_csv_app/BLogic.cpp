#include "BLogic.h"

void input_data_from_file(std::list<std::string>& list, const std::string& filename)
{
    std::string str;
    std::ifstream fileForRead(filename);
    if (fileForRead.is_open()) {
        while(getline(fileForRead, str)) {
            list.push_back(str);
        }
    } else {
        //error here
    }
}

void output_list_of_str(const std::list<std::string>& list)
{
    for (auto& str : list) {
        std::cout << str << std::endl;
    }
}

void split_str_to_words(std::list<std::string>& list, const std::string& str, char sep)
{
    int start = 0;
    int pos = str.find(sep, start);
    while (pos != -1) {
        if (start != pos) {
            list.emplace_back(str.substr(start, pos - start));
        }
        start = pos + 1;
        pos = str.find(sep, start);
    }
    if (str[start] != sep && start != str.size()) {
        list.emplace_back(str.substr(start, str.size() - start));
    }
}
