#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/DraftMessage.h"

//begin namespace block
namespace COMMON
{
class DraftMessageEmpty : public TLBaseObject
{
public:
	DraftMessageEmpty();
	~DraftMessageEmpty();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

private:
};
} //end namespace block
