#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Messages/Public/Stickers.h"

//begin namespace block
namespace MESSAGES
{
class StickersNotModified : public TLBaseObject
{
public:
	StickersNotModified();
	~StickersNotModified();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

private:
};
} //end namespace block
