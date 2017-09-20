#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class DcOption : public TLBaseObject
{
public:
	DcOption();
	DcOption(bool ipv6, bool media_only, bool tcpo_only, bool cdn, bool Static, int32 id, FString ip_address, int32 port);

	~DcOption();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	bool ipv6;
	 bool media_only;
	 bool tcpo_only;
	 bool cdn;
	 bool Static;
	 int32 id;
	 FString ip_address;
	 int32 port;
};
} //end namespace block
