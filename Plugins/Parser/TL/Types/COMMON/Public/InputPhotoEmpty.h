#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputPhoto.h"

//begin namespace block
namespace COMMON
{
class InputPhotoEmpty : public TLBaseObject
{
public:
	InputPhotoEmpty();
	~InputPhotoEmpty();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
};
} //end namespace block
