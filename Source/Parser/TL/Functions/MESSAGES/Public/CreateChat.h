#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputUser.h"
#include "../../../Types/Common/Public/Updates.h"

//begin namespace block
namespace MESSAGES
{
class CreateChat : public TLBaseObject
{
public:
	CreateChat();
	CreateChat(TArray<COMMON::InputUser*> users, FString title);

	~CreateChat();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TArray<COMMON::InputUser*>  Getusers() const
	{
		 return this->users;
	}

	FString Gettitle() const
	{
		 return this->title;
	}

	COMMON::Updates* GetResult() const
	{
		 return this->result;
	}

private:
	TArray<COMMON::InputUser*> users;
	 FString title;
	COMMON::Updates* result;
};
} //end namespace block
