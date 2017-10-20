#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class UpdateUserPhone : public TLBaseObject
{
public:
	UpdateUserPhone();
	UpdateUserPhone(int32 user_id, FString phone);

	~UpdateUserPhone();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 GetUserId() const
	{
		 return this->user_id;
	}

	FString Getphone() const
	{
		 return this->phone;
	}

private:
	int32 user_id;
	 FString phone;
};
} //end namespace block
