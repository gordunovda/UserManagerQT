#include "UsersRole.h"
#include <algorithm>
using namespace std;

UserRole::UserRole()
{

}

bool UserRole::IsAllow(QString name)
{
	auto pos = find(m_vecAccessRights.begin(), m_vecAccessRights.end(), name);
	return pos != m_vecAccessRights.end();
}

bool UserRole::IsDeny(QString name)
{
	return !IsAllow(name);
}
	
void UserRole::AddAccessRight(QString name)
{
	if (!IsAllow(name))
		m_vecAccessRights.push_back(name);
}


OperatorRole::OperatorRole()
{
	AddAccessRight("newwindow");
	AddAccessRight("button1");
	AddAccessRight("button2");
}

QString OperatorRole::GetName()
{
	return "Operator";
}


TechnicianRole::TechnicianRole()
{
	AddAccessRight("button3");
	AddAccessRight("button4");
}

QString TechnicianRole::GetName()
{
	return "Technician";
}


EngeneerRole::EngeneerRole()
{
	AddAccessRight("button5");
	AddAccessRight("button6");
}

QString EngeneerRole::GetName()
{
	return "Engeneer";
}
