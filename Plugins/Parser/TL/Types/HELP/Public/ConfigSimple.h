#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/ipPort.h"

//begin namespace block
namespace HELP
{
class ConfigSimple : public TLBaseObject
{
public:
	ConfigSimple();
	ConfigSimple(FDateTime date, FDateTime expires, int32 dc_id, TArray<COMMON::ipPort*> ip_port_list);

	~ConfigSimple();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	FDateTime date;
	 FDateTime expires;
	 int32 dc_id;
	 TArray<COMMON::ipPort*> ip_port_list;
};
} //end namespace block
