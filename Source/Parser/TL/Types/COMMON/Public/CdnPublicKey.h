#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class CdnPublicKey : public TLBaseObject
{
public:
	CdnPublicKey();
	CdnPublicKey(int32 dc_id, FString public_key);

	~CdnPublicKey();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 GetDcId() const
	{
		 return this->dc_id;
	}

	FString GetPublicKey() const
	{
		 return this->public_key;
	}

private:
	int32 dc_id;
	 FString public_key;
};
} //end namespace block
