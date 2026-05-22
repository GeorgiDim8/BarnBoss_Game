#include "TaskManager.h"

TaskManager& TaskManager::GetInstance()
{
    static TaskManager instance;
    return instance;
}
