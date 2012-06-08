#include "pathManager.h"

PathManager::PathManager()
{
}

PathManager::~PathManager()
{
}

void PathManager::setInputPath(QString path)
{
    this->inputPath = path;
}

void PathManager::setWorkDir(QString path)
{
    this->workDir = path;
}

void PathManager::setOutputDir(QString path)
{
    this->outputDir = path;
}

void PathManager::setStepPath(QString path, int step)
{
    this->stepPath[step - 1] = path;
}

void PathManager::loadPathCfg(QString path)
{
    QSettings *pathConfig = new QSettings(path, QSettings::IniFormat);
    pathConfig->setIniCodec("UTF-8");

    pathConfig->beginGroup(tr("SystemPath"));
    this->setInputPath(pathConfig->value(tr("InputPath")).toString());
    this->setWorkDir(pathConfig->value(tr("WorkDir")).toString());
    this->setOutputDir(pathConfig->value(tr("OutputDir")).toString());
    pathConfig->endGroup();

    pathConfig->beginGroup(tr("StepPath"));
    for(int i = 0; i < MAX_STEP; i++)
    {
        this->setStepPath(pathConfig->value(tr("Step")
                                            +QString::number(i+1)+tr("Path")).toString(), i+1);
    }
    pathConfig->endGroup();

    delete pathConfig;
}

void PathManager::savePathCfg(QString path)
{
    QSettings *pathConfig = new QSettings(path, QSettings::IniFormat);
    pathConfig->setIniCodec("UTF-8");

    pathConfig->beginGroup(tr("SystemPath"));
    pathConfig->setValue(tr("InputPath"), this->inputPath);
    pathConfig->setValue(tr("WorkDir"), this->workDir);
    pathConfig->setValue(tr("OutputDir"), this->outputDir);
    pathConfig->endGroup();

    pathConfig->beginGroup(tr("StepPath"));
    for(int i = 0; i < MAX_STEP; i++)
    {
        pathConfig->setValue(tr("Step")+QString::number(i+1)+tr("Path"), this->stepPath[i]);
    }
    pathConfig->endGroup();

    delete pathConfig;
}

void PathManager::resetAll()
{
    this->inputPath.clear();
    this->workDir.clear();
    this->outputDir.clear();
    for(int i = 0; i < MAX_STEP; i++)
    {
        this->stepPath[i].clear();
    }
}

QString PathManager::getInputPath()
{
    return this->inputPath;
}

QString PathManager::getWorkDir()
{
    return this->workDir;
}

QString PathManager::getOutputDir()
{
    return this->outputDir;
}

QString PathManager::getStepPath(int step)
{
    return this->stepPath[step - 1];
}

