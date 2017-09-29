#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/Document.h"

//begin namespace block
namespace MESSAGES
{
class Stickers : public TLBaseObject
{
public:
	Stickers();
	Stickers(FString hash, TArray<COMMON::Document*> stickers);

	~Stickers();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	FString Gethash() const
	{
		 return this->hash;
	}

	TArray<COMMON::Document*>  Getstickers() const
	{
		 return this->stickers;
	}

private:
	FString hash;
	 TArray<COMMON::Document*> stickers;
};
} //end namespace block