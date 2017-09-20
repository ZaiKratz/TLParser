#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace ACCOUNT
{
class Password : public TLBaseObject
{
public:
	Password();
	Password(TArray<uint8> current_salt, TArray<uint8> new_salt, FString hint, bool has_recovery, FString email_unconfirmed_pattern);

	~Password();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	TArray<uint8> current_salt;
	 TArray<uint8> new_salt;
	 FString hint;
	 bool has_recovery;
	 FString email_unconfirmed_pattern;
};
} //end namespace block
