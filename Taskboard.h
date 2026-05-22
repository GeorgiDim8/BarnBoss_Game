#pragma once
#include "Taskmanager.h"
#include "Namespaces.h"
#include "Task.h"
#include <vector>
#include<memory>
#include "Player.h"

class Taskboard 
{
	std::vector<std::unique_ptr<Task>> tasks;
	

public:
	Taskboard();
	std::vector<std::unique_ptr<Task>> GetTasks();

	void Print() const;
	void AddTask(Task t);
	bool CompleteTask(Player& player, int taskId);
	void RemoveTask(int taskId);
};