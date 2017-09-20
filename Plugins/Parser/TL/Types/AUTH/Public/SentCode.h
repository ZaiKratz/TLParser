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
private:
	bool phone_registered;
	 PRIVATE::SentCodeType* type;
	 FString phone_code_hash;
	 PRIVATE::CodeType* next_type;
	 int32 timeout;
};
} //end namespace block
