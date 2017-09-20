#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputPhoto.h"

//begin namespace block
namespace PHOTOS
{
class DeletePhotos : public TLBaseObject
{
public:
	DeletePhotos();
	DeletePhotos(TArray<COMMON::InputPhoto*> id);

	~DeletePhotos();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	TArray<COMMON::InputPhoto*> id;
	TArray<unsigned long long> result;
};
} //end namespace block
