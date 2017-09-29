#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace AUTH
{
class SendInvites : public TLBaseObject
{
public:
	SendInvites();
	SendInvites(TArray<FString> phone_numbers, FString message);

	~SendInvites();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TArray<FString>  GetPhoneNumbers() const
	{
		 return this->phone_numbers;
	}

	FString Getmessage() const
	{
		 return this->message;
	}

	bool GetResult() const
	{
		 return this->result;
	}

private:
	TArray<FString> phone_numbers;
	 FString message;
	bool result;
};
} //end namespace block
