#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/FutureSalts.h"

//begin namespace block
namespace COMMON
{
class GetFutureSalts : public TLBaseObject
{
public:
	GetFutureSalts();
	GetFutureSalts(int32 num);

	~GetFutureSalts();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 num;
	COMMON::FutureSalts* result;
};
} //end namespace block
