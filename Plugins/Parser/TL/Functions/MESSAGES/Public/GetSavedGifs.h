#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Messages/Public/SavedGifs.h"

//begin namespace block
namespace MESSAGES
{
class GetSavedGifs : public TLBaseObject
{
public:
	GetSavedGifs();
	GetSavedGifs(int32 hash);

	~GetSavedGifs();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 hash;
	MESSAGES::SavedGifs* result;
};
} //end namespace block
