#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class PhoneConnection : public TLBaseObject
{
public:
	PhoneConnection();
	PhoneConnection(unsigned long long id, FString ip, FString ipv6, int32 port, TArray<uint8> peer_tag);

	~PhoneConnection();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	unsigned long long Getid() const
	{
		 return this->id;
	}

	FString Getip() const
	{
		 return this->ip;
	}

	FString Getipv6() const
	{
		 return this->ipv6;
	}

	int32 Getport() const
	{
		 return this->port;
	}

	TArray<uint8>  GetPeerTag() const
	{
		 return this->peer_tag;
	}

private:
	unsigned long long id;
	 FString ip;
	 FString ipv6;
	 int32 port;
	 TArray<uint8> peer_tag;
};
} //end namespace block
