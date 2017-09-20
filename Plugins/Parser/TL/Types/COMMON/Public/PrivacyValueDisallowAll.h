#pragma once
#include "Engine.h"
#include "../../../Types/Private/PrivacyRule.h"

#include "../../../Types/Private/PrivacyRule.h"

//begin namespace block
namespace COMMON
{
class PrivacyValueDisallowAll : public PRIVATE::PrivacyRule
{
public:
	PrivacyValueDisallowAll();
	~PrivacyValueDisallowAll();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
};
} //end namespace block
