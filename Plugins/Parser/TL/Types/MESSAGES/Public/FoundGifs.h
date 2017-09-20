#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/FoundGif.h"

//begin namespace block
namespace MESSAGES
{
class FoundGifs : public TLBaseObject
{
public:
	FoundGifs();
	FoundGifs(int32 next_offset, TArray<COMMON::FoundGif*> results);

	~FoundGifs();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 next_offset;
	 TArray<COMMON::FoundGif*> results;
};
} //end namespace block
