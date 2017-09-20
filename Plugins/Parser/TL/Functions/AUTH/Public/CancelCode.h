#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace AUTH
{
class CancelCode : public TLBaseObject
{
public:
	CancelCode();
	CancelCode(FString phone_number, FString phone_code_hash);

	~CancelCode();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	FString phone_number;
	 FString phone_code_hash;
	bool result;
};
} //end namespace block
