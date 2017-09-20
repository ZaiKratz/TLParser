#pragma once
#include "Engine.h"
#include "../../../Types/Private/MessageAction.h"

#include "../../../Types/Private/MessageAction.h"

//begin namespace block
namespace COMMON
{
class MessageActionGameScore : public PRIVATE::MessageAction
{
public:
	MessageActionGameScore();
	MessageActionGameScore(unsigned long long game_id, int32 score);

	~MessageActionGameScore();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	unsigned long long game_id;
	 int32 score;
};
} //end namespace block
