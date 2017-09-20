#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Upload/Public/CdnFile.h"

//begin namespace block
namespace UPLOAD
{
class GetCdnFile : public TLBaseObject
{
public:
	GetCdnFile();
	GetCdnFile(TArray<uint8> file_token, int32 offset, int32 limit);

	~GetCdnFile();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	TArray<uint8> file_token;
	 int32 offset;
	 int32 limit;
	UPLOAD::CdnFile* result;
};
} //end namespace block
