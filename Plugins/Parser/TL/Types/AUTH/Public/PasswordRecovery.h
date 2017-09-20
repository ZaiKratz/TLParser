#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace AUTH
{
class PasswordRecovery : public TLBaseObject
{
public:
	PasswordRecovery();
	PasswordRecovery(FString email_pattern);

	~PasswordRecovery();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	FString email_pattern;
};
} //end namespace block
