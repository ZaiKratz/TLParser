#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class UpdateStickerSetsOrder : public TLBaseObject
{
public:
	UpdateStickerSetsOrder();
	UpdateStickerSetsOrder(bool masks, TArray<unsigned long long> order);

	~UpdateStickerSetsOrder();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	bool Getmasks() const
	{
		 return this->masks;
	}

	TArray<unsigned long long>  Getorder() const
	{
		 return this->order;
	}

private:
	bool masks;
	 TArray<unsigned long long> order;
};
} //end namespace block
