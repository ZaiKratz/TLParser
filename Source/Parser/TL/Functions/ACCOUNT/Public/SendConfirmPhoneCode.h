#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Auth/Public/SentCode.h"

//begin namespace block
namespace ACCOUNT
{
class SendConfirmPhoneCode : public TLBaseObject
{
public:
	SendConfirmPhoneCode();
	SendConfirmPhoneCode(bool allow_flashcall, FString hash, bool current_number);

	~SendConfirmPhoneCode();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	bool GetAllowFlashcall() const
	{
		 return this->allow_flashcall;
	}

	FString Gethash() const
	{
		 return this->hash;
	}

	bool GetCurrentNumber() const
	{
		 return this->current_number;
	}

	AUTH::SentCode* GetResult() const
	{
		 return this->result;
	}

private:
	bool allow_flashcall;
	 FString hash;
	 bool current_number;
	AUTH::SentCode* result;
};
} //end namespace block
