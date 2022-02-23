#ifndef BLOGIC_H
#define BLOGIC_H

#include <fstream>
#include <QList>
#include <iostream>
#include <list>
#include <vector>
#include <QMessageBox>

void input_data_from_file(std::list<std::string>& list, const std::string& filename);
void output_list_of_str(const std::list<std::string>& list);
void split_str_to_words(std::vector<std::string>& vector, const std::string& str, char sep);

#endif // BLOGIC_H
