#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Messages/Public/FavedStickers.h"

//begin namespace block
namespace MESSAGES
{
class GetFavedStickers : public TLBaseObject
{
public:
	GetFavedStickers();
	GetFavedStickers(int32 hash);

	~GetFavedStickers();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 hash;
	MESSAGES::FavedStickers* result;
};
} //end namespace block
