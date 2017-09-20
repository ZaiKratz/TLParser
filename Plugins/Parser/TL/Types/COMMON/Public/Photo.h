#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/PhotoSize.h"

//begin namespace block
namespace COMMON
{
class Photo : public TLBaseObject
{
public:
	Photo();
	Photo(bool has_stickers, unsigned long long id, unsigned long long access_hash, FDateTime date, TArray<COMMON::PhotoSize*> sizes);

	~Photo();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	bool has_stickers;
	 unsigned long long id;
	 unsigned long long access_hash;
	 FDateTime date;
	 TArray<COMMON::PhotoSize*> sizes;
};
} //end namespace block
