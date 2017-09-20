#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Messages/Public/AllStickers.h"

//begin namespace block
namespace MESSAGES
{
class GetAllStickers : public TLBaseObject
{
public:
	GetAllStickers();
	GetAllStickers(int32 hash);

	~GetAllStickers();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 hash;
	MESSAGES::AllStickers* result;
};
} //end namespace block
