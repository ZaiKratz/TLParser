#pragma once
#include "Engine.h"
#include "../../../Types/Private/Update.h"

#include "../../../Types/Private/PrivacyKey.h"
#include "../../../Types/Private/PrivacyRule.h"
#include "../../../Types/Private/Update.h"

//begin namespace block
namespace COMMON
{
class UpdatePrivacy : public PRIVATE::Update
{
public:
	UpdatePrivacy();
	UpdatePrivacy(PRIVATE::PrivacyKey* key, TArray<PRIVATE::PrivacyRule*> rules);

	~UpdatePrivacy();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	PRIVATE::PrivacyKey*  Getkey() const
	{
		 return this->key;
	}

	TArray<PRIVATE::PrivacyRule*>  Getrules() const
	{
		 return this->rules;
	}

private:
	PRIVATE::PrivacyKey* key;
	 TArray<PRIVATE::PrivacyRule*> rules;
};
} //end namespace block
