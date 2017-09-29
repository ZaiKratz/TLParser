#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputPhoneCall.h"
#include "../../../Types/Common/Public/Updates.h"

//begin namespace block
namespace PHONE
{
class SetCallRating : public TLBaseObject
{
public:
	SetCallRating();
	SetCallRating(COMMON::InputPhoneCall* peer, int32 rating, FString comment);

	~SetCallRating();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::InputPhoneCall*  Getpeer() const
	{
		 return this->peer;
	}

	int32 Getrating() const
	{
		 return this->rating;
	}

	FString Getcomment() const
	{
		 return this->comment;
	}

	COMMON::Updates* GetResult() const
	{
		 return this->result;
	}

private:
	COMMON::InputPhoneCall* peer;
	 int32 rating;
	 FString comment;
	COMMON::Updates* result;
};
} //end namespace block
