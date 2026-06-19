#include "TaskManager.h"

TaskManager::TaskManager(const std::string& name, const std::string& pw)
    : User(name,pw)
{
}

void TaskManager::showTasks(Taskboard& t)
{
    t.Print();
}

bool TaskManager::AddTask(Taskboard& t, const std::string& product, int quant, int rbal, int rscore)
{
    Task task(StringToEntity(product), quant, rbal, rscore);
    return  t.AddTask(task);
}

bool TaskManager::RemoveTask(Taskboard& t, int taskId)
{
    return t.RemoveTask(taskId);
}


UserTypes TaskManager::GetType()
{
    return UserTypes::TaskManager;
}

void TaskManager::profileInfo()
{
    std::cout << "Currently logged in TaskManager profile." << std::endl;
}
