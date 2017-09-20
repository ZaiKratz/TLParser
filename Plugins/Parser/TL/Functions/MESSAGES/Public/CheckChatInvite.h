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
private:
	FString hash;
	COMMON::ChatInvite* result;
};
} //end namespace block
