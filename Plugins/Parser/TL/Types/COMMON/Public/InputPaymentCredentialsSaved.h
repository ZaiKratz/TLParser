#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputPaymentCredentials.h"

//begin namespace block
namespace COMMON
{
class InputPaymentCredentialsSaved : public TLBaseObject
{
public:
	InputPaymentCredentialsSaved();
	InputPaymentCredentialsSaved(FString id, TArray<uint8> tmp_password);

	~InputPaymentCredentialsSaved();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	FString id;
	 TArray<uint8> tmp_password;
};
} //end namespace block
