#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace ACCOUNT
{
class TmpPassword : public TLBaseObject
{
public:
	TmpPassword();
	TmpPassword(TArray<uint8> tmp_password, int32 valid_until);

	~TmpPassword();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	TArray<uint8> tmp_password;
	 int32 valid_until;
};
} //end namespace block
