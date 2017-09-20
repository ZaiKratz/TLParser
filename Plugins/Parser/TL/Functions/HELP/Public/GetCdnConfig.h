#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/CdnConfig.h"

//begin namespace block
namespace HELP
{
class GetCdnConfig : public TLBaseObject
{
public:
	GetCdnConfig();
	~GetCdnConfig();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::CdnConfig* result;
};
} //end namespace block
