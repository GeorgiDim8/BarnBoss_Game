#include "AnimalEntity.h"


AnimalEntity::AnimalEntity(const Entities& an)
    : Entity(an)
{
}

int AnimalEntity::GetRewardCount() const
{
    return rewardCount;
}

void AnimalEntity::SetRewardCount(int n)
{
    rewardCount = n;
}

void AnimalEntity::Cycle()
{
    SetCurrentCycles(GetCurrentCycles() + 1);
    if (Ready())
    {
        SetRewardCount(GetRewardCount() + 1);

        SetCurrentCycles(0);
    }
}

bool AnimalEntity::Harvest(Barn& barn)
{
    if (GetRewardCount()) 
    {
        Entities temp = GetEntity();
        barn.AddItem(++temp, GetRewardCount());
        SetRewardCount(0);
        return true;
    }
    return false;
}

void AnimalEntity::Print() const
{
    Entities temp = GetEntity();
    std::cout << "There are " << GetRewardCount() << " " << EntityToString(++temp) << " ready to harvest" << std::endl;

}


