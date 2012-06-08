#include "stepProcessor.h"

StepProcessor::StepProcessor()
{
    this->myProcess = new QProcess();
    this->priority = QThread::NormalPriority;
    this->progress = 0;
    this->status = NotStarted;
    connect(myProcess, SIGNAL(readyReadStandardOutput()), this, SLOT(readFromStdOut()));
    connect(myProcess, SIGNAL(readyReadStandardError()), this, SLOT(readFromStdErr()));
    connect(myProcess, SIGNAL(error(QProcess::ProcessError)), this, SLOT(processError(QProcess::ProcessError)));
    connect(myProcess, SIGNAL(finished(int,QProcess::ExitStatus)), this, SLOT(processStop(int,QProcess::ExitStatus)));
    connect(myProcess, SIGNAL(stateChanged(QProcess::ProcessState)), this, SLOT(statusChanged(QProcess::ProcessState)));
}

StepProcessor::~StepProcessor()
{
    delete this->myProcess;
}

void StepProcessor::setEnv(QString path, QString result, QString param, QThread::Priority prio)
{
    this->programPath = path;
    this->resultPath = result;
    this->paramLine = param;
    this->priority = prio;
}

int StepProcessor::getProgress()
{
    return this->progress;
}

QString StepProcessor::getResultPath()
{
    return this->resultPath;
}

RunStatus StepProcessor::getStatus()
{
    return this->status;
}

bool StepProcessor::startProcess()
{
    QFileInfo info(this->programPath);
    if(!info.exists())
    {
        emit errorMsg(tr("����:�����ļ�������!"));
        return false;
    }

    QStringList arguments = this->paramLine.split(' ');
    this->myProcess->thread()->setPriority(this->priority);
    this->status = NotStarted;
    this->myProcess->start(this->programPath, arguments);
    return true;
}

void StepProcessor::stopProcess()
{
    if(this->status != Finish)
    {
        this->myProcess->terminate();
        this->status = Stop;
    }
}

void StepProcessor::readFromStdOut()
{
    QString stdOut = this->myProcess->readAllStandardOutput();

    //�������, ��������ź�(��ȡ���һ���а����Ľ�����Ϣ)
    int end = stdOut.lastIndexOf('%');
    int start = stdOut.lastIndexOf('\n', end);
    this->progress = stdOut.mid(start, end-start).toInt();
    emit progressUpdate(this->progress);
}

void StepProcessor::readFromStdErr()
{
    emit errorMsg(this->myProcess->readAllStandardError());
}

void StepProcessor::processError(QProcess::ProcessError error)
{
    switch(error)
    {
    case QProcess::FailedToStart: emit errorMsg(tr("��������ʧ��!")); break;
    case QProcess::Crashed: emit errorMsg(tr("���̱���!")); break;
    case QProcess::Timedout: emit errorMsg(tr("���̵ȴ���ʱ!")); break;
    case QProcess::WriteError: emit errorMsg(tr("д����ʧ��!")); break;
    case QProcess::ReadError: emit errorMsg(tr("������ʧ��!")); break;
    case QProcess::UnknownError: emit errorMsg(tr("����δ֪����!")); break;
    }
    this->status = Stop;
}

void StepProcessor::processStop(int exitCode, QProcess::ExitStatus exitStatus)
{
    if(QProcess::CrashExit == exitStatus)
    {
        this->status = Stop;
    }
    else
    {
        this->status = Finish;
        emit processFinish();   // ���̴������
    }
}

void StepProcessor::statusChanged(QProcess::ProcessState newState)
{
    this->status = RunStatus(newState);
}

