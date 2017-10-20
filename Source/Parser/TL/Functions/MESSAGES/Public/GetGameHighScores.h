#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputUser.h"
#include "../../../Types/Messages/Public/HighScores.h"

//begin namespace block
namespace MESSAGES
{
class GetGameHighScores : public TLBaseObject
{
public:
	GetGameHighScores();
	GetGameHighScores(TLBaseObject* peer, int32 id, COMMON::InputUser* user_id);

	~GetGameHighScores();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TLBaseObject*  Getpeer() const
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

	MESSAGES::HighScores* GetResult() const
	{
		 return this->result;
	}

private:
	TLBaseObject* peer;
	 int32 id;
	 COMMON::InputUser* user_id;
	MESSAGES::HighScores* result;
};
} //end namespace block
