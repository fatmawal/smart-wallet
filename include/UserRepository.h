#ifndef USERREPOSITORY_H
#define USERREPOSITORY_H

#include <string>
#include <vector>
#include "User.h"

class UserRepository {
private:
    std::string filename;
    std::vector<User> users;

public:
    UserRepository(const std::string& file);   
    void load();
    void save();
       bool loadFromCSV(const std::string& filename);
    bool saveToCSV(const std::string& filename);
    User* findUser(const std::string& username, const std::string& password);
    void updateUser(const User& user);
    const std::vector<User>& getAllUsers() const;
    void addUser(const User& user);


};

#endif
