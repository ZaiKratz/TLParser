#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/CdnFileHash.h"
#include "../../../Types/Upload/Public/File.h"

//begin namespace block
namespace UPLOAD
{
class FileCdnRedirect : public TLBaseObject
{
public:
	FileCdnRedirect();
	FileCdnRedirect(int32 dc_id, TArray<uint8> file_token, TArray<uint8> encryption_key, TArray<uint8> encryption_iv, TArray<COMMON::CdnFileHash*> cdn_file_hashes);

	~FileCdnRedirect();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 GetDcId() const
	{
		 return this->dc_id;
	}

	TArray<uint8>  GetFileToken() const
	{
		 return this->file_token;
	}

	TArray<uint8>  GetEncryptionKey() const
	{
		 return this->encryption_key;
	}

	TArray<uint8>  GetEncryptionIv() const
	{
		 return this->encryption_iv;
	}

	TArray<COMMON::CdnFileHash*>  GetCdnFileHashes() const
	{
		 return this->cdn_file_hashes;
	}

private:
	int32 dc_id;
	 TArray<uint8> file_token;
	 TArray<uint8> encryption_key;
	 TArray<uint8> encryption_iv;
	 TArray<COMMON::CdnFileHash*> cdn_file_hashes;
};
} //end namespace block
