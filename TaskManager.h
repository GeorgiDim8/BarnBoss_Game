#pragma once
#include "User.h"

class TaskManager : public User
{
	TaskManager();

public:

	static TaskManager& GetInstance();

	TaskManager(const TaskManager& m) = delete;
	TaskManager& operator=(const TaskManager& m) = delete;

};
