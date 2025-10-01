#ifndef STORAGE_H
#define STORAGE_H

#include "User.h"
#include <string>

class Storage {
private:
    std::string filename;
public:
    Storage(const std::string& file) : filename(file) {}

    void save(const User& user);
    User load();
};

#endif
