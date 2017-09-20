#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputBotInlineMessageID.h"
#include "../../../Types/Common/Public/InputUser.h"
#include "../../../Types/Messages/Public/HighScores.h"

//begin namespace block
namespace MESSAGES
{
class GetInlineGameHighScores : public TLBaseObject
{
public:
	GetInlineGameHighScores();
	GetInlineGameHighScores(COMMON::InputBotInlineMessageID* id, COMMON::InputUser* user_id);

	~GetInlineGameHighScores();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::InputBotInlineMessageID* id;
	 COMMON::InputUser* user_id;
	MESSAGES::HighScores* result;
};
} //end namespace block
