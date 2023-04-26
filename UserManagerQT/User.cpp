#include "User.h"

User::User(QString password, UserRole *role)
{
	Q_ASSERT(role != nullptr);
	m_cUserRole = role;
	m_qsPassword = password;
}

User::~User()
{
	delete m_cUserRole;
}

bool User::ValidatePassword(QString password)
{
	if (password == m_qsPassword)
		return true;
	return m_qsPassword.isEmpty();
}