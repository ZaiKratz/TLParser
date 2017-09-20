#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/Authorization.h"

//begin namespace block
namespace ACCOUNT
{
class Authorizations : public TLBaseObject
{
public:
	Authorizations();
	Authorizations(TArray<COMMON::Authorization*> authorizations);

	~Authorizations();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	TArray<COMMON::Authorization*> authorizations;
};
} //end namespace block
