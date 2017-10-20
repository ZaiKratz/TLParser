#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class InputBotInlineMessageMediaContact : public TLBaseObject
{
public:
	InputBotInlineMessageMediaContact();
	InputBotInlineMessageMediaContact(FString phone_number, FString first_name, FString last_name, TLBaseObject* reply_markup);

	~InputBotInlineMessageMediaContact();
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

	TLBaseObject*  GetReplyMarkup() const
	{
		 return this->reply_markup;
	}

private:
	FString phone_number;
	 FString first_name;
	 FString last_name;
	 TLBaseObject* reply_markup;
};
} //end namespace block
