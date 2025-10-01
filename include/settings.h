#pragma once
#include "User.h"

class Settings {
    User* user;

public:
    Settings() : user(nullptr) {}  
    Settings(User* user);     
    void viewProfile();
    void changePIN();
    void changePassword();
    void updateUserCSV();
};
