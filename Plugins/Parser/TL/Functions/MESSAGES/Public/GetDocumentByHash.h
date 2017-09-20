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
private:
	TArray<uint8> sha256;
	 int32 size;
	 FString mime_type;
	COMMON::Document* result;
};
} //end namespace block
