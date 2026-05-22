#include "Taskboard.h"

Taskboard::Taskboard()
{
	tasks.push_back(std::make_unique<Task>((StringToEntity("Wheat"), 5, 50, 10)));
	tasks.push_back(std::make_unique<Task>((StringToEntity("Milk"), 3, 120, 20)));

}

std::vector<std::unique_ptr<Task>> Taskboard::GetTasks()
{
	return tasks;
}

void Taskboard::Print() const
{
	for (const auto& t : tasks) 
	{
		t->Print();
	}
}

void Taskboard::AddTask(Task t)
{
	tasks.push_back(std::make_unique<Task>(t));
}

bool Taskboard::CompleteTask(Player& player, int taskId)
{
	if (taskId < 1) {
		std::cout << "Wrong id" << std::endl;
		return false;
	}


	for (const auto& t : GetTasks())
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

void Taskboard::RemoveTask(int taskId)
{
	tasks.erase(
		std::remove_if(tasks.begin(), tasks.end(),
			[&](const Task& t)
			{
				return t.GetId() == taskId;
			}),
		tasks.end());
}
