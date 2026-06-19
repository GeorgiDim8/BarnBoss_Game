#include "Task.h"


Task::Task(const Entities& prod, int quant, int bal, int score)
{
    SetId(IdGenerator++);
    SetRequiredProduct(prod);
    SetRequiredQuantity(quant);
    SetRewardBalance(bal);
    SetRewardScore(score);

    
}


int Task::GetId() const
{
    return id;
}

Entities Task::GetReqiredProduct() const
{
    return RequiredProduct;
}

int Task::GetRequiredQuantity() const
{
    return RequiredQuantity;
}

int Task::GetRewardBalance() const
{
    return RewardBalance;
}

int Task::GetRewardScore() const
{
    return RewardScore;
}

void Task::SetId(int ID)
{
    id = ID;
}

void Task::SetRequiredProduct(const Entities& e)
{
    RequiredProduct = e;
}

void Task::SetRequiredQuantity(const int q)
{
    RequiredQuantity = q;

}

void Task::SetRewardBalance(const int b)
{
    RewardBalance = b;
}

void Task::SetRewardScore(const int s)
{
    RewardScore = s;
}

void Task::Print() const
{
    std::cout << GetId()
        << ". Deliver " << GetRequiredQuantity()
        << " " << EntityToString(GetReqiredProduct())
        << " -> Reward: " << GetRewardBalance()
        << " Balance, " << GetRewardScore()
        << " Score" << std::endl;
}

int Task::IdGenerator = 1;