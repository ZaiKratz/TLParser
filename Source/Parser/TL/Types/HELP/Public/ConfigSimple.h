#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/IpPort.h"

//begin namespace block
namespace HELP
{
class ConfigSimple : public TLBaseObject
{
public:
	ConfigSimple();
	ConfigSimple(FDateTime date, FDateTime expires, int32 dc_id, TArray<COMMON::IpPort*> ip_port_list);

	~ConfigSimple();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	FDateTime Getdate() const
	{
		 return this->date;
	}

	FDateTime Getexpires() const
	{
		 return this->expires;
	}

	int32 GetDcId() const
	{
		 return this->dc_id;
	}

	TArray<COMMON::IpPort*>  GetIpPortList() const
	{
		 return this->ip_port_list;
	}

private:
	FDateTime date;
	 FDateTime expires;
	 int32 dc_id;
	 TArray<COMMON::IpPort*> ip_port_list;
};
} //end namespace block
