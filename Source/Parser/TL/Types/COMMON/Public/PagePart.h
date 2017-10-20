#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/Photo.h"
#include "../../../Types/Common/Public/Document.h"

//begin namespace block
namespace COMMON
{
class PagePart : public TLBaseObject
{
public:
	PagePart();
	PagePart(TArray<TLBaseObject*> blocks, TArray<COMMON::Photo*> photos, TArray<COMMON::Document*> documents);

	~PagePart();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TArray<TLBaseObject*>  Getblocks() const
	{
		 return this->blocks;
	}

	TArray<COMMON::Photo*>  Getphotos() const
	{
		 return this->photos;
	}

	TArray<COMMON::Document*>  Getdocuments() const
	{
		 return this->documents;
	}

private:
	TArray<TLBaseObject*> blocks;
	 TArray<COMMON::Photo*> photos;
	 TArray<COMMON::Document*> documents;
};
} //end namespace block
