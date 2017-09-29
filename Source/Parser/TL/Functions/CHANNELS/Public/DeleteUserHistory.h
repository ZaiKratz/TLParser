#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputChannel.h"
#include "../../../Types/Common/Public/InputUser.h"
#include "../../../Types/Messages/Public/AffectedHistory.h"

//begin namespace block
namespace CHANNELS
{
class DeleteUserHistory : public TLBaseObject
{
public:
	DeleteUserHistory();
	DeleteUserHistory(COMMON::InputChannel* channel, COMMON::InputUser* user_id);

	~DeleteUserHistory();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::InputChannel*  Getchannel() const
	{
		 return this->channel;
	}

	COMMON::InputUser*  GetUserId() const
	{
		 return this->user_id;
	}

	MESSAGES::AffectedHistory* GetResult() const
	{
		 return this->result;
	}

private:
	COMMON::InputChannel* channel;
	 COMMON::InputUser* user_id;
	MESSAGES::AffectedHistory* result;
};
} //end namespace block
