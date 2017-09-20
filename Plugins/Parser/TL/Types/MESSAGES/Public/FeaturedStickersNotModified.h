#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Messages/Public/FeaturedStickers.h"

//begin namespace block
namespace MESSAGES
{
class FeaturedStickersNotModified : public TLBaseObject
{
public:
	FeaturedStickersNotModified();
	~FeaturedStickersNotModified();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
};
} //end namespace block
