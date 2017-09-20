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
private:
	unsigned long long id;
	 FString ip;
	 FString ipv6;
	 int32 port;
	 TArray<uint8> peer_tag;
};
} //end namespace block
