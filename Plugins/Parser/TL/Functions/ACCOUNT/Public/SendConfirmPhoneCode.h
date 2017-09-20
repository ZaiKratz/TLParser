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
private:
	bool allow_flashcall;
	 FString hash;
	 bool current_number;
	AUTH::SentCode* result;
};
} //end namespace block
