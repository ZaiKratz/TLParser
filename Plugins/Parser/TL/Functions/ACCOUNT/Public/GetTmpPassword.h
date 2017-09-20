#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Account/Public/TmpPassword.h"

//begin namespace block
namespace ACCOUNT
{
class GetTmpPassword : public TLBaseObject
{
public:
	GetTmpPassword();
	GetTmpPassword(TArray<uint8> password_hash, int32 period);

	~GetTmpPassword();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	TArray<uint8> password_hash;
	 int32 period;
	ACCOUNT::TmpPassword* result;
};
} //end namespace block
