#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/CdnPublicKey.h"

//begin namespace block
namespace COMMON
{
class CdnConfig : public TLBaseObject
{
public:
	CdnConfig();
	CdnConfig(TArray<COMMON::CdnPublicKey*> public_keys);

	~CdnConfig();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TArray<COMMON::CdnPublicKey*>  GetPublicKeys() const
	{
		 return this->public_keys;
	}

private:
	TArray<COMMON::CdnPublicKey*> public_keys;
};
} //end namespace block
