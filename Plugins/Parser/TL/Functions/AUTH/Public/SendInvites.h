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
private:
	TArray<FString> phone_numbers;
	 FString message;
	bool result;
};
} //end namespace block
