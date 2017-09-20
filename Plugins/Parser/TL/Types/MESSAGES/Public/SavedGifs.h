#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/Document.h"

//begin namespace block
namespace MESSAGES
{
class SavedGifs : public TLBaseObject
{
public:
	SavedGifs();
	SavedGifs(int32 hash, TArray<COMMON::Document*> gifs);

	~SavedGifs();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 hash;
	 TArray<COMMON::Document*> gifs;
};
} //end namespace block
