#include "PlantEntity.h"

PlantEntity::PlantEntity(Entities& e)
{
    switch (e) 
    {
    case Entities::Wheatseed: 
    {
        SetRequiredCycles(3);
        break;
    }
    case Entities::Cornseed: 
    {
        SetRequiredCycles(4);
        break;
    }
    default: 
    {
        std::cout << "Unable to grow " << EntityToString(e) << std::endl;

    }
    }

}

PlantEntity::PlantEntity(const PlantEntity& pl)
{
    SetEntity(pl.GetEntity());
    SetRequiredCycles(pl.GetRequiredCycles());
    SetCurrentCycles(pl.GetCurrentCycles());

}

int PlantEntity::GetRequiredCycles() const
{
    return required_cycles;
}

int PlantEntity::GetCurrentCycles() const
{
    return current_cycles;
}

Entities PlantEntity::GetEntity() const
{
    return entity;
}

bool PlantEntity::GetGrown() const
{
    return Grown;
}

void PlantEntity::SetRequiredCycles(int count)
{
    required_cycles = count;
}

void PlantEntity::SetCurrentCycles(int count)
{
    current_cycles = count;
}

void PlantEntity::SetEntity(Entities e)
{
    entity = e;
}

void PlantEntity::SetGrown()
{
    Grown = true;
}

bool PlantEntity::Ready()
{
    if (required_cycles <= current_cycles)return true;

    return false;
}

void PlantEntity::Cycle()
{
    SetCurrentCycles(GetCurrentCycles() + 1);
    if (Ready() && !GetGrown()) 
    {
        Entities temp = GetEntity();
        SetEntity(++temp);

        SetRequiredCycles(0);
        SetCurrentCycles(0);
    }
}

Entities PlantEntity::Reward() const
{
    if (GetGrown())return GetEntity();

    return Entities::Air;
}

void PlantEntity::Print() const
{
    if (!GetGrown())
        std::cout << EntityToString(GetEntity()) << " on cycle " << GetCurrentCycles() << " out of " << GetRequiredCycles() << std::endl;

    else std::cout << EntityToString(GetEntity()) << " is ready to harvest" << std::endl;
}
