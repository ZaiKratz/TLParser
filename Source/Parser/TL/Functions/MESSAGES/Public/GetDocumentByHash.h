#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/Document.h"

//begin namespace block
namespace MESSAGES
{
class GetDocumentByHash : public TLBaseObject
{
public:
	GetDocumentByHash();
	GetDocumentByHash(TArray<uint8> sha256, int32 size, FString mime_type);

	~GetDocumentByHash();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TArray<uint8>  Getsha256() const
	{
		 return this->sha256;
	}

	int32 Getsize() const
	{
		 return this->size;
	}

	FString GetMimeType() const
	{
		 return this->mime_type;
	}

	COMMON::Document* GetResult() const
	{
		 return this->result;
	}

private:
	TArray<uint8> sha256;
	 int32 size;
	 FString mime_type;
	COMMON::Document* result;
};
} //end namespace block
