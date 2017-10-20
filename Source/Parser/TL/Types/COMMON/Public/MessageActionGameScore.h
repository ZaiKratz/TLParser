#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class MessageActionGameScore : public TLBaseObject
{
public:
	MessageActionGameScore();
	MessageActionGameScore(unsigned long long game_id, int32 score);

	~MessageActionGameScore();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	unsigned long long GetGameId() const
	{
		 return this->game_id;
	}

	int32 Getscore() const
	{
		 return this->score;
	}

private:
	unsigned long long game_id;
	 int32 score;
};
} //end namespace block
