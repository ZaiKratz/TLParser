#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/NearestDc.h"

//begin namespace block
namespace HELP
{
class GetNearestDc : public TLBaseObject
{
public:
	GetNearestDc();
	~GetNearestDc();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	COMMON::NearestDc* result;
};
} //end namespace block
