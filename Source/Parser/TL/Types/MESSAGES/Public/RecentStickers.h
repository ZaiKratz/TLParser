#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/Document.h"

//begin namespace block
namespace MESSAGES
{
class RecentStickers : public TLBaseObject
{
public:
	RecentStickers();
	RecentStickers(int32 hash, TArray<COMMON::Document*> stickers);

	~RecentStickers();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 Gethash() const
	{
		 return this->hash;
	}

	TArray<COMMON::Document*>  Getstickers() const
	{
		 return this->stickers;
	}

private:
	int32 hash;
	 TArray<COMMON::Document*> stickers;
};
} //end namespace block
