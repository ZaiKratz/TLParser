#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class ChannelAdminLogEventActionChangeStickerSet : public TLBaseObject
{
public:
	ChannelAdminLogEventActionChangeStickerSet();
	ChannelAdminLogEventActionChangeStickerSet(TLBaseObject* prev_stickerset, TLBaseObject* new_stickerset);

	~ChannelAdminLogEventActionChangeStickerSet();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TLBaseObject*  GetPrevStickerset() const
	{
		 return this->prev_stickerset;
	}

	TLBaseObject*  GetNewStickerset() const
	{
		 return this->new_stickerset;
	}

private:
	TLBaseObject* prev_stickerset;
	 TLBaseObject* new_stickerset;
};
} //end namespace block
