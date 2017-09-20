#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Auth/Public/SentCode.h"

//begin namespace block
namespace ACCOUNT
{
class SendChangePhoneCode : public TLBaseObject
{
public:
	SendChangePhoneCode();
	SendChangePhoneCode(bool allow_flashcall, FString phone_number, bool current_number);

	~SendChangePhoneCode();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	bool allow_flashcall;
	 FString phone_number;
	 bool current_number;
	AUTH::SentCode* result;
};
} //end namespace block
