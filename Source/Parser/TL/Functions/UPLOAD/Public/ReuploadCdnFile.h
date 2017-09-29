#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/CdnFileHash.h"

//begin namespace block
namespace UPLOAD
{
class ReuploadCdnFile : public TLBaseObject
{
public:
	ReuploadCdnFile();
	ReuploadCdnFile(TArray<uint8> file_token, TArray<uint8> request_token);

	~ReuploadCdnFile();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TArray<uint8>  GetFileToken() const
	{
		 return this->file_token;
	}

	TArray<uint8>  GetRequestToken() const
	{
		 return this->request_token;
	}

	TArray<COMMON::CdnFileHash*> GetResult() const
	{
		 return this->result;
	}

private:
	TArray<uint8> file_token;
	 TArray<uint8> request_token;
	TArray<COMMON::CdnFileHash*> result;
};
} //end namespace block
