#include "processorManager.h"

ProcessorManager::ProcessorManager(PathManager *pathManager)
{
    this->pathManager = pathManager;
    this->stepProcessor = new StepProcessor();
    this->currentRunStep = -1;
    this->progressAll = 0;
    connect(this->stepProcessor, SIGNAL(progressUpdate(int)), this, SLOT(progressUpdate_slot(int)));
    connect(this->stepProcessor, SIGNAL(errorMsg(QString)), this, SLOT(errorMsg_slot(QString)));
    connect(this->stepProcessor, SIGNAL(processFinish()), this, SLOT(processFinish_slot()));
    for(int i = 0; i < MAX_STEP; i++)
    {
        this->stepFinish[i] = false;
    }
}

ProcessorManager::~ProcessorManager()
{
    delete this->stepProcessor;
}

void ProcessorManager::setMaxProcessor(int n)
{
    this->maxProcessor = n;
}

void ProcessorManager::setStepParamAll() //设置进程命令参数和结果路径
{
    QString workDir = this->pathManager->getWorkDir();
    QString outDir = this->pathManager->getOutputDir();
    QString fileName = this->pathManager->getInputPath();

    workDir = QDir::toNativeSeparators(workDir);
    if(!workDir.endsWith('\\'))
    {
        workDir.append('\\');
    }

    outDir = QDir::toNativeSeparators(outDir);
    if(!outDir.endsWith('\\'))
    {
        outDir.append('\\');
    }

    fileName = QDir::toNativeSeparators(fileName);
    QFileInfo info(fileName);
    fileName = info.baseName(); //去掉后缀的文件名, 可能存在判定错误,如 test.2010.dat (多个'.')

    //step1
    this->stepParam[0] = this->pathManager->getInputPath() + " " + workDir + fileName + ".dat";
    this->resultPath[0] = workDir + fileName + ".dat";
    //step2
    this->stepParam[1] = workDir + fileName + ".dat" + " " + workDir;
    this->resultPath[1] = workDir + fileName + ".dat";
    //step3
    this->stepParam[2] = workDir + "Part_0.dat" + " " + workDir + "edge.dat" + " " + workDir + "dire.dat";
    this->resultPath[2] = workDir + "edge.dat";
    //step4
    this->stepParam[3] = workDir + "edge.dat" + " " + workDir + "dire.dat" + " " + workDir + "line.dat";
    this->resultPath[3] = workDir + "line.dat";
    //step5
    this->stepParam[4] = workDir + "line.dat" + " " + workDir + "Part_0.dat";
    this->resultPath[4] = workDir + "Part_0.dat";
    //step6
    this->stepParam[5] = workDir + "PartConfig.conf" + " " + workDir + "ans.dat";
    this->resultPath[5] = workDir + "ans.dat";
    //step7
    this->stepParam[6] = workDir + "ans.dat" + " " + this->pathManager->getInputPath() + " "
            + outDir + "result.bmp";
    this->resultPath[6] = outDir + "result.bmp";
}

void ProcessorManager::setStepParam(QString param, int step)
{
    if(step <= MAX_STEP)
    {
        this->stepParam[step - 1] = param;
    }
}

QString ProcessorManager::getStepParam(int step)
{
    if(step <= MAX_STEP)
    {
        return this->stepParam[step - 1];
    }
    else
    {
        return NULL;
    }
}

void ProcessorManager::setStepPriority(QThread::Priority priority, int step)
{
    if(step <= MAX_STEP)
    {
        this->priority[step - 1] = priority;
    }
}

QString ProcessorManager::getResultPath(int step)
{
    return this->resultPath[step - 1];
}

void ProcessorManager::beginStep(int step)  //单步运行
{
    this->currentRunStep = step;
    this->stepProcessor->setEnv(
                this->pathManager->getStepPath(step),
                this->resultPath[step - 1],
                this->stepParam[step - 1],
                this->priority[step - 1]);
    this->stepProcessor->startProcess();  
}

void ProcessorManager::stopStep(int step)  //单步停止
{
    this->stepProcessor->stopProcess();
    this->currentRunStep = -1;
    this->stepFinish[step - 1] = false;
//    this->disconnect(SIGNAL(progressUpdate(int,int)));
//    this->disconnect(SIGNAL(processFinish(int)));
//    this->disconnect(SIGNAL(errorMsg(QString,int)));
}

void ProcessorManager::beginProcess()     //总体开始
{

}

void ProcessorManager::pauseProcess()     //总体暂停
{

}

void ProcessorManager::stopProcess()      //总体停止
{

}

void ProcessorManager::progressUpdate_slot(int n)
{
    this->progressAll = 100/MAX_STEP*(this->currentRunStep-1) + n*MAX_STEP/100;
    emit this->progressUpdate(n, this->currentRunStep);
    emit progressUpdateAll(this->progressAll);
}

void ProcessorManager::processFinish_slot()
{
    this->stepFinish[this->currentRunStep - 1] = true;
    emit this->processFinish(this->currentRunStep);
}

void ProcessorManager::errorMsg_slot(QString msg)
{
    this->stepFinish[this->currentRunStep - 1] = false;
    emit this->errorMsg(msg, this->currentRunStep);
}

bool ProcessorManager::getStepFinish(int step)
{
    return this->stepFinish[step - 1];
}
