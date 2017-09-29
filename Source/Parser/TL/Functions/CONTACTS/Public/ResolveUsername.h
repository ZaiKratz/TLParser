#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Contacts/Public/ResolvedPeer.h"

//begin namespace block
namespace CONTACTS
{
class ResolveUsername : public TLBaseObject
{
public:
	ResolveUsername();
	ResolveUsername(FString username);

	~ResolveUsername();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	FString Getusername() const
	{
		 return this->username;
	}

	CONTACTS::ResolvedPeer* GetResult() const
	{
		 return this->result;
	}

private:
	FString username;
	CONTACTS::ResolvedPeer* result;
};
} //end namespace block
