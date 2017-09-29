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

	FString GetPhoneNumber() const
	{
		 return this->phone_number;
	}

	AUTH::CheckedPhone* GetResult() const
	{
		 return this->result;
	}

private:
	FString phone_number;
	AUTH::CheckedPhone* result;
};
} //end namespace block