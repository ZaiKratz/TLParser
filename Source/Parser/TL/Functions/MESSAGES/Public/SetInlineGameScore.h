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

	bool GetEditMessage() const
	{
		 return this->edit_message;
	}

	bool Getforce() const
	{
		 return this->force;
	}

	COMMON::InputBotInlineMessageID*  Getid() const
	{
		 return this->id;
	}

	COMMON::InputUser*  GetUserId() const
	{
		 return this->user_id;
	}

	int32 Getscore() const
	{
		 return this->score;
	}

	bool GetResult() const
	{
		 return this->result;
	}

private:
	bool edit_message;
	 bool force;
	 COMMON::InputBotInlineMessageID* id;
	 COMMON::InputUser* user_id;
	 int32 score;
	bool result;
};
} //end namespace block
