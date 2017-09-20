#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class IpPort : public TLBaseObject
{
public:
	IpPort();
	IpPort(int32 ipv4, int32 port);

	~IpPort();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 ipv4;
	 int32 port;
};
} //end namespace block
