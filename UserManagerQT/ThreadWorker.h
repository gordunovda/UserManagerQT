#pragma once

#include <QThread>
#include <QMutex>
#include <QWaitCondition>

class ThreadWorker : public QThread
{
public:
    ThreadWorker(QObject* parent = nullptr);
    ~ThreadWorker();
    void Init();
    void Process();
    void Exit();
protected:
    void run() override;
    virtual void Job() = 0;
protected:
    QMutex m_mutex;
    QWaitCondition m_condition;
    bool m_exit;
};