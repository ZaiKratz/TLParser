#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Upload/Public/CdnFile.h"

//begin namespace block
namespace UPLOAD
{
class CdnFileReuploadNeeded : public TLBaseObject
{
public:
	CdnFileReuploadNeeded();
	CdnFileReuploadNeeded(TArray<uint8> request_token);

	~CdnFileReuploadNeeded();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TArray<uint8>  GetRequestToken() const
	{
		 return this->request_token;
	}

private:
	TArray<uint8> request_token;
};
} //end namespace block
