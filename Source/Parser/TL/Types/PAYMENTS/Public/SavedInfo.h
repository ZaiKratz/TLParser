#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/PaymentRequestedInfo.h"

//begin namespace block
namespace PAYMENTS
{
class SavedInfo : public TLBaseObject
{
public:
	SavedInfo();
	SavedInfo(bool has_saved_credentials, COMMON::PaymentRequestedInfo* saved_info);

	~SavedInfo();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	bool GetHasSavedCredentials() const
	{
		 return this->has_saved_credentials;
	}

	COMMON::PaymentRequestedInfo*  GetSavedInfo() const
	{
		 return this->saved_info;
	}

private:
	bool has_saved_credentials;
	 COMMON::PaymentRequestedInfo* saved_info;
};
} //end namespace block
