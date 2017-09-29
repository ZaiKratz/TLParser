#pragma once
#include "Engine.h"
#include "../../../Types/Private/InputContact.h"

#include "../../../Types/Private/InputContact.h"

//begin namespace block
namespace COMMON
{
class InputPhoneContact : public PRIVATE::InputContact
{
public:
	InputPhoneContact();
	InputPhoneContact(unsigned long long client_id, FString phone, FString first_name, FString last_name);

	~InputPhoneContact();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	unsigned long long GetClientId() const
	{
		 return this->client_id;
	}

	FString Getphone() const
	{
		 return this->phone;
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
	unsigned long long client_id;
	 FString phone;
	 FString first_name;
	 FString last_name;
};
} //end namespace block
