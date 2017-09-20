#pragma once
#include "Engine.h"
#include "../../../Types/Private/ContactLink.h"

#include "../../../Types/Private/ContactLink.h"

//begin namespace block
namespace COMMON
{
class ContactLinkNone : public PRIVATE::ContactLink
{
public:
	ContactLinkNone();
	~ContactLinkNone();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
};
} //end namespace block
