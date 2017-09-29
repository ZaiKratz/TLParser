#pragma once
#include "Engine.h"
#include "../../../Types/Private/InputMedia.h"

#include "../../../Types/Private/InputMedia.h"

//begin namespace block
namespace COMMON
{
class InputMediaContact : public PRIVATE::InputMedia
{
public:
	InputMediaContact();
	InputMediaContact(FString phone_number, FString first_name, FString last_name);

	~InputMediaContact();
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

private:
	FString phone_number;
	 FString first_name;
	 FString last_name;
};
} //end namespace block
