#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Messages/Public/AllStickers.h"

//begin namespace block
namespace MESSAGES
{
class GetMaskStickers : public TLBaseObject
{
public:
	GetMaskStickers();
	GetMaskStickers(int32 hash);

	~GetMaskStickers();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 Gethash() const
	{
		 return this->hash;
	}

	MESSAGES::AllStickers* GetResult() const
	{
		 return this->result;
	}

private:
	int32 hash;
	MESSAGES::AllStickers* result;
};
} //end namespace block
