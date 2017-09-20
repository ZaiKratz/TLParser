#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Account/Public/Authorizations.h"

//begin namespace block
namespace ACCOUNT
{
class GetAuthorizations : public TLBaseObject
{
public:
	GetAuthorizations();
	~GetAuthorizations();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	ACCOUNT::Authorizations* result;
};
} //end namespace block
