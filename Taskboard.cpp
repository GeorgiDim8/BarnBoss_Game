#include "Taskboard.h"

Taskboard::Taskboard()
{

}

void Taskboard::Initialize()
{

	tasks.push_back(std::make_unique<Task>(Entities::Wheat, 5, 50, 10));
	tasks.push_back(std::make_unique<Task>(Entities::Milk, 3, 120, 20));
}

const std::vector<std::unique_ptr<Task>>& Taskboard::GetTasks() const
{
	return tasks;
}

void Taskboard::Print() const
{
	std::cout << "=== TASKBOARD ===" << std::endl;

	for (const auto& t : tasks) 
	{
		t->Print();
	}
}

bool Taskboard::AddTask(const Task& t)
{
	tasks.push_back(std::make_unique<Task>(t.GetReqiredProduct(),
		t.GetRequiredQuantity(),
		t.GetRewardBalance(),
		t.GetRewardScore()));
	return true;
}

bool Taskboard::CompleteTask(Player& player, int taskId)
{
	if (taskId < 1) {
		std::cout << "Wrong id" << std::endl;
		return false;
	}


	for (const auto& t : tasks)
	{
		if ((*t).GetId() == taskId)
		{
			if (!player.GetBarn().Check((*t).GetReqiredProduct(), (*t).GetRequiredQuantity()))return false;
			player.GetBarn().RemoveItem((*t).GetReqiredProduct(), (*t).GetRequiredQuantity());
			player.SetBalance(player.GetBalance() + (*t).GetRewardBalance());
			player.SetScore(player.GetScore() + (*t).GetRewardScore());
			RemoveTask(taskId);

			return true;
		}
	}

	return false;
}

bool Taskboard::RemoveTask(int taskId)
{
	if (!TaskExists(taskId)) return false;
	tasks.erase(
		std::remove_if(tasks.begin(), tasks.end(),
			[&](const std::unique_ptr<Task>& t)
			{
				return t->GetId() == taskId;
			}),
		tasks.end());
	return true;
}

bool Taskboard::TaskExists(int taskId)
{
	for (const auto& t : tasks) 
	{
		if (t->GetId() == taskId) return true;
	}

	return false;
}
