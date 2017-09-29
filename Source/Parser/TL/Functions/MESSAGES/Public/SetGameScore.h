#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Private/InputPeer.h"
#include "../../../Types/Common/Public/InputUser.h"
#include "../../../Types/Common/Public/Updates.h"

//begin namespace block
namespace MESSAGES
{
class SetGameScore : public TLBaseObject
{
public:
	SetGameScore();
	SetGameScore(bool edit_message, bool force, PRIVATE::InputPeer* peer, int32 id, COMMON::InputUser* user_id, int32 score);

	~SetGameScore();
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

	PRIVATE::InputPeer*  Getpeer() const
	{
		 return this->peer;
	}

	int32 Getid() const
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

	COMMON::Updates* GetResult() const
	{
		 return this->result;
	}

private:
	bool edit_message;
	 bool force;
	 PRIVATE::InputPeer* peer;
	 int32 id;
	 COMMON::InputUser* user_id;
	 int32 score;
	COMMON::Updates* result;
};
} //end namespace block
