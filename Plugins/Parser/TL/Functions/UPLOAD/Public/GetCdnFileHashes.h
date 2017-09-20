#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/CdnFileHash.h"

//begin namespace block
namespace UPLOAD
{
class GetCdnFileHashes : public TLBaseObject
{
public:
	GetCdnFileHashes();
	GetCdnFileHashes(TArray<uint8> file_token, int32 offset);

	~GetCdnFileHashes();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	TArray<uint8> file_token;
	 int32 offset;
	TArray<COMMON::CdnFileHash*> result;
};
} //end namespace block
