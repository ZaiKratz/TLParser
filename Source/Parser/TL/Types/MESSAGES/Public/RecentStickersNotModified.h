#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Messages/Public/RecentStickers.h"

//begin namespace block
namespace MESSAGES
{
class RecentStickersNotModified : public TLBaseObject
{
public:
	RecentStickersNotModified();
	~RecentStickersNotModified();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

private:
};
} //end namespace block
