#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Messages/Public/AllStickers.h"

//begin namespace block
namespace MESSAGES
{
class AllStickersNotModified : public TLBaseObject
{
public:
	AllStickersNotModified();
	~AllStickersNotModified();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

private:
};
} //end namespace block
