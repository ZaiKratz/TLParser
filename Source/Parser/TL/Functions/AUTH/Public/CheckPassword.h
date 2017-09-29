#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Auth/Public/Authorization.h"

//begin namespace block
namespace AUTH
{
class CheckPassword : public TLBaseObject
{
public:
	CheckPassword();
	CheckPassword(TArray<uint8> password_hash);

	~CheckPassword();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TArray<uint8>  GetPasswordHash() const
	{
		 return this->password_hash;
	}

	AUTH::Authorization* GetResult() const
	{
		 return this->result;
	}

private:
	TArray<uint8> password_hash;
	AUTH::Authorization* result;
};
} //end namespace block