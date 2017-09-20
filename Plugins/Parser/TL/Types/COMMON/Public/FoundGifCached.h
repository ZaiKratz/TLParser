#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/Photo.h"
#include "../../../Types/Common/Public/Document.h"
#include "../../../Types/Common/Public/FoundGif.h"

//begin namespace block
namespace COMMON
{
class FoundGifCached : public TLBaseObject
{
public:
	FoundGifCached();
	FoundGifCached(FString url, COMMON::Photo* photo, COMMON::Document* document);

	~FoundGifCached();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	FString url;
	 COMMON::Photo* photo;
	 COMMON::Document* document;
};
} //end namespace block