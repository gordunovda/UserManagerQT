#pragma once
#include "UsersRole.h"
#include <qstring.h>

class User
{
public:
	User(QString password, UserRole * role);
	~User();

	bool ValidatePassword(QString password);
	UserRole* GetUserRole() {
		return m_cUserRole;
	};
private:
	QString m_qsPassword;
	UserRole* m_cUserRole;

};

