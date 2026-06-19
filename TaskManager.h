#pragma once
#include "User.h"
#include "Namespaces.h"
#include "Taskboard.h"

class TaskManager : public User
{
	

public:

	TaskManager(const std::string& name, const std::string& pw);

	void showTasks(Taskboard& t);
	bool AddTask(Taskboard& t, const std::string& product, int quant, int rbal, int rscore);
	bool RemoveTask(Taskboard& t, int taskId);

	UserTypes GetType() override;
	void profileInfo() override;
};
