#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace MESSAGES
{
class UninstallStickerSet : public TLBaseObject
{
public:
	UninstallStickerSet();
	UninstallStickerSet(TLBaseObject* stickerset);

	~UninstallStickerSet();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TLBaseObject*  Getstickerset() const
	{
		 return this->stickerset;
	}

	bool GetResult() const
	{
		 return this->result;
	}

private:
	TLBaseObject* stickerset;
	bool result;
};
} //end namespace block
