#include "UserController.h"

UserController::UserController(UserManager* userManager, QObject* parent) : QObject(parent) 
{
	assert(userManager);
	m_pUserManager = userManager;
}

void UserController::ChangeUser()
{
	emit userChanged();
}

void UserController::ChangePassword(QString password)
{
	m_pUserManager->ChangePassword(password);
}

bool UserController::IsAllow(QString name)
{
	return m_pUserManager->IsAllow(name);
}