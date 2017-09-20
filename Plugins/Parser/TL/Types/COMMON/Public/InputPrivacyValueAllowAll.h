#pragma once
#include "Engine.h"
#include "../../../Types/Private/InputPrivacyRule.h"

#include "../../../Types/Private/InputPrivacyRule.h"

//begin namespace block
namespace COMMON
{
class InputPrivacyValueAllowAll : public PRIVATE::InputPrivacyRule
{
public:
	InputPrivacyValueAllowAll();
	~InputPrivacyValueAllowAll();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
};
} //end namespace block
