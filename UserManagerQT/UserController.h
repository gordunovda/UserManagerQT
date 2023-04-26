#pragma once
#include <QObject>
#include <QThread>
#include "UserManagerObserver.h"
#include "UserManager.h"


class UserController: public QObject, public UserManagerObserver
{
	Q_OBJECT
public:
	explicit UserController(UserManager* userManager, QObject* parent = nullptr);
	virtual ~UserController() {};
	
	virtual void ChangeUser();

	Q_INVOKABLE  bool IsAllow(QString name);
	
signals:
	void userChanged();

public slots:
	void ChangePassword(QString password);

private:
	UserManager* m_pUserManager;

};

