#pragma once
class MenuManager;
class IMenu {
public:
    virtual void run() = 0;
    virtual ~IMenu() {}
};

class WelcomeMenu : public IMenu {
    MenuManager& manager;

public:
    WelcomeMenu(MenuManager& m);
    void run() override;
};

class UserMenu : public IMenu {
    MenuManager& manager;

public:
    UserMenu(MenuManager& m);
    void run() override;
};

class TransactionMenu : public IMenu {
    MenuManager& manager;

public:
    TransactionMenu(MenuManager& m);
    void run() override;
};
