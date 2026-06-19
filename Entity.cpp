#include "Entity.h"

Entity::Entity(const Entities& e)
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

    case Entities::Chicken:
    {
        SetRequiredCycles(3);
        break;
    }

    case Entities::Cow:
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


Entity::Entity(const Entity& e)
{
    SetEntity(e.GetEntity());
    SetRequiredCycles(e.GetRequiredCycles());
    SetCurrentCycles(e.GetCurrentCycles());

}

int Entity::GetRequiredCycles() const
{
    return required_cycles;
}

int Entity::GetCurrentCycles() const
{
    return current_cycles;
}

Entities Entity::GetEntity() const
{
    return object;
}

void Entity::SetRequiredCycles(int count)
{
    required_cycles = count;
}

void Entity::SetCurrentCycles(int count)
{
    current_cycles = count;
}

void Entity::SetEntity(Entities e)
{
    object = e;
}


bool Entity::Ready()
{
    if (required_cycles <= current_cycles)return true;

    return false;
}
