#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class PrivacyValueAllowContacts : public TLBaseObject
{
public:
	PrivacyValueAllowContacts();
	~PrivacyValueAllowContacts();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

private:
};
} //end namespace block
