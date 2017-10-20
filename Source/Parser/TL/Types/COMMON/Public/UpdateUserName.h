#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class UpdateUserName : public TLBaseObject
{
public:
	UpdateUserName();
	UpdateUserName(int32 user_id, FString first_name, FString last_name, FString username);

	~UpdateUserName();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 GetUserId() const
	{
		 return this->user_id;
	}

	FString GetFirstName() const
	{
		 return this->first_name;
	}

	FString GetLastName() const
	{
		 return this->last_name;
	}

	FString Getusername() const
	{
		 return this->username;
	}

private:
	int32 user_id;
	 FString first_name;
	 FString last_name;
	 FString username;
};
} //end namespace block
