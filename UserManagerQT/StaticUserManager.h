#pragma once

#include "User.h"
#include "UserManager.h"
#include "UsersRole.h"
#include "ThreadWorker.h"

class StaticUserManager: public UserManager, public ThreadWorker
{
public:
    explicit StaticUserManager();
    ~StaticUserManager();
    bool IsAllow(QString name);

public slots:
    void ChangePassword(QString password);

private:
    void Job() override;

    QString m_qsPassword;
    User* m_cCurrentUser;
    std::vector<User *> m_vecUsers;
};

