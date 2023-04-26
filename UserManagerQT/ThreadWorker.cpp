#include "ThreadWorker.h"

ThreadWorker::ThreadWorker(QObject* parent)
    : QThread(parent)
    , m_exit(false)
{

}

ThreadWorker::~ThreadWorker()
{
    if (isRunning()) {
        exit();
    }
}

void ThreadWorker::Init()
{
    m_exit = false;
    QThread::start();
}

void ThreadWorker::Process()
{
    m_condition.wakeOne();
}

void ThreadWorker::Exit()
{
    m_exit = true;
    m_condition.wakeOne();
    QThread::wait();
}

void ThreadWorker::run()
{
    while (!m_exit) {
        QMutexLocker locker(&m_mutex);
        m_condition.wait(&m_mutex);
        if (m_exit) {
            break;
        }
        Job();
    }
}