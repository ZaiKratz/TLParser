#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class ChatInviteExported : public TLBaseObject
{
public:
	ChatInviteExported();
	ChatInviteExported(FString link);

	~ChatInviteExported();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	FString Getlink() const
	{
		 return this->link;
	}

private:
	FString link;
};
} //end namespace block
