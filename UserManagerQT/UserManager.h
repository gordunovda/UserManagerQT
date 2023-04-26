#pragma once

#include "qstring.h"
#include "UserManagerObserver.h"
#include "vector"

class UserManager
{    
    
    public:
        void Attach(UserManagerObserver* observer);
        void Detach(UserManagerObserver* observer);
        void Notify();
        virtual bool IsAllow(QString name) = 0;
    
        virtual void ChangePassword(QString password) = 0;
    protected:
        
        std::vector<UserManagerObserver*> m_vecObservers;
};