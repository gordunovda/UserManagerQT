#pragma once

class UserManagerObserver {
public:
    virtual ~UserManagerObserver() {}
    virtual void ChangeUser() = 0;
};
