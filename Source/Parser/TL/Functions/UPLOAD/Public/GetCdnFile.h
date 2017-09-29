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

	TArray<uint8>  GetFileToken() const
	{
		 return this->file_token;
	}

	int32 Getoffset() const
	{
		 return this->offset;
	}

	int32 Getlimit() const
	{
		 return this->limit;
	}

	UPLOAD::CdnFile* GetResult() const
	{
		 return this->result;
	}

private:
	TArray<uint8> file_token;
	 int32 offset;
	 int32 limit;
	UPLOAD::CdnFile* result;
};
} //end namespace block
