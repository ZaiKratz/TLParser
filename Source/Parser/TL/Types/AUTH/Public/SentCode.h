#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Private/SentCodeType.h"
#include "../../../Types/Private/CodeType.h"

//begin namespace block
namespace AUTH
{
class SentCode : public TLBaseObject
{
public:
	SentCode();
	SentCode(bool phone_registered, PRIVATE::SentCodeType* type, FString phone_code_hash, PRIVATE::CodeType* next_type, int32 timeout);

	~SentCode();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	bool GetPhoneRegistered() const
	{
		 return this->phone_registered;
	}

	PRIVATE::SentCodeType*  Gettype() const
	{
		 return this->type;
	}

	FString GetPhoneCodeHash() const
	{
		 return this->phone_code_hash;
	}

	PRIVATE::CodeType*  GetNextType() const
	{
		 return this->next_type;
	}

	int32 Gettimeout() const
	{
		 return this->timeout;
	}

private:
	bool phone_registered;
	 PRIVATE::SentCodeType* type;
	 FString phone_code_hash;
	 PRIVATE::CodeType* next_type;
	 int32 timeout;
};
} //end namespace block
