#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Account/Public/Password.h"

//begin namespace block
namespace ACCOUNT
{
class GetPassword : public TLBaseObject
{
public:
	GetPassword();
	~GetPassword();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	ACCOUNT::Password* result;
};
} //end namespace block
