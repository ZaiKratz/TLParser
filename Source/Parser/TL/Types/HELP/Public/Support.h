#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/User.h"

//begin namespace block
namespace HELP
{
class Support : public TLBaseObject
{
public:
	Support();
	Support(FString phone_number, COMMON::User* user);

	~Support();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	FString GetPhoneNumber() const
	{
		 return this->phone_number;
	}

	COMMON::User*  Getuser() const
	{
		 return this->user;
	}

private:
	FString phone_number;
	 COMMON::User* user;
};
} //end namespace block
