#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Auth/Public/SentCode.h"

//begin namespace block
namespace AUTH
{
class SendCode : public TLBaseObject
{
public:
	SendCode();
	SendCode(bool allow_flashcall, FString phone_number, bool current_number, int32 api_id, FString api_hash);

	~SendCode();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	bool GetAllowFlashcall() const
	{
		 return this->allow_flashcall;
	}

	FString GetPhoneNumber() const
	{
		 return this->phone_number;
	}

	bool GetCurrentNumber() const
	{
		 return this->current_number;
	}

	int32 GetApiId() const
	{
		 return this->api_id;
	}

	FString GetApiHash() const
	{
		 return this->api_hash;
	}

	AUTH::SentCode* GetResult() const
	{
		 return this->result;
	}

private:
	bool allow_flashcall;
	 FString phone_number;
	 bool current_number;
	 int32 api_id;
	 FString api_hash;
	AUTH::SentCode* result;
};
} //end namespace block
