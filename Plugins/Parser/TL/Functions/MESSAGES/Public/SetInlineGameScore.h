#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputBotInlineMessageID.h"
#include "../../../Types/Common/Public/InputUser.h"

//begin namespace block
namespace MESSAGES
{
class SetInlineGameScore : public TLBaseObject
{
public:
	SetInlineGameScore();
	SetInlineGameScore(bool edit_message, bool force, COMMON::InputBotInlineMessageID* id, COMMON::InputUser* user_id, int32 score);

	~SetInlineGameScore();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	bool edit_message;
	 bool force;
	 COMMON::InputBotInlineMessageID* id;
	 COMMON::InputUser* user_id;
	 int32 score;
	bool result;
};
} //end namespace block
