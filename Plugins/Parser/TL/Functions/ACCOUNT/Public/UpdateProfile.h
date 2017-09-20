#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/User.h"

//begin namespace block
namespace ACCOUNT
{
class UpdateProfile : public TLBaseObject
{
public:
	UpdateProfile();
	UpdateProfile(FString first_name, FString last_name, FString about);

	~UpdateProfile();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	FString first_name;
	 FString last_name;
	 FString about;
	COMMON::User* result;
};
} //end namespace block
