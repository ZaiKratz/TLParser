#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class InputStickerSetShortName : public TLBaseObject
{
public:
	InputStickerSetShortName();
	InputStickerSetShortName(FString short_name);

	~InputStickerSetShortName();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	FString GetShortName() const
	{
		 return this->short_name;
	}

private:
	FString short_name;
};
} //end namespace block
