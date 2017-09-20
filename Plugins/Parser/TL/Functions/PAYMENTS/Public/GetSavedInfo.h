#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Payments/Public/SavedInfo.h"

//begin namespace block
namespace PAYMENTS
{
class GetSavedInfo : public TLBaseObject
{
public:
	GetSavedInfo();
	~GetSavedInfo();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	PAYMENTS::SavedInfo* result;
};
} //end namespace block
