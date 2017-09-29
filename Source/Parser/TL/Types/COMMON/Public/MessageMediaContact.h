#pragma once
#include "Engine.h"
#include "../../../Types/Private/MessageMedia.h"

#include "../../../Types/Private/MessageMedia.h"

//begin namespace block
namespace COMMON
{
class MessageMediaContact : public PRIVATE::MessageMedia
{
public:
	MessageMediaContact();
	MessageMediaContact(FString phone_number, FString first_name, FString last_name, int32 user_id);

	~MessageMediaContact();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	FString GetPhoneNumber() const
	{
		 return this->phone_number;
	}

	FString GetFirstName() const
	{
		 return this->first_name;
	}

	FString GetLastName() const
	{
		 return this->last_name;
	}

	int32 GetUserId() const
	{
		 return this->user_id;
	}

private:
	FString phone_number;
	 FString first_name;
	 FString last_name;
	 int32 user_id;
};
} //end namespace block
