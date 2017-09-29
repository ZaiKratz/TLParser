#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/ChatInvite.h"

//begin namespace block
namespace MESSAGES
{
class CheckChatInvite : public TLBaseObject
{
public:
	CheckChatInvite();
	CheckChatInvite(FString hash);

	~CheckChatInvite();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	FString Gethash() const
	{
		 return this->hash;
	}

	COMMON::ChatInvite* GetResult() const
	{
		 return this->result;
	}

private:
	FString hash;
	COMMON::ChatInvite* result;
};
} //end namespace block
