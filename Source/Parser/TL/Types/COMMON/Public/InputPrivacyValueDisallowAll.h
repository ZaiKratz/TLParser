#pragma once
#include "Engine.h"
#include "../../../Types/Private/InputPrivacyRule.h"

#include "../../../Types/Private/InputPrivacyRule.h"

//begin namespace block
namespace COMMON
{
class InputPrivacyValueDisallowAll : public PRIVATE::InputPrivacyRule
{
public:
	InputPrivacyValueDisallowAll();
	~InputPrivacyValueDisallowAll();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

private:
};
} //end namespace block
