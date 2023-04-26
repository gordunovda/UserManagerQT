#pragma once

#include <qstring.h>
#include <vector>


class UserRole
{
	public:
		UserRole();
		bool IsAllow(QString name);
		bool IsDeny(QString name);
		virtual QString GetName() = 0;
	protected:
		void AddAccessRight(QString name);
		std::vector<QString> m_vecAccessRights;

};

class OperatorRole: public UserRole
{
public:
	OperatorRole();
	virtual QString GetName() override;
};

class TechnicianRole : public OperatorRole
{
public:
	TechnicianRole();
	virtual QString GetName() override;
};

class EngeneerRole : public TechnicianRole
{
public:
	EngeneerRole();
	virtual QString GetName() override;
};
