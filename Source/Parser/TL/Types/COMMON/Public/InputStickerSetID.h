#pragma once
#include "Engine.h"
#include "../../../Types/Private/InputStickerSet.h"

#include "../../../Types/Private/InputStickerSet.h"

//begin namespace block
namespace COMMON
{
class InputStickerSetID : public PRIVATE::InputStickerSet
{
public:
	InputStickerSetID();
	InputStickerSetID(unsigned long long id, unsigned long long access_hash);

	~InputStickerSetID();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	unsigned long long Getid() const
	{
		 return this->id;
	}

	unsigned long long GetAccessHash() const
	{
		 return this->access_hash;
	}

private:
	unsigned long long id;
	 unsigned long long access_hash;
};
} //end namespace block