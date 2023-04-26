#include "UserManager.h"


void UserManager::Attach(UserManagerObserver* observer)
{
    m_vecObservers.push_back(observer);
}

void UserManager::Detach(UserManagerObserver* observer)
{
    m_vecObservers.erase(std::remove(m_vecObservers.begin(), m_vecObservers.end(), observer), m_vecObservers.end());
}

void UserManager::Notify()
{
    for (UserManagerObserver* observer : m_vecObservers) {
        observer->ChangeUser();
    }
}
