#pragma once
#include "Engine.h"
#include "../../../Types/Private/PrivacyRule.h"

#include "../../../Types/Private/PrivacyRule.h"

//begin namespace block
namespace COMMON
{
class PrivacyValueAllowAll : public PRIVATE::PrivacyRule
{
public:
	PrivacyValueAllowAll();
	~PrivacyValueAllowAll();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

private:
};
} //end namespace block
