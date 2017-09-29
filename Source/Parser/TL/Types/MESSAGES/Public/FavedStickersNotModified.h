#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Messages/Public/FavedStickers.h"

//begin namespace block
namespace MESSAGES
{
class FavedStickersNotModified : public TLBaseObject
{
public:
	FavedStickersNotModified();
	~FavedStickersNotModified();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

private:
};
} //end namespace block
