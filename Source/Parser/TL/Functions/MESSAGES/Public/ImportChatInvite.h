#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/Updates.h"

//begin namespace block
namespace MESSAGES
{
class ImportChatInvite : public TLBaseObject
{
public:
	ImportChatInvite();
	ImportChatInvite(FString hash);

	~ImportChatInvite();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	FString Gethash() const
	{
		 return this->hash;
	}

	COMMON::Updates* GetResult() const
	{
		 return this->result;
	}

private:
	FString hash;
	COMMON::Updates* result;
};
} //end namespace block
