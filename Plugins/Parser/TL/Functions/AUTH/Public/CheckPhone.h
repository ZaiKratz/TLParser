#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Auth/Public/CheckedPhone.h"

//begin namespace block
namespace AUTH
{
class CheckPhone : public TLBaseObject
{
public:
	CheckPhone();
	CheckPhone(FString phone_number);

	~CheckPhone();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	FString phone_number;
	AUTH::CheckedPhone* result;
};
} //end namespace block
