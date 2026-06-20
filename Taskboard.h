#pragma once
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
	void Initialize();
	const std::vector<std::unique_ptr<Task>>& GetTasks() const;

	void Print() const;
	bool AddTask(const Task& t);
	bool CompleteTask(Player& player, int taskId);
	bool RemoveTask(int taskId);
	bool TaskExists(int taskId);
};