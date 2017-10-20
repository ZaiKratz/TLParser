#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace MESSAGES
{
class InstallStickerSet : public TLBaseObject
{
public:
	InstallStickerSet();
	InstallStickerSet(TLBaseObject* stickerset, bool archived);

	~InstallStickerSet();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TLBaseObject*  Getstickerset() const
	{
		 return this->stickerset;
	}

	bool Getarchived() const
	{
		 return this->archived;
	}

	TLBaseObject* GetResult() const
	{
		 return this->result;
	}

private:
	TLBaseObject* stickerset;
	 bool archived;
	TLBaseObject* result;
};
} //end namespace block
