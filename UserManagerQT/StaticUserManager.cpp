#include "StaticUserManager.h"
#include "UsersRole.h"

StaticUserManager::StaticUserManager()
{
	m_vecUsers.push_back(new User("", new OperatorRole()));
	m_vecUsers.push_back(new User("111", new TechnicianRole()));
	m_vecUsers.push_back(new User("222", new EngeneerRole()));
	m_cCurrentUser = nullptr;
}

StaticUserManager::~StaticUserManager()
{
	Exit();
	m_cCurrentUser = 0;
	for (auto p : m_vecUsers)
		delete p;
}

void StaticUserManager::ChangePassword(QString password)
{
	{
		QMutexLocker locker(&m_mutex);
		m_qsPassword = password;
	}
	Process();
}

void StaticUserManager::Job()
{
	User* lastUser = m_cCurrentUser;
	for (auto iter = m_vecUsers.rbegin(); iter != m_vecUsers.rend(); iter++)
		if ((*iter)->ValidatePassword(m_qsPassword))
		{
			m_cCurrentUser = *iter;
			break;
		}

	if (lastUser != m_cCurrentUser)
		Notify();
}

bool StaticUserManager::IsAllow(QString name)
{
	if (m_cCurrentUser)
		return m_cCurrentUser->GetUserRole()->IsAllow(name);
	else
		return false;
}